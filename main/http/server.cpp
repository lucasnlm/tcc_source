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

#include "server.hpp"
#include "logger.hpp"

#include <signal.h>
#include <utility>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <cstdio>
#include <iostream>

namespace controller 
{
    namespace http 
    { 
        Server::Server(const std::string& address, 
                       const std::string& port,
                       const std::string& doc_root) 
        : io_service_(), signals_(io_service_),
          acceptor_(io_service_), connection_manager_(),
          socket_(io_service_), request_handler_(doc_root)
        {
            // Registra os sinais que podem interromper o servidor.
            signals_.add(SIGINT);
            signals_.add(SIGTERM);
            
            #if defined(SIGQUIT)
                signals_.add(SIGQUIT);
            #endif
            
            doAwaitStop();

            boost::asio::ip::tcp::resolver resolver(io_service_);
            boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve({address, port});
            
            acceptor_.open(endpoint.protocol());
            acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
            acceptor_.bind(endpoint);
            acceptor_.listen(4);

            logger.write("Servidor HTTP criado.");

            doAccept();
        }
        
        void Server::freeConnections()
        {
            connection_manager_.checkLife();
        }

void Server::run()
{
    // The io_service::run() call will block until all asynchronous operations
    // have finished. While the server is running, there is always at least one
    // asynchronous operation outstanding: the asynchronous accept call waiting
    // for new incoming connections.
    io_service_.run();
    
    /*while (io_service_.run_one())
    {
        connection_manager_.checkLife();
        io_service_.reset();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }*/
}

void Server::doAccept()
{
    acceptor_.async_accept(socket_,
    [this](boost::system::error_code ec)
    {
        // Check whether the server was stopped by a signal before this
        // completion handler had a chance to run.
        if (!acceptor_.is_open())
        {
            return;
        }

        if (!ec)
        {
            auto conn = std::make_shared<Connection>(std::move(socket_), connection_manager_, request_handler_);

            if(conn != nullptr)
            {
                connection_manager_.start(conn);
                logger.write("O painel foi acessado via HTTP por {}.", conn->getIP());
            }
        }

        doAccept();
    });
}

void Server::doAwaitStop()
{
    signals_.async_wait(
    [this](boost::system::error_code /*ec*/, int /*signo*/)
    {
        // The server is stopped by cancelling all outstanding asynchronous
        // operations. Once all operations have finished the io_service::run()
        // call will exit.
        acceptor_.close();
        connection_manager_.stopAll();
    });
}

} } 
