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
