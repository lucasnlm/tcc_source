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
