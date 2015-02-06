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
