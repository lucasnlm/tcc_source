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

#include "request_handler.hpp"
#include "mime_types.hpp"
#include "reply.hpp"
#include "request.hpp"
#include "connection.hpp"
#include "analog.hpp"
#include "util.hpp"
#include "rest.hpp"
#include "controller_io.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace controller { namespace http { 

RequestHandler::RequestHandler(const std::string& doc_root) 
    : doc_root_(doc_root)
{}

void RequestHandler::handleRequest(const Connection* conn, const Request& req, Reply& rep)
{
    // Verifica se a conexão foi autenticada.
    if(!conn->isAuthenticated())
    {
        rep = Reply::stockReply(Reply::unauthorized);

        rep.headers.resize(4);
        rep.headers[0].name = "Content-Length";
        rep.headers[0].value = std::to_string(rep.content.size());
        rep.headers[1].name = "Content-Type";
        rep.headers[1].value = "text/html";
        rep.headers[2].name = "WWW-Authenticate";
        rep.headers[2].value = "Basic";
        rep.headers[3].name = "Connection";
        rep.headers[3].value = "close";
        return;
    }

    // Decode url to path.
    std::string request_path;
    
    if (!urlDecode(req.getURI(), request_path))
    {
        rep = Reply::stockReply(Reply::bad_request);
        return;
    }

    // Request path must be absolute and not contain "..".
    if (request_path.empty() || request_path[0] != '/' || request_path.find("..") != std::string::npos)
    {
        rep = Reply::stockReply(Reply::bad_request);
        return;
    }

    // If path ends in slash (i.e. is a directory) then add "index.html".
    if (request_path[request_path.size() - 1] == '/')
    {
        request_path += "index.html";
    }

    // Determine the file extension.
    std::size_t last_slash_pos = request_path.find_last_of("/");
    std::size_t last_dot_pos = request_path.find_last_of(".");
    std::string extension;
    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos)
    {
        extension = request_path.substr(last_dot_pos + 1);
    }

    // Verifica se é um comando REST.
    if(this->call(req, rep))
    {
        return;
    }

    // Open the file to send back.
    std::string full_path = doc_root_ + request_path;
    std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
    if (!is)
    {
        rep = Reply::stockReply(Reply::not_found);
        return;
    }

    // Fill out the reply to be sent to the client.
    rep.status = Reply::ok;
    rep.content = "";
    
    static char buf[8192];
    std::memset(buf, '\0', 8192);
    
    while (is.read(buf, sizeof(buf)).gcount() > 0)
    {
        rep.content.append(buf, is.gcount());
    }
  
    rep.headers.resize(3);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = std::to_string(rep.content.size());
    rep.headers[1].name = "Content-Type";
    rep.headers[1].value = extensionToType(extension);
    rep.headers[2].name = "Connection";
    rep.headers[2].value = "keep-alive";
}

std::string makeAnalog(const char* id, int value)
{
    std::stringstream ss;
    ss << "\"" << id << "\" : { \"value\" : " << value << " }";
    return ss.str();
}

bool RequestHandler::call(const Request& req, Reply& rep)
{
    const std::string& ftn = req.getURI();

    if(ftn == "/read.plc")
    {
        std::stringstream ss;
        ss << "{ \"gpio\" : [ ";
        ss << " ], ";
        
        ss << " \"analog\" : { "
           << makeAnalog("AIN0", IO::getAnalog(0).getValue()) << ", "
           << makeAnalog("AIN1", IO::getAnalog(1).getValue()) << ", "
           << makeAnalog("AIN2", IO::getAnalog(2).getValue()) << ", "
           << makeAnalog("AIN3", IO::getAnalog(3).getValue()) << ", "
           << makeAnalog("AIN4", IO::getAnalog(4).getValue()) << ", "
           << makeAnalog("AIN5", IO::getAnalog(5).getValue()) 
           << " } } ";

        rep.status = Reply::ok;
        rep.content = ss.str();

        rep.headers.resize(3);
        rep.headers[0].name = "Content-Length";
        rep.headers[0].value = std::to_string(rep.content.size());
        rep.headers[1].name = "Content-Type";
        rep.headers[1].value = "text/plain";
        rep.headers[2].name = "Connection";
        rep.headers[2].value = "keep-alive";
        return true;
    }
    else if(ftn == "/write.plc")
    {
        controller::util::writeFileContent("configurations.plc", req.getContent());
    }
    
    return false;
}

bool RequestHandler::urlDecode(const std::string& in, std::string& out)
{
    out.clear();
    out.reserve(in.size());
    
    for (std::size_t i = 0; i < in.size(); ++i)
    {
        if (in[i] == '%')
        {
            if (i + 3 <= in.size())
            {
                int value = 0;
                std::istringstream is(in.substr(i + 1, 2));
                if (is >> std::hex >> value)
                {
                    out += static_cast<char>(value);
                    i += 2;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (in[i] == '+')
        {
            out += ' ';
        }
        else
        {
            out += in[i];
        }
    }
    
    return true;
}

} } 
