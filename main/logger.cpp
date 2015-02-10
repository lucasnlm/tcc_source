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

#include "logger.hpp"

namespace controller
{
    Logger logger;

    Logger::Logger()
    {
        spdlog::set_level(spdlog::level::TRACE);

        std::string filename = "logs/log";

        spdlog::set_pattern("%Y-%m-%d %H:%M:%S > %v");

        size_t flush_interval = 5;               // # lines
        size_t max_files_num = 30;               // # files
        size_t max_files_size = 1024 * 1024 * 5; // # bytes

        try
        {
            this->logger = spdlog::rotating_logger_st("file_logger", 
                                                      filename,
                                                      max_files_size,
                                                      max_files_num,
                                                      flush_interval);
        }
        catch (const spdlog::spdlog_ex& ex)
        {
            std::cout << "Can't create logger: " << ex.what() << std::endl;
            this->logger = nullptr;
        }
    }

    Logger::~Logger()
    {
        this->write(u8"Encerrando sistema... RIP");
    }
}
