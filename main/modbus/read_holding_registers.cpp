#include "read_holding_registers.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        ReadHoldingRegistersResponse::ReadHoldingRegistersResponse(Header& header)
        {
            unit = header.getUnit();
            transaction_id.word = header.getTransition();
            protocol.word = 0u;
            //length.word = 0u;
        }

        void ReadHoldingRegistersResponse::appendByte(uint8_t word)
        {
            data.emplace_back(word);
            //length.add(1u);
        }

        void ReadHoldingRegistersResponse::appendWord(Word word)
        {
            data.emplace_back(word.high);
            data.emplace_back(word.low);
            //length.add(2u);
        }

        std::vector<uint8_t> ReadHoldingRegistersResponse::getData() const
        {
            std::vector<uint8_t> total;
            total.reserve(7 + data.size());

            Word length(data.size());

            total.push_back(transaction_id.low);
            total.push_back(transaction_id.high);
            total.push_back(protocol.low);
            total.push_back(protocol.high);
            total.push_back(length.low);
            total.push_back(length.high);
            total.push_back(unit);

            for(size_t i = 0u; i < data.size(); i++)
            {
                total.push_back(data[i]);
            }

            return total;
        }
    }
}
