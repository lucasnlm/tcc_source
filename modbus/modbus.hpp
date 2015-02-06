#ifndef MODBUS_STRUCTS_HPP_INCLUDED
#define MODBUS_STRUCTS_HPP_INCLUDED

#include "response.hpp"

namespace controller
{
    namespace modbus
    {
        const int MAX_REQUEST_LENGTH = 256;

        /**
         * Códigos de Função Modbus.
         **/
        enum FunctionCode : uint16_t
        {
            READ_COILS = 0x01,
            READ_DISCRETE_INPUTS = 0x02,
            READ_HOLDING_REGISTERS = 0x03,
            READ_INPUT_REGISTERS = 0x04,
            
            WRITE_SINGLE_COIL = 0x05,
            WRITE_SINGLE_REGISTER = 0x06,
            WRITE_MULTIPLE_COILS = 0x0F,
            WRITE_MULTIPLE_REGISTERS = 0x10
        };
    }
}

#endif // MODBUS_STRUCTS_HPP_INCLUDED
