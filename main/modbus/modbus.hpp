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
