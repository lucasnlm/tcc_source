#include "controller.hpp"

#include "http/server.hpp"
#include "logger.hpp"
#include "settings.hpp"
#include "manager.hpp"
#include "modbus/handler.hpp"

#include <memory>

namespace controller
{
    namespace Controller
    {   
        using http::Server;
    
        Server* http_server = nullptr;
        
        Manager* manager = nullptr;
        
        void http_thread()
        {
            try
            {
                logger.write("Iniciando servidor HTTP.");
                
                Server sv("0.0.0.0", "80", ".");
                http_server = &sv;
                
                sv.run();
                http_server = nullptr;
            }
            catch(std::exception e)
            {
                logger.write("Erro ao executar servidor HTTP: {}.", e.what());
            }
            catch(...)
            {
                logger.write("Erro ao executar servidor HTTP.");
            }
        }
        
        void free_thread()
        {
            do
            {
                if(http_server != nullptr)
                {
                    http_server->freeConnections();
                }
                
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
            while(true);
        }
        
        void manager_thread()
        {
            Manager mn;
            manager = &mn;
            
            mn.run();
            manager = nullptr;
            
            mn.kickDog();
            logger.write("Erro ao executar programa principal.");
        }
        
        void modbus_thread()
        {
            using namespace modbus;

            try
            {
                logger.write("Iniciando servidor modbus.");

                Modbus sv;
                sv.run();
            }
            catch (std::exception& e)
            {
                logger.write("Erro ao executar servidor Modbus: {}.", e.what());
                
            }
            catch(...)
            {
                logger.write("Erro ao executar servidor Modbus.");
            }
        }
        
        void kick()
        {
            if(manager != nullptr) manager->kickDog();
        }
        
        void start()
        {
            system("cpufreq-set -f 1000MHz");
            
            std::thread t1(http_thread);
            std::thread t2(manager_thread);
            std::thread t3(modbus_thread);
            std::thread t4(free_thread);
            
            t1.join(); kick();
            t2.join(); kick();
            t3.join(); kick();
            t4.join(); kick();
        }
    }
}