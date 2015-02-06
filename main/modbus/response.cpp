#include "response.hpp"
#include "modbus.hpp"

#include <string>
#include <iostream>

namespace controller
{
    namespace modbus
    {
        void Response::echo()
        {
            auto arr = getData();
            
            std::cout << "r: ";
            
            for(uint8_t i : arr)
            {
                std::cout << std::to_string(i) << ",";
            }

            std::cout << std::endl;
        }
    }
}
