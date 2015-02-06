#ifndef MODBUS_RESPONSE_HPP_INCLUDED
#define MODBUS_RESPONSE_HPP_INCLUDED

#include "bit_manip.hpp"
#include <vector>

namespace controller
{
    namespace modbus
    {
        /**
         * Descreve uma resposta modbus.
         **/
        class Response
        {
            public:
                Response()
                {}
                
                virtual std::vector<uint8_t> getData() const = 0;
                
                /**
                 * Mostra a resposta no console.
                 **/
                void echo();
        };
    }
}

#endif
