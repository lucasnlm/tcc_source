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
