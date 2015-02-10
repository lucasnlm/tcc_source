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

#include "connection.hpp"
#include "connection_manager.hpp"
#include "request_handler.hpp"
#include "authentication.hpp"
#include "header_parser.hpp"

#include "util.hpp"

#include <utility>
#include <vector>

#include <iostream>

namespace controller { namespace http { 

int connIdGen = 0;
    
Connection::Connection(boost::asio::ip::tcp::socket sckt,
                       ConnectionManager& mng, RequestHandler& hdlr)
    : socket(std::move(sckt)), connection_manager(mng), request_handler(hdlr)
{    
    this->authenticated = false;
    
    this->connId = ++connIdGen;
}

void Connection::setKeepAlive(bool ka)
{
    if(ka)
    {
        this->addLifeTime();
    }
        
    this->keep_alive = ka;
}

void Connection::start()
{
    doRead();
}

void Connection::stop()
{
    socket.close();
}

void Connection::addLifeTime()
{
    this->last_use = std::time(nullptr);
}

std::time_t Connection::isTimeOver() const
{
    return keepAlive() && (std::time(nullptr) - this->last_use) > LIFE_TIME;
}

void Connection::doRead()
{
    auto self(shared_from_this());

    buffer.fill('\0');

    socket.async_read_some(boost::asio::buffer(buffer),
    [this, self](boost::system::error_code ec, std::size_t bytes_transferred)
    {
        if (!ec)
        {
            auto buffer_data = buffer.data();
            bool result = request.consume(this, buffer_data);

            if (result)
            {
               // if(!isAuthenticated())
                //{
                  //  checkAuthentication(this, buffer_data);
                //}
                
                //processHeaders(this, buffer_data);
                
                if(request.getMethod() == "GET")
                {
                    request_handler.handleRequest(this, request, reply);
                    doWrite();
                }
                else if(request.getMethod() == "POST")
                {
                    request_handler.handleRequest(this, request, reply);
                    
                    Reply rep;
                    rep.status = Reply::created;
                    reply = rep;
                    
                    doWrite();
                }
            }
            else
            {
                doRead();
            }
        }
        else //if (ec == boost::asio::error::operation_aborted)
        {
            connection_manager.stop(shared_from_this());
        }
    });
}

std::string Connection::getIP() const
{
    return socket.remote_endpoint().address().to_string();
}

void Connection::doWrite()
{
    auto self(shared_from_this());
        
    boost::asio::async_write(socket, reply.toBuffers(),
    [this, self](boost::system::error_code ec, std::size_t)
    {
        if (!ec)
        {
            if(this->keepAlive())
            {
                doRead();
            }
            else
            {
                // Encerra a conexão.
                boost::system::error_code ignored_ec;
                socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
                connection_manager.stop(shared_from_this());
            }
        }
        else
        {
            connection_manager.stop(shared_from_this());
        }
    });
}
    
} } 
