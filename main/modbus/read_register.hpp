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

#ifndef READ_REGISTER_HPP
#define READ_REGISTER_HPP

#include "bit_manip.hpp"
#include "header.hpp"
#include <cstdint>

namespace controller
{
    namespace modbus
    {
        class ReadRegister : public Header
        {
            public:
                /**
                 * Construtor.
                 * @param O buffer lido de um cliente.
                 **/
                ReadRegister(const uint8_t* buffer);

                /**
                 * @return Retorna o registrador de referência.
                 **/
                Word getRegisterReference() const
                {
                    return reference_number;
                }

                /**
                 * @return Retorna a quantidade de registradores que 
                 * serão retornados.
                 **/
                Word getQuantity() const
                {
                    return quantity;
                }

            private:
                // O número de referência.
                Word reference_number;

                // O número de palavras que serão transferidas.
                Word quantity;
        };
    }
}

#endif
