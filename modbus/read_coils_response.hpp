#ifndef READ_COILS_RESPONSE_HPP_INCLUDED
#define READ_COILS_RESPONSE_HPP_INCLUDED

#include "response.hpp"
#include "header.hpp"

namespace controller
{
    namespace modbus
    {
        class ReadCoilsResponse : public Response
        {
            public:
                ReadCoilsResponse(Header& header);

                void appendByte(uint8_t value);

                void appendWord(Word value);

                std::vector<uint8_t> getData() const;

            private:
                Word transaction_id;

                Word protocol;

                uint8_t unit;

                std::vector<uint8_t> data;
        };
    }
}

#endif
