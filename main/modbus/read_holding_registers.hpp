#ifndef READ_HOLDING_REGISTERS_RESPONSE
#define READ_HOLDING_REGISTERS_RESPONSE

#include "response.hpp"
#include "header.hpp"

namespace controller
{
    namespace modbus
    {
        class ReadHoldingRegistersResponse : public Response
        {
            public:
                ReadHoldingRegistersResponse(Header& header);

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
