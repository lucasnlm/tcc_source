#include "modbus_connection.hpp"
#include "bit_manip.hpp"
#include "header.hpp"
#include "controller_io.hpp"

#include "read_coils_response.hpp"
#include "read_discrete_inputs.hpp"
#include "read_holding_registers.hpp"
#include "read_input_registers.hpp"
#include "write_single_coil.hpp"
#include "read_register.hpp"
#include "write_register.hpp"

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
                    
                    std::cout << ">";
                    auto arr = message.data();
                    for(int i = 0; i < 15; i++)
                    {
                        std::cout << std::to_string(int(arr[i])) << ",";
                    }
                    std::cout << std::endl;
                    
                    std::cout << "FTN: " << std::to_string(header->getFunctionCode()) << std::endl;

                    if(header->getFunctionCode() == READ_COILS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        ReadRegister funct(input_data);

                        ReadCoilsResponse res(*header);

                        // Código da Função
                        res.appendByte(READ_COILS);

                        uint16_t quantity = funct.getQuantity().word;
                        int reference = funct.getRegisterReference().word;
                        int bits = 0;
                        int response = 0;

                        // Número de Bytes
                        if(quantity < 9)
                        {
                            res.appendByte(1);
                        }
                        else
                        {
                            res.appendByte(static_cast<int>(quantity / 8) + 1);
                        }

                        // Bytes:
                        size_t limit = (reference + quantity);
                        for(size_t i = reference; i < limit; i++)
                        {
                            const Pin& pin = IO::getPin(i);
                            response = appendBit(response, pin.getValue() != 0u);
                            bits++;
                            
                            if(bits == 8)
                            {
                                res.appendByte(response);
                                bits = 0;
                            }
                        }
                        
                        if(bits != 0)
                        {
                            res.appendByte(response);
                        }

                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == READ_DISCRETE_INPUTS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        ReadRegister funct(input_data);

                        ReadDiscreteInputsResponse res(*header);

                        // Código da Função
                        res.appendByte(READ_DISCRETE_INPUTS);

                        uint16_t quantity = funct.getQuantity().word;
                        int reference = funct.getRegisterReference().word;
                        int bits = 0;
                        int response = 0;

                        // Número de Bytes
                        if(quantity < 9)
                        {
                            res.appendByte(1);
                        }
                        else
                        {
                            res.appendByte(static_cast<int>(quantity / 8) + 1);
                        }

                        // Bytes:
                        size_t limit = (reference + quantity);
                        for(size_t i = reference; i < limit; i++)
                        {
                            const Pin& pin = IO::getPin(i);
                            response = appendBit(response, pin.getValue() != 0u);
                            bits++;
                            
                            if(bits == 8)
                            {
                                res.appendByte(response);
                                bits = 0;
                            }
                        }
                        
                        if(bits != 0)
                        {
                            res.appendByte(response);
                        }

                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == READ_HOLDING_REGISTERS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        ReadRegister funct(input_data);

                        ReadHoldingRegistersResponse res(*header);

                        // Código da Função
                        res.appendByte(READ_HOLDING_REGISTERS);

                        uint16_t quantity = funct.getQuantity().word;
                        int reference = funct.getRegisterReference().word;

                        // Número de Bytes
                        res.appendByte(quantity * 2);

                        // Bytes:
                        const size_t limit = (reference + quantity);
                        for(size_t i = reference; i < limit; i++)
                        {
                            const Pin& pin = IO::getPin(i);
                            res.appendWord(pin.getValue());
                        }
                        
                        res.echo();
                        
                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == READ_INPUT_REGISTERS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        ReadRegister funct(input_data);

                        ReadInputRegisters res(*header);

                        // Código da Função
                        res.appendByte(READ_INPUT_REGISTERS);

                        size_t quantity = funct.getQuantity().word;
                        size_t reference = funct.getRegisterReference().word + 12u;
                        

                        std::cout << "quantity = " << quantity << std::endl;
                        std::cout << "ref = " << reference << std::endl;

                        // Número de Bytes
                        res.appendByte(quantity * 2);

                        // Bytes:
                        const size_t limit = (reference + quantity);
                        for(size_t i = reference; i < limit; i++)
                        {
                            const Pin& pin = IO::getPin(i);
                            
                            std::cout << i << " -> " << std::to_string(pin.getValue()) << std::endl;
                            res.appendWord(pin.getValue());
                        }
                        
                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == WRITE_SINGLE_COIL)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        WriteRegister funct(input_data);

                        WriteSingleCoil res(*header);

                        Pin& pin = IO::getPin(funct.getOutputAddress().word);
                        pin.setValue((funct.getOutputValue().word == 0x00) ? 0x00 : 0xFF);
                            
                        std::cout << "target =  " << funct.getOutputAddress().word << std::endl;
                        std::cout << "to = " << funct.getOutputValue().word  << std::endl;
                        
                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == WRITE_SINGLE_REGISTER)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        WriteRegister funct(input_data);

                        WriteSingleCoil res(*header);

                        Pin& pin = IO::getPin(funct.getOutputAddress().word);
                        pin.setValue(funct.getOutputValue().low);
                        
                        std::cout << "target =  " << funct.getOutputAddress().word << std::endl;
                        std::cout << "to = " << funct.getOutputValue().word  << std::endl;
                        
                        doWrite(res);
                    }
                    else if(header->getFunctionCode() == WRITE_MULTIPLE_COILS)
                    {
                        const uint8_t* input_data = reinterpret_cast<const uint8_t*>(message.data());
                        WriteRegister funct(input_data);

                        WriteSingleCoil res(*header);

                        Pin& pin = IO::getPin(funct.getOutputAddress().word);
                        pin.setValue(funct.getOutputValue().word);
                        
                        std::cout << "target =  " << funct.getOutputAddress().word << std::endl;
                        std::cout << "to = " << funct.getOutputValue().word  << std::endl;
                        
                        doWrite(res);
                    }
                }
            });
        }

        void Session::doWrite(Response& res)
        {
            auto self(shared_from_this());

            std::cout << "<";
            auto arr = res.getData();
            for(int i = 0; i < 15; i++)
            {
                std::cout << std::to_string(int(arr[i])) << ",";
            }
            std::cout << std::endl;

            boost::asio::async_write(m_socket, boost::asio::buffer(res.getData()),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec)
                {
                    doRead();
                }
                else
                {
                    std::cout << "foi nao" << std::endl;
                }
            });
        }
    }
}
