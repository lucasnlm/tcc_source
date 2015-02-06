#include "read_coils_response.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        ReadCoilsResponse::ReadCoilsResponse(Header& header)
        {
            unit = header.getUnit();
            transaction_id.word = header.getTransition();
            protocol.word = 0u;
        }

        void ReadCoilsResponse::appendByte(uint8_t word)
        {
            data.emplace_back(word);
            
        }

        std::vector<uint8_t> ReadCoilsResponse::getData() const
        {
            std::vector<uint8_t> total;
            total.reserve(7 + data.size());

            Word length(1u + data.size());

            total.push_back(transaction_id.low);
            total.push_back(transaction_id.high);
            total.push_back(protocol.low);
            total.push_back(protocol.high);
            total.push_back(length.high); // TODO: length tá invertido. arrumar isso.
            total.push_back(length.low);
            total.push_back(unit);

            for(size_t i = 0u; i < data.size(); i++)
            {
                total.push_back(data[i]);
            }

            return total;
        }
    }
}
