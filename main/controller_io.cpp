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

#include "controller_io.hpp"

#include <vector>

namespace controller
{
    namespace IO
    {
        Pin pins[] =
        {
            { P8_7,  "IO1" },  // 01
            { P8_8,  "IO2" },  // 02
            { P8_9,  "IO3" },  // 03
            { P8_10, "IO4" },  // 04
            { P8_11, "IO5" },  // 05
            { P8_12, "IO6" },  // 06
            
            { P8_14, "IO7" },  // 07
            { P8_15, "IO8" },  // 08
            { P8_16, "IO9" },  // 09
            { P8_17, "IO10" }, // 10
            { P8_18, "IO11" }, // 11
            { P8_20, "IO12" }, // 12
            
            { AIN0, "AIN1" }, // 13
            { AIN1, "AIN2" }, // 14
            { AIN2, "AIN3" }, // 15
            { AIN3, "AIN4" }, // 16
            { AIN4, "AIN5" }, // 17
            { AIN5, "AIN6" }  // 18
        };

        void refresh()
        {
            for(Pin& pin : pins)
            {
                pin.updateInput();
            }
            
            for(Pin& pin : pins)
            {
                pin.refresh();
            }
        }

        Pin& getPin(size_t index, bool analog)
        {
            if(analog)
            {
                index += 12;
            }
            
            if(index < sizeof(pins))
            {
                return pins[index];
            }
            else
            {
                static Pin generic_pin(DGND, "DGND");
                return generic_pin;
            }
        }
    }
}
