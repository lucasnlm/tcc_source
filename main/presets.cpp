#include "presets.hpp"

namespace controller
{
    Preset presets[] =
    {
        { "unknown", UNDEFINED, false },
        { "lamp", OUTPUT, false },
        { "general", OUTPUT, false },
        { "relay", OUTPUT, false },
        { "timer", OUTPUT, false },
        { "motion", INPUT, false },
        { "date", OUTPUT, false },
        { "dumidity", INPUT, true },
        { "lumen", INPUT, true },
        { "temperature", INPUT, true }
    };
    
    const Preset& findPreset(const std::string& name)
    {
        for(const Preset& ps : presets)
        {
            if(ps.name == name)
            {
                return ps;
            }
        }
        
        return presets[0];
    }
}
