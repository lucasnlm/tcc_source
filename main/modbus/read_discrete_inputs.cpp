#include "read_discrete_inputs.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        ReadDiscreteInputsResponse::ReadDiscreteInputsResponse(Header& header)
        {
            transaction_id.word = header.getTransition();
            protocol.word = 0u;
            length.word = 0u;
        }

        void ReadDiscreteInputsResponse::appendByte(uint8_t word)
        {
            data.emplace_back(word);
            length.word++;
        }

        std::vector<uint8_t> ReadDiscreteInputsResponse::getData() const
        {
            std::vector<uint8_t> total;
            total.reserve(7 + data.size());

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
