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
