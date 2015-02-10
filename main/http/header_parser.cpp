/**
 * Copyright 2014 Lucas Nunes de Lima
 * 
 * Based on http_server from Christopher M. Kohlhoff (chris at kohlhoff dot com).
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

#include "header_parser.hpp"
#include "connection.hpp"

#include <iostream>

namespace controller 
{
    namespace http 
    {   
        void processHeaders(Connection* conn, const std::string& msg)
        {
            std::string line, header;
            std::istringstream ss(msg);
            
            std::string rqts;
            std::getline(ss, rqts);

            while (std::getline(ss, line)) 
            {
                std::size_t found = line.find_first_of(":");
                
                if(found != std::string::npos)
                {
                    header = line.substr(0, found);
                }
                else 
                {
                    return;
                }
            }
        }
    } 
}
