#ifndef READ_DISCRETE_INPUTS_RESPONSE_HPP_INCLUDED
#define READ_DISCRETE_INPUTS_RESPONSE_HPP_INCLUDED

#include "response.hpp"
#include "header.hpp"

namespace controller
{
    namespace modbus
    {
        class ReadDiscreteInputsResponse : public Response
        {
            public:
                ReadDiscreteInputsResponse(Header& header);

                void appendByte(uint8_t value);

                std::vector<uint8_t> getData() const;

            private:
                Word transaction_id;

                Word protocol;

                Word length;

                uint8_t unit;

                std::vector<uint8_t> data;
        };
    }
}

#endif
