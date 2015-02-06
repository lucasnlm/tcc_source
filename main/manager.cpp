#include "manager.hpp"

#include "controller_io.hpp"
#include "analog.hpp"
#include "watch_dog.hpp"
#include "logger.hpp"
#include "presets.hpp"
#include "settings.hpp"
#include "util.hpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"

#include <timer.hpp>
#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>

namespace controller
{
    bool reload_request = true;
    
    Manager::Manager()
    {
        logger.write(u8"Iniciando programa do usuário...");
        doge.wakeUp();
    }

    Manager::~Manager()
    {
        logger.write(u8"O sistema será desligado em breve...");

        for (std::map<int, Pin*>::iterator it = active_pins.begin(); it != active_pins.end(); ++it)
        {
            Pin* pin = it->second;
            delete pin;
        }

        this->active_pins.clear();
    }
    
    void Manager::requestReload()
    {
        reload_request = true;
    }
    
    void Manager::loadConfigurations()
    {
        using namespace rapidjson;
        
        if(!reload_request)
        {
            return;
        }
        
        reload_request = false;
        
        std::string json = util::getFileContent("configurations.plc");
        
        if(json.empty())
        {
            return;
        }
        
        Document d;
        
        d.Clear();
        d.Parse(json.c_str());
        
        if(d.IsNull())
        {
            return;
        }
           
        if(d.HasParseError())
        {
            logger.write("Erro ao interpretar configurações ({}).", GetParseError_En(d.GetParseError()));
            return;
        }
        
        auto catcheField = [&](const char* member) -> void
        {
            if(d.HasMember(member) && d[member].IsArray())
            {
                const Value& gpio_arr = d[member];
                
                for (SizeType i = 0u; i < gpio_arr.Size(); i++)
                {
                    const Value& c = gpio_arr[i];
                    
                    if(!c["id"].IsInt() || !c["config"].IsString())
                        continue;

                    int id = c["id"].GetInt();
                    const Preset& ps = findPreset(c["config"].GetString());
                    
                    // verifica se é analógico.
                    bool analog = (std::strcmp("analogs", member) == 0);
                    
                    Pin& pin = IO::getPin(id, analog);
                    pin.setDirection(ps.direction);
                    pin.setName(c["name"].GetString());
                    
                    if(c.HasMember("source") && c["source"].IsString())
                    {
                        pin.setSource(c["source"].GetString());
                    }
                    
                    pin.setContext(&lua, id + 1);
                }
            }
        };
     
        if(d.IsObject())
        {
            catcheField("gpios");
            catcheField("analogs");
                       
            logger.write("Configurações carregadas com sucesso.");
        }
        else
        {
            logger.write("Erro ao carregar configurações do controlador.");
        }
    }
    
    void Manager::kickDog()
    {
        doge.kick();
    }

    void Manager::setUp(int id, const std::string& config, const std::string alias)
    {
        //active_pins[id] = new General(id);

        logger.write("o pino", id, "foi definido como '", config, "' e agora é chamado de '", alias, "'");
    }

    void Manager::setScript(const std::string& lua_script)
    {
        mainScript = lua_script;
    }
    
    void Manager::setScriptFile(const std::string& lua_script)
    {
        mainScript = util::getFileContent(lua_script);
    }
    
    void Manager::reconfigure()
    {
        reset();
    }
    
    struct LuaObject
    {};
    
    void Manager::reset()
    {
        logger.write("O contexto do programa principal foi resetado.");
        
        lua = LuaContext();
    }

    void Manager::run()
    {
        logger.write(u8"Configurando máquina Lua.");
        
        loadConfigurations();
        runUserScript();
        
        Timer timer;
        const std::time_t scan_time = getSettings().getScanTime();
        
        double it = 1.0;
        double total = 0.0;
        
        
        while(true)
        {
            timer.resetTimer();
            
            // Atualiza as leituras analógias.
            Analog::refresh();
            
            // Atualiza as portas digitais.
            // Em seguida, executa o algoritmo do usuário referente a porta.
            IO::refresh();

            // Alimenta o Watch Dog.
            doge.feed();
            
            // Calcula o tempo.
            std::time_t diff = timer.getDiff();
            total += static_cast<double>(diff);
            it += 1.0;           
            std::cout << "Demorou " << std::setw(4) << (total/it) << " ms" << std::endl;
            
            // Libera o CPU para descanço.
            if(diff < scan_time) 
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(scan_time - diff));
            }
        }
    }

    void Manager::runUserScript()
    {
        if(mainScript.empty())
        {
            return;
        }

        try
        {
            lua.executeCode(mainScript);
        }
        catch(LuaContext::ExecutionErrorException e)
        {
            logger.write("Erro de execução Lua:", e.what());
        }
        catch(LuaContext::SyntaxErrorException e)
        {
            logger.write("Erro de sintaxa Lua encontrado:", e.what());
        }
        catch(LuaContext::WrongTypeException e)
        {
            logger.write("Tipo inválido Lua:", e.what());
        }
        catch(...)
        {
            logger.write("Erro desconhecido ao executar script Lua.");
        }
    }

    void Manager::scan()
    {
        for (std::map<int, Pin*>::iterator it = active_pins.begin(); it != active_pins.end(); ++it)
        {
            //Pin* pin = it->second;
            //pin->u
        }
        
        doge.feed();
    }
}
