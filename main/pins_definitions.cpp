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

#include "pins_definitions.hpp"

namespace controller
{
    int toGPIO(PinCode pin)
    {
        const int gpio = (pin & 0xff0000) >> 16;
        return (gpio != 0xff ? gpio : -1);
    }
    
    int toAIN(PinCode pin)
    {
        int ain = (pin & 0x00ff00) >> 8;
        return (ain != 0xff ? ain : -1);
    }
    
    int toPWM(PinCode pin)
    {
        int pwm_mux_mode = (pin & 0x0000ff);
        return (pwm_mux_mode != 0xff ? pwm_mux_mode : -1);
    }
}
