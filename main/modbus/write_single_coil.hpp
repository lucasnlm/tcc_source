#ifndef WRITE_SINGLE_COIL_INCLUDED
#define WRITE_SINGLE_COIL_INCLUDED

#include "response.hpp"
#include "header.hpp"

namespace controller
{
    namespace modbus
    {
        class WriteSingleCoil : public Response
        {
            public:
                WriteSingleCoil(Header& header);

                std::vector<uint8_t> getData() const;

            private:
                Word transaction_id;

                Word protocol;

                Word length;

                uint8_t unit;
            
                // Function code.
                uint8_t function_code;
            
                // O número de referência.
                Word output_address;

                // O número de palavras que serão transferidas.
                Word output_value;
        };
    }
}

#endif
