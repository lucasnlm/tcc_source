#ifndef MANAGER_HPP_INCLUDED
#define MANAGER_HPP_INCLUDED

#include "watch_dog.hpp"
#include "pin.hpp"

#include <string>
#include <map>

namespace controller
{
    class Manager
    {
        public:
            /**
             * Default constructor.
             * Set up controller manager.
             **/
            Manager();

            /**
             * Destructor.
             * Free all pins.
             **/
            ~Manager();

            /**
             * Set up a pin for a defined configuration.
             *
             * @param id the pin's ID.
             * @param config the pin configuration.
             * @param alias the pin's alias.
             **/
            void setUp(int id, const std::string& config, const std::string alias);

            /**
             * Run pins scan.
             **/
            void scan();

            /**
             * Set controller script.
             **/
            void setScript(const std::string& lua_script);
            
            /**
             * Lê um arquivo de script Lua.
             * @param lua_script O arquivo de script.
             **/
            void setScriptFile(const std::string& lua_script);

            void run();
            
            void reconfigure();
            
            void kickDog();
            
            /**
             * Faz uma requisição para que o gerenciador recarregue o programa
             * principal.
             **/
            static void requestReload();

        private:
            /**
             * Set up Lua Engine.
             **/
            void configureLuaEngine();
            
            /**
             * Carrega os arquivos de configurações.
             **/
            void loadConfigurations();

            /**
             * Run main script.
             **/
            void runUserScript();

            void reset();

        private:
            std::map<int, Pin*> active_pins;

            std::string mainScript;

            LuaContext lua;

            WatchDog doge;
    };
}

#endif
