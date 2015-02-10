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

#ifndef GPIO_HPP_INCLUDED
#define GPIO_HPP_INCLUDED

#include "pin.hpp"

namespace controller
{
    namespace IO
    {
        /**
         * Instancia os pinos GPIO.
         **/
        void create();
        
        /**
         * Atualiza as entradas dos pinos.
         **/
        void refresh();

        /**
         * @param index O índice do pino procurado.
         * @param analog Se true, o index é referenciado aos analógicos.
         * @return Retorna o pino alvo.
         **/
        Pin& getPin(size_t index, bool analog = false);
        
        inline Pin& getAnalog(size_t index)
        {
            return getPin(index, true);
        }
    }
}

#endif
