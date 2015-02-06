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
