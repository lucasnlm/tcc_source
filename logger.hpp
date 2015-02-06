#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include "spdlog/spdlog.h"
#include "cppformat/format.h"

namespace controller
{
    class Logger
    {
        public:
            /**
             * Constructor.
             * Create logger system.
             **/
            Logger();

            /**
             * Destructor.
             * Shutdown logger system.
             **/
            ~Logger();

            /**
             * Escreve uma informação no logger.
             **/
            template <typename... Args>
            void write(const Args&... args)
            {
                try
                {
                    logger->info(args...);
                }
                catch(std::exception e)
                {
                    std::cout << "log fail: " << e.what() << std::endl;
                }
                catch(...)
                {
                    std::cout << "log: unknow error" << std::endl;
                }
            }

            /**
             * Escreve uma informação no logger.
             **/
            template <typename... Args>
            void write(const char* str, const Args&... args)
            {
                try
                {
                    std::cout << fmt::format(str, args...) << std::endl;
                    logger->info(fmt::format(str, args...));
                }
                catch(std::exception e)
                {
                    std::cout << "log fail: " << e.what() << std::endl;
                }
                catch(...)
                {
                    std::cout << "log: unknow error" << std::endl;
                }
            }

        private:
            std::shared_ptr<spdlog::logger> logger;
    };

    extern Logger logger;
}

#endif // LOGGER_HPP_INCLUDED
