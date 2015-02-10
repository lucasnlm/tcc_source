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

#ifndef MODBUS_HEADER_HPP_INCLUDED
#define MODBUS_HEADER_HPP_INCLUDED

namespace controller
{
    namespace modbus
    {
        /**
         * Descreve o cabeçalho de uma requisição modbus.
         **/
        class Header
        {
            public:
                /**
                 * Construtor.
                 **/
                Header()
                {}

                /**
                 * @return Retorna o ID da transação.
                 **/
                uint16_t getTransition() const
                {
                    return this->transaction_id.word;
                }

                /**
                 * @return Retorna o ID da unidade.
                 **/
                uint8_t getUnit() const
                {
                    return this->unit;
                }

                /**
                 * @return Retorna o código da Função.
                 **/
                uint8_t getFunctionCode() const
                {
                    return this->function_code;
                }

            protected:
                // Transaction ID. Not important.
                // Usually zero when making a request, the server will copy them faithfully into the response.
                Word transaction_id;

                // Protocol number. Must be zero.
                Word protocol;

                // Equal to the number of bytes which follow
                Word length;

                // Unit number.
                uint8_t unit;

                // Function code.
                uint8_t function_code;
        };
    }
}

#endif
