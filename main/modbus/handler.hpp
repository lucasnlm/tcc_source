/**
 * Copyright 2014 Lucas Nunes de Lima
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

#ifndef MODBUS_HANDLER_HPP_INCLUDED
#define MODBUS_HANDLER_HPP_INCLUDED

#include "modbus_connection.hpp"

namespace controller
{
    namespace modbus
    {
        inline int getPort()
        {
            return 502;
        }

        class Modbus
        {
            public:
                // Cancela o construtor de cópia e atribuição.
                Modbus(const Modbus&) = delete;
                Modbus& operator=(const Modbus&) = delete;

                /**
                 * Cria o servidor, ativando o listener para 
                 * um endereço e porta TCP específicos.
                 ***/
                Modbus();
                
                void run();

            private:
                void startAccept();

                void handleAccept(Connection::Pointer new_connection,
                                  const boost::system::error_code& error);
                                  
                boost::asio::io_service io_service;

                tcp::acceptor m_acceptor;

                tcp::socket m_socket;
        };
    }
}

#endif // MODBUS_HANDLER_HPP_INCLUDED
