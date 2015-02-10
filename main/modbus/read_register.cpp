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

#include "read_register.hpp"

namespace controller
{
    namespace modbus
    {
        ReadRegister::ReadRegister(const uint8_t* buffer)
        {
            // ID da Transação
            transaction_id.high = buffer[0];
            transaction_id.low = buffer[1];

            // Protocolo, sempre zero
            // Consome buffer[2] e buffer[3]
            
            // Comprimento da Mensagem
            length.high = buffer[4];
            length.low = buffer[5];
            
            // ID da unidade.
            unit = buffer[6];
            
            // Código da Função
            function_code = buffer[7];
            
            // Número de Referência
            reference_number.high = buffer[8];
            reference_number.low = buffer[9];
            
            // Quantidade de bits que deve ser retornados
            quantity.high = buffer[10];
            quantity.low = buffer[11];
        }
    }
}
