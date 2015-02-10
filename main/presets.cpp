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
