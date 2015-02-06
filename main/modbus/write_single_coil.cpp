#include "write_single_coil.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        WriteSingleCoil::WriteSingleCoil(Header& header)
        {
            function_code = header.getFunctionCode();
            transaction_id.word = header.getTransition();
            unit = header.getUnit();
            protocol.word = 0u;
            length.high = 0;
            length.low  = 6;
        }

        std::vector<uint8_t> WriteSingleCoil::getData() const
        {
            std::vector<uint8_t> total;

            total.push_back(transaction_id.low);
            total.push_back(transaction_id.high);
            total.push_back(protocol.low);
            total.push_back(protocol.high);
            total.push_back(length.low);
            total.push_back(length.high);
            total.push_back(unit);

            total.push_back(function_code);
            total.push_back(output_address.low);
            total.push_back(output_address.high);
            total.push_back(output_value.low);
            total.push_back(output_value.high);

            return total;
        }
    }
}
