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
