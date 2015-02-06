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
