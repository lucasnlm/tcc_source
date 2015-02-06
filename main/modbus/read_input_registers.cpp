#include "read_input_registers.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        ReadInputRegisters::ReadInputRegisters(Header& header)
        {
            unit = header.getUnit();
            transaction_id.word = header.getTransition();
            protocol.word = 0u;
        }

        void ReadInputRegisters::appendByte(uint8_t word)
        {
            data.emplace_back(word);
        }

        void ReadInputRegisters::appendWord(Word word)
        {
            data.emplace_back(word.high);
            data.emplace_back(word.low);
        }

        std::vector<uint8_t> ReadInputRegisters::getData() const
        {
            std::vector<uint8_t> total;
            total.reserve(7 + data.size());
            
            Word length(1u + data.size());

            total.push_back(transaction_id.low);
            total.push_back(transaction_id.high);
            total.push_back(protocol.low);
            total.push_back(protocol.high);
            total.push_back(length.high);
            total.push_back(length.low); // TODO: invertido
            total.push_back(unit);

            for(size_t i = 0u; i < data.size(); i++)
            {
                total.push_back(data[i]);
            }

            return total;
        }
    }
}
