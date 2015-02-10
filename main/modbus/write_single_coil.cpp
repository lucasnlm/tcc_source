/**
 * Copyright 2014 Lucas Nunes de Lima
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

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
