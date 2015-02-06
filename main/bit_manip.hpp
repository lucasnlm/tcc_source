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
