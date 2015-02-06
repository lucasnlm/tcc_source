#ifndef PRESETS_HPP_INCLUDED
#define PRESETS_HPP_INCLUDED

#include <string>
#include "pins_definitions.hpp"

namespace controller
{    
    struct Preset
    {
        const std::string name;
        const Direction direction;
        const bool analog;
    };
    
    const Preset& findPreset(const std::string& name);
}

#endif
