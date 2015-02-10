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

#include "authentication.hpp"
#include "connection.hpp"
#include "base64.hpp"
#include "util.hpp"

namespace controller
{
    namespace http
    {
        const std::string& getAuthentication(void)
        {
            using namespace controller::util;
            
            static std::string g_pass = []() -> std::string
            {
                std::string pass = getFileContent("http_key.b64");
                
                if(pass.empty())
                {
                    writeFileContent("http_key.b64", "cm9vdDo=");
                    
                    // Se o arquivo da senha não for encontrado,
                    // usa root sem senha.
                    return "cm9vdDo=";
                }
                else
                {
                    return pass;
                }
            }();
            
            return g_pass;
        }

        void checkAuthentication(Connection* conn, const std::string& msg)
        {
            std::string line;
            std::istringstream ss(msg);
            
            std::string base = "Authorization: Basic ";
            
            while (std::getline(ss, line)) 
            {
                if(line.find(base) != std::string::npos)
                {
                    std::string user_pass = line.substr(base.size(), std::string::npos);                

                    if(user_pass.size() != 0)
                    {                                   
                        if(user_pass.find(getAuthentication()) != std::string::npos)
                        {
                            conn->authenticate();
                        }
                        
                        return;
                    }
                }
            }
        }
    }
}
