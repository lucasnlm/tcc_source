#include "http_handler.hpp"

#include <iostream>
#include <fstream>

#include "http/server.hpp"
#include "logger.hpp"
#include "settings.hpp"

namespace controller
{
    namespace http
    {
        void run()
        {
            using namespace http;

            try
            {
                logger.write("Iniciando servidor HTTP.");
                Server("0.0.0.0", "80", ".").run();
            }
            catch(...)
            {
                logger.write("Erro ao estabelecer servidor HTTP na porta %d.", getSettings().getHttpPort());
            }
        }
    }
}
