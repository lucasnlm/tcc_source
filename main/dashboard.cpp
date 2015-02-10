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

#include "dashboard.hpp"
#include "analog.hpp"
#include "controller_io.hpp"

#include <cstdlib>
#include <string>
#include <sstream>
#include <cstdlib>

namespace controller
{
    namespace rest
    {
        std::string getValuesTo(const std::string& command, const std::string& param)
        {
            if(command == "inv_value")
            {
                int index = std::stoi(param);
                //Pin& pin = gpio::getPin(index);
                //pin.invertValue();
            }

            return "";
        }
    }
}
