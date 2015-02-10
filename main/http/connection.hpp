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

#ifndef HTTP_CONNECTION_HPP
#define HTTP_CONNECTION_HPP

#include <array>
#include <memory>
#include <ctime>
#include <boost/asio.hpp>

#include "reply.hpp"
#include "request.hpp"
#include "request_handler.hpp"
#include "request_parser.hpp"

namespace controller { namespace http {

class ConnectionManager;

class Connection : public std::enable_shared_from_this<Connection>
{
    public:
        static const std::time_t LIFE_TIME = 4;
    
        /**
         * Proíbe contrutores de cópia.
         **/
        Connection(const Connection&) = delete;
        Connection& operator=(const Connection&) = delete;

        explicit Connection(boost::asio::ip::tcp::socket sckt,
                            ConnectionManager& mng, RequestHandler& hdlr);

        /// Start the first asynchronous operation for the connection.
        void start();

        /// Stop all asynchronous operations associated with the connection.
        void stop();
        
        /**
         * Autentica a conexão.
         **/
        void authenticate()
        {
            authenticated = true;
        }
        
        /**
         * @return Retorna true se a conexão foi autenticada.
         **/
        bool isAuthenticated() const
        {
            return authenticated;
        }
        
        /**
         * @return Retorna o IP dessa conexão.
         **/
        std::string getIP() const;
        
        void setKeepAlive(bool ka);
        
        bool keepAlive() const
        {
            return this->keep_alive;
        }

        int getIdentification() const
        {
            return this->connId;
        }
        
        /**
         * @return Retorna o tempo restante para a conexão.
         **/
        std::time_t isTimeOver() const;

    private:
        /// Perform an asynchronous read operation.
        void doRead();

        /// Perform an asynchronous write operation.
        void doWrite();
        
        /**
         * Adiciona tempo de vida à conexão.
         **/
        void addLifeTime();

        /// Socket for the connection.
        boost::asio::ip::tcp::socket socket;

        /// The manager for this connection.
        ConnectionManager& connection_manager;

        /// The handler used to process the incoming request.
        RequestHandler& request_handler;

        /// Buffer for incoming data.
        std::array<char, 4096> buffer;

        /// The incoming request.
        Request request;

        /// The parser for the incoming request.
        RequestParser request_parser;

        /// The reply to be sent back to the client.
        Reply reply;
        
    private:
        bool authenticated = false;
        
        bool keep_alive = false;
        
        int connId;
        
        std::time_t last_use;
};

typedef std::shared_ptr<Connection> connection_ptr;

} } 

#endif // HTTP_CONNECTION_HPP
