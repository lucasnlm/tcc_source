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
