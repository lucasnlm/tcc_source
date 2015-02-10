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

#ifndef HTTP_REQUEST_HPP_INCLUDED
#define HTTP_REQUEST_HPP_INCLUDED

#include <string>
#include <vector>

#include "header.hpp"

namespace controller 
{ 
    namespace http 
    {
        class Connection;
        
        class Request
        {
            public:
                Request();
                
                bool consume(Connection* conn, const std::string& http_hdr);
                
                void setMethod(const std::string& method)
                {
                    this->method = method;
                }
            
                const std::string& getMethod() const
                {
                    return this->method;
                }
                
                const std::string& getURI() const
                {
                    return this->uri;
                }
                
                void setURI(const std::string& uri)
                {
                    this->uri = uri;
                }
                
                void setHttpVersion(int major, int minor)
                {
                    this->http_version_major = major;
                    this->http_version_minor = minor;
                }
                
                int getMajorVersion() const
                {
                    return this->http_version_major;
                }
                
                int getMinorVersion() const
                {
                    return this->http_version_minor;
                }
            
                void addHeader(const std::string& key, const std::string& value)
                {
                    headers.push_back({key, value});
                }
                
                const std::string& getValue(const std::string& key) const;
                
                bool isHealthy() const
                {
                    return this->healthy;
                }
                
                const std::string& getContent() const
                {
                    return content;
                }
                            
            private:
                size_t captureMethod(const std::string& line);
                
                size_t captureURI(const std::string& line, size_t starter);
                
                bool captureHTTP(const std::string& line, size_t starter);
                
            private:
                std::string method;
                
                std::string uri;
                
                int http_version_major;
                
                int http_version_minor;
                
                std::vector<Header> headers;
                
                bool healthy = false;
                
                std::string content;
        };
    }
}

#endif // HTTP_REQUEST_HPP