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
