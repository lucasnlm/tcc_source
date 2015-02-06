#ifndef READ_INPUT_REGISTERS_HPP
#define READ_INPUT_REGISTERS_HPP

#include "response.hpp"
#include "header.hpp"

namespace controller
{
    namespace modbus
    {
        class ReadInputRegisters : public Response
        {
            public:
                ReadInputRegisters(Header& header);

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
