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

#include "bit_manip.hpp"

namespace controller
{
    Word::Word() : word(0u)
    {}
    
    Word::Word(uint16_t word)
    {
        this->word = word;
    }
    
    Word::Word(uint8_t high, uint8_t low)
    {
        this->high = high;
        this->low = low;
    }
    
    void Word::add(uint16_t val)
    {
        val = ((high << 8) + low) + val;
        this->word = val;
    }
    
    int appendBit(int input, bool bit)
    {
        input = input << 1;
        if(bit) input = input | 0x01;
        return input;
    }
    
    int appendNibble(int input, int nibble)
    {
        nibble = nibble & 0x0F;
        input = input << 4;
        input = input | nibble;
        return input;
    }
}
