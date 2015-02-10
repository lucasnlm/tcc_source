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

#ifndef HTTP_CONNECTION_MANAGER_HPP
#define HTTP_CONNECTION_MANAGER_HPP

#include <set>
#include <mutex>

#include "connection.hpp"

namespace controller 
{
    namespace http 
    { 
        /**
         * Descreve o gerenciador de conexões.
         **/
        class ConnectionManager
        {
            public:
                // Cancela construtores de cópia e atribuição.
                ConnectionManager(const ConnectionManager&) = delete;
                ConnectionManager& operator=(const ConnectionManager&) = delete;

                /**
                 * Construtor.
                 **/
                ConnectionManager();

                /**
                 * Adiciona uma nova conexão a lista.
                 **/
                void start(connection_ptr c);

                /**
                 * Para uma conexão.
                 **/
                void stop(connection_ptr c);

                /**
                 * Para todas as conexões.
                 **/
                void stopAll();
                
                /**
                 * A quantida de conexões cadastradas.
                 **/
                size_t count() const
                {
                    return connections.size();
                }
                
                void checkLife();

            private:
                // A lista de conexões.
                std::set<connection_ptr> connections;
                
                // Mutex utilizada nas funções de manipulação do std::set.
                std::mutex mtx;
        };
} }


#endif // HTTP_CONNECTION_MANAGER_HPP
