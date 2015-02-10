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

#ifndef HTTP_SERVER_HPP_INCLUDED
#define HTTP_SERVER_HPP_INCLUDED

#include <string>
#include <boost/asio.hpp>

#include "connection.hpp"
#include "connection_manager.hpp"
#include "request_handler.hpp"

namespace controller
{
    namespace http
    { 
        /**
         * Descreve um servidor HTTP.
         **/
        class Server
        {
            public:
                // Cancela o construtor de cópia e atribuição.
                Server(const Server&) = delete;
                Server& operator=(const Server&) = delete;

                /**
                 * Cria o servidor, ativando o listener para 
                 * um endereço e porta TCP específicos.
                 ***/
                explicit Server(const std::string& address,
                                const std::string& port,
                                const std::string& doc_root);

                /**
                 * Executa o loop do servidor.
                 **/
                void run();
        
                /**
                 * Liberta as conexões não utilizadas.
                 * @see keep-alive
                 **/
                void freeConnections();
                
            private:
                /**
                 * Executam uma operação de aceitação assíncrona.
                 **/
                void doAccept();

                /**
                 * Aguarda uma requisição do servidor parar.
                 **/
                void doAwaitStop();

            private:
                // O io_service usado para as operações assíncronas.
                boost::asio::io_service io_service_;

                /// The signal_set is used to register for process termination notifications.
                boost::asio::signal_set signals_;

                /// Acceptor used to listen for incoming connections.
                boost::asio::ip::tcp::acceptor acceptor_;

                /// The connection manager which owns all live connections.
                ConnectionManager connection_manager_;

                /// The next socket to be accepted.
                boost::asio::ip::tcp::socket socket_;

                /// The handler for all incoming requests.
                RequestHandler request_handler_;
                
                // O número de máximo de conexões permitidas.
                int max_connections = 25;
        };
    }
} 

#endif // HTTP_SERVER_HPP
