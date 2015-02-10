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

#ifndef MODBUS_CONNECTION_HPP_INCLUDED
#define MODBUS_CONNECTION_HPP_INCLUDED

#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <array>

#include "modbus.hpp"

namespace controller
{
    namespace modbus
    {
        using boost::asio::ip::tcp;

        class Connection : public boost::enable_shared_from_this<Connection>
        {
            public:
                typedef boost::shared_ptr<Connection> Pointer;

                static Pointer create(boost::asio::io_service& io_service);

                tcp::socket& socket();

                void start();

            private:
                Connection(boost::asio::io_service& io_service);

                void handleWrite(const boost::system::error_code&, size_t);

                tcp::socket m_socket;

                std::string m_message;
        };

        class Session : public std::enable_shared_from_this<Session>
        {
            public:
                Session(tcp::socket socket);

                void start();

            private:
                void doRead();

                void doWrite(Response& res);

                tcp::socket m_socket;

                std::array<char, MAX_REQUEST_LENGTH> message;
        };

    }
}

#endif // MODBUS_CONNECTION_HPP_INCLUDED
