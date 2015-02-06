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
