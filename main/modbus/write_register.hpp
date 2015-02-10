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

#ifndef WRITE_REGISTER_HPP_INCLUDED
#define WRITE_REGISTER_HPP_INCLUDED

#include "bit_manip.hpp"
#include "header.hpp"
#include <cstdint>

namespace controller
{
    namespace modbus
    {
        class WriteRegister : public Header
        {
            public:
                /**
                 * Construtor.
                 * @param O buffer lido de um cliente.
                 **/
                WriteRegister(const uint8_t* buffer);

                Word getOutputAddress() const
                {
                    return output_address;
                }

                Word getOutputValue() const
                {
                    return output_value;
                }

            private:
                // O número de referência.
                Word output_address;

                // O número de palavras que serão transferidas.
                Word output_value;
        };
    }
}

#endif
