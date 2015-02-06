#ifndef PLC_DASHBOARD_HPP
#define PLC_DASHBOARD_HPP

#include "pins_definitions.hpp"
#include "controller_io.hpp"

#include <string>

namespace controller
{
    namespace rest
    {
        std::string getValuesTo(const std::string& command, const std::string& param);
    }
}

#endif
