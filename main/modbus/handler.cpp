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

#include "handler.hpp"
#include "logger.hpp"

namespace controller
{
    namespace modbus
    {
        Modbus::Modbus()  
           : io_service(), 
             m_acceptor(io_service, tcp::endpoint(tcp::v4(), modbus::getPort())),
             m_socket(io_service)
        {
            logger.write("Servidor Modbus criado em {}.", modbus::getPort());
            this->startAccept();
        }

        void Modbus::run()
        {
            io_service.run();
        }

        void Modbus::startAccept()
        {
            m_acceptor.async_accept(m_socket,
            [this](boost::system::error_code ec)
            {
                if (!ec)
                {
                    logger.write(u8"Nova conexão Modbus TCP/IP em {}.", m_socket.remote_endpoint().address().to_string());
                    std::make_shared<Session>(std::move(m_socket))->start();
                }

                startAccept();
            });
        }
    }
}
