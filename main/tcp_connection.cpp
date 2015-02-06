#include "modbus_connection.hpp"
#include "bit_manip.hpp"
#include "gpio.hpp"

#include <iostream>


namespace controller
{
    namespace modbus
    {
        Session::Session(tcp::socket socket) : m_socket(std::move(socket))
        {}

        void Session::start()
        {
            doRead();
        }

        void Session::doRead()
        {
            auto self(shared_from_this());

            m_socket.async_read_some(boost::asio::buffer(message),
            [this, self](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    Header *header = reinterpret_cast<Header*>(message.data());

                    std::cout << "in: ";
                    const uint8_t* dats = (const uint8_t*) message.data();
                    for(int i = 0; i < 12; i++)
                    {
                        std::cout << std::to_string(dats[i]) << ",";
                    }
                    std::cout << std::endl;

                    if(header->getFunctionCode() == READ_COILS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        ReadRegister funct(input_data);

                        Response res(*header);

                        // Código da Função
                        res.appendByte(READ_COILS);

                        int quantity = funct.getQuantity();
                        int reference = funct.getRegisterReference().low;
                        int response = 0;
                        
                        std::cout << "q = " << quantity << std::endl;
                        std::cout << "r = " << reference << std::endl;
                        
                        // Número de Bytes
                        res.appendByte(uint8_t(1)); // F01 lê só 1 byte.

                        // Bytes:
                        size_t limit = (reference + 4);
                        for(size_t i = reference; i < limit; i++)
                        {
                            const Pin& pin = gpio::getPin(i);
                            response = appendBit(response, pin.getValue() == HIGH);
                        }
                        
                        res.appendByte(response); // Até 4 bits.

                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == READ_DISCRETE_INPUTS)
                    {

                    }
                }
            });
        }

        void Session::doWrite(Response& res)
        {
            auto self(shared_from_this());

            res.print();

            boost::asio::async_write(m_socket, boost::asio::buffer(res.getData()),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec)
                {
                    doRead();
                }
            });
        }
    }
}
