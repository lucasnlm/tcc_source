/**
 * Copyright 2014 Lucas Nunes de Lima
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "settings.hpp"
#include "util.hpp"
#include "logger.hpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace controller
{
    Settings& getSettings()
    {
        static Settings settings;
        return settings;
    }

    Settings::Settings()
    {}
    
    void Settings::loadFromFile(const std::string& file_name)
    {
        std::string sts = util::getFileContent(file_name);
        loadJson(sts);
    }
    
    void Settings::load() 
    {
        getSettings().loadFromFile("settings.json");
    }

    void Settings::save(const char* path)
    {
        using namespace rapidjson;
        
        Document d;
        
        d["http"] = this->getHttpPort();
        d["modbus"] = this->getModbusPort();
        d["watch_dog"] = this->getWatchDog();
        
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);
        
        bool sucess = util::writeFileContent("settings.json", buffer.GetString());
        
        if(!sucess)
        {
            logger.write("Falha ao gravar configurações.");
        }
    }
    
    bool Settings::loadJson(const std::string& json)
    {
        using namespace rapidjson;

        if(json.empty())
        {
            return false;
        }
        
        Document d;
        if(!d.IsNull())
        {
            return false;
        }
        
        d.Parse(json.c_str());
        
        if(!d.HasParseError() && d.IsObject())
        {
            if(d.HasMember("http") && d["http"].IsInt())
            {
                this->http_port = d["http"].GetInt();
            }
            else
            {
                logger.write("Faltando campo \"http\" ou inválido.");
                return false;
            }
            
            auto checkAndTake = [&d](const char* field, int& target) -> void
            {
                bool is_valid = d.HasMember(field) && d[field].IsInt();
                
                if(is_valid)
                {
                    target = d[field].GetInt();
                }
                else
                {
                    logger.write("Faltando campo \"{}\" ou inválido.", field);
                }
            };
            
            checkAndTake("http", this->http_port);
            checkAndTake("modbus", this->modbus_port);
            checkAndTake("watch_dog", this->watch_dog);
            
            logger.write("Configurações carregadas com sucesso.");
            return true;
        }
        else
        {
            logger.write("Erro ao carregar configurações anteriores. Retornando a padrão.");
            return false;
        }
    }
    
    void Settings::loadDefault()
    {
        logger.write("Configurações padrões carregadas.");
        
        this->http_port = 80;
        this->modbus_port = 502;
        this->watch_dog = 1;
    }
}
