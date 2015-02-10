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

#ifndef BIT_MANIP_HPP_INCLUDED
#define BIT_MANIP_HPP_INCLUDED

#include <cstdint>

namespace controller
{
    /**
     * Big Endian Word.
     **/
    union Word
    {
        Word();

        Word(uint16_t value);

        Word(uint8_t high, uint8_t low);

        void add(uint16_t val);
        
        uint16_t word;

        struct
        {
            uint8_t low;
            uint8_t high;
        };
    };
    
    int appendNibble(int input, int nibble);
    int appendBit(int input, bool bit);
}

#endif
