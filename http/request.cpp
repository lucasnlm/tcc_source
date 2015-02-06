#include "request.hpp"
#include "connection.hpp"
#include "authentication.hpp"

#include <sstream>
#include <cstdlib>

#include <iostream>
#include <algorithm>

namespace controller
{
    namespace http
    {
        Request::Request() : healthy(false)
        {
            this->headers.reserve(24u);
        }
        
        size_t Request::captureMethod(const std::string& line)
        {
            if(line.empty())
            {
                return std::string::npos;
            }
            
            std::size_t pos = line.find_first_of(' ');
            std::string mthd = line.substr(0u, pos);
            
            if (mthd == "GET" || mthd == "POST" || mthd == "PUT")
            {
                this->method = mthd;
                return pos;
            }
            else
            {
                return std::string::npos;
            }
        }
        
        size_t Request::captureURI(const std::string& line, size_t starter)
        {
            if(line.empty())
            {
                return std::string::npos;
            }
            
            std::size_t pos = line.find_first_of(' ', starter);
            std::string uri = line.substr(starter, pos - starter);
            
            this->setURI(uri);

            return pos;
        }

        bool Request::captureHTTP(const std::string& line, size_t starter)
        {
            if(line.empty())
            {
                return false;
            }
            
            std::size_t pos = line.find_first_of('/', starter);
            std::string str = line.substr(starter, pos - starter);

            if(str != "HTTP")
            {
                return false;
            }

            starter = pos+1;
            pos = line.find_first_of('.', starter);

            try
            {
                int major = std::stoi(line.substr(starter, pos - starter));
                int minor = std::stoi(line.substr(pos + 1));
                
                this->setHttpVersion(major, minor);
                return true;
            }
            catch(...)
            {
                return false;
            }
        }
        
        const std::string& Request::getValue(const std::string& key) const
        {
            for(const Header& hr : headers)
            {
                if(hr.name.find(key) != std::string::npos)
                {
                    return hr.value;
                }
            }
            
            static const std::string void_str;
            return void_str;
        }
        
        bool Request::consume(Connection* conn, const std::string& http_hdr)
        {
            this->healthy = false;
            this->headers.clear();
            this->content = "";
            
            std::string line;
            std::istringstream ss(http_hdr);
                        
            std::getline(ss, line);
            
            if(line.empty())
                return false;

            std::size_t found = captureMethod(line);
            if(found == std::string::npos)
                return false;
            
            found = captureURI(line, found + 1);
            if(found == std::string::npos)
                return false;
            
            if(!captureHTTP(line, found + 1))
                return false;
            
            bool wainting_headers = true;
            
            std::string header, value;
            while (std::getline(ss, line)) 
            {
                if(wainting_headers)
                {
                    found = line.find_first_of(":");
                    
                    if(found != std::string::npos)
                    {
                        std::string header = line.substr(0, found);
                        std::string value = line.substr(found + 2);
                        
                        if(header == "Connection")
                        {
                            if(value == "keep-alive\r")
                            {
                                conn->setKeepAlive(true);
                            }
                            else if(value == "close\r")
                            {
                                conn->setKeepAlive(false);
                            }
                        }
                        else if(!conn->isAuthenticated() && header == "Authorization")
                        {
                            std::string user_pass = value.substr(strlen("Basic "), std::string::npos);                

                            if(user_pass.size() != 0)
                            {                                   
                                if(user_pass.find(getAuthentication()) != std::string::npos)
                                {
                                    conn->authenticate();
                                }
                            }
                        }
                        
                        this->addHeader(header, value);
                    }
                    else 
                    {
                        wainting_headers = false;
                        continue;
                    }
                }
                else
                {
                    this->content.append(line);
                }
            }

            return (this->healthy = true);
        }
    }
}
