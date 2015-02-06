#include "pin.hpp"
#include "cppformat/format.h"

#include <fstream>
#include <sstream>

#include <iostream>

namespace controller
{
    template <typename T>
    bool writeTo(const std::string& path, T value)
    {
        bool result = true;
        
        try
        {
            std::ofstream file(path);

            if(file.good())
            {
                file << value;                
            }
            else
            {
                result = false;
            }
        }
        catch(...)
        {
            result = false;
        }
        
        return result;
    }
    
    template <typename T>
    T readFrom(const std::string& path)
    {
        T result;
        
        try
        {
            std::ifstream file(path);

            if(file.good())
            {
                file >> result;
            }
        }
        catch(...)
        {}
        
        return result;
    }
    
    bool Pin::exportIt()
    {
        return writeTo<int>("/sys/class/gpio/export", id);
    }
    
    bool Pin::deportIt()
    {
        return writeTo<int>("/sys/class/gpio/unexport", id);
    }

    Pin::Pin(PinCode pin_id, const std::string idname)
        : direction(UNDEFINED), value(INVALID), id_name(idname)
    {
        analog = (toAIN(pin_id) != -1);
        
        if(!analog)
        {
            id = toGPIO(pin_id);
            
            if(!exportIt())
            {
                return;
            }
            
            this->value_str = fmt::format("/sys/class/gpio/gpio{}/value", id);
        }
        else
        {
            id = toAIN(pin_id);
            direction = INPUT;
            
            this->value_str = fmt::format("/sys/bus/iio/devices/iio:device0/in_voltage{}_raw", id);
        }
    }

    Pin::~Pin()
    {}
    
    struct PinObject
    {
        Pin* target;
    };
    
    struct AinObject
    {
        AinObject(Pin* tg, float mult) : target(tg), multiplier(mult)
        {}
        
        Pin* target;
        
        float multiplier = 1.0f;
        
        int getValue() const
        {
            return (int) (target->getValue() * multiplier);
        }
    };
    
    void Pin::setContext(LuaContext* lua, int index)
    {
        if(lua == nullptr)
        {
            return;
        }

        this->lua = lua;
        
        if(!source.empty()) 
        {
            try
            {
                lua->executeCode(source);
            }
            catch(std::exception& e)
            {
                std::cout << "Erro Lua: " << e.what() << std::endl;
            }
            
            std::string matrix;
            matrix.reserve(1024);
            
            if(!analog)
            {
                std::string var_name = fmt::format("___gpio{}", index);
                
                std::string catche_ftns = 
                    fmt::format("{0}.onActive = onActive or (function() end);"
                                "{0}.onDesactive = onDesactive or (function() end);"
                                "{0}.whileActive = whileActive or (function() end);"
                                "{0}.whileDesative = whileDesative or (function() end);"
                                "{0}.onClick = onClick or (function() end);", var_name);
                
                std::string free_user_defs = "onActive = nil;"
                                             "onDesactive = nil;"
                                             "whileActive = nil;"
                                             "whileDesative = nil;"
                                             "onClick = nil;";
                
                fcnts.emplace_back(fmt::format("{0}.onActive();", var_name));
                fcnts.emplace_back(fmt::format("{0}.onDesactive();", var_name));
                fcnts.emplace_back(fmt::format("{0}.whileActive();", var_name));
                fcnts.emplace_back(fmt::format("{0}.whileDesative();", var_name));
                fcnts.emplace_back(fmt::format("{0}.onClick();", var_name));
                
                matrix.append(var_name);
                matrix.append("={};");               
                matrix.append(catche_ftns);
                matrix.append(free_user_defs);
            }
            else
            {
                std::string var_name = fmt::format("___ain{}", index);
                
                std::string catche_ftns = 
                    fmt::format("{0}.whenChange = whenChange or (function(value) end);", var_name);
                    
                std::string free_user_defs =
                            "whenChange = nil;";
                            
                fcnts.emplace_back(fmt::format("{}.whenChange(AIN{}.value);", var_name, index));
                
                matrix.append(var_name);
                matrix.append("={};");
                matrix.append(catche_ftns);
                matrix.append(free_user_defs);
            }

            try
            {
                lua->executeCode(matrix);
            }
            catch(std::exception& e)
            {
                std::cout << "Erro Lua: " << e.what() << std::endl;
            }
        }
        
        if(!analog)
        {
            lua->writeVariable(fmt::format("GPIO{}", index), PinObject{this});
            
            lua->registerMember<PinObject, bool>("value",
                [](const PinObject& object) -> bool 
                {
                    return object.target->getValue() != 0x00;
                },
                [](PinObject& object, bool rvalue) 
                {
                    object.target->setValue(rvalue);
                }
            );
        }
        else
        {
            float multiplier;
            
            try
            {
                multiplier = lua->readVariable<float>("multiplier");
            }
            catch(std::exception e)
            {
                multiplier = 1.0f;
            }
            
            lua->writeVariable(fmt::format("AIN{}", index), AinObject(this, multiplier));
            
            lua->registerMember<AinObject, int>("value",
                [](const AinObject& object) -> int 
                {
                    return object.getValue();
                },
                [](AinObject& object, int rvalue) 
                {
                    // somente leitura
                });
        }
    }
    
    void Pin::execFuction(FunctionID funct)
    {
        try
        {
            lua->executeCode(fcnts[funct]);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    void Pin::updateInput()
    {
        if(!isValid())
        {
            return;
        }
        
        if(this->isInput())
        {
            this->read();
        }
    }
    
    void Pin::refresh()
    {
        if(!isValid())
        {
            return;
        }

        if(!analog)
        {
            if(haveSource())
            {
                this->execFuction((value != 0) ? FTN_WHILE_ACTIVE : FTN_WHILE_DESACTIVE);
            }
        }
        else
        {
            if(haveSource())
            {
                this->execFuction(FTN_ON_CHANGE);
            }
        }
    }

    void Pin::setDirection(Direction direction)
    {
        if(analog)
        {
            return;
        }
        
        const std::string direction_path = fmt::format("/sys/class/gpio/gpio{}/direction", id);
        
        if(direction == INPUT)
        {
            writeTo(direction_path, "in");
        }
        else if(direction == OUTPUT)
        {
            writeTo(direction_path, "out");
        }

        this->direction = direction;
    }
    
    void Pin::invertValue(void)
    {
        if(analog)
        {
            return;
        }
        
        if(isOutput())
        {
            auto value = getValue();
            setValue((value != 0x00) ? LOW : HIGH);
        }
    }
    
    bool Pin::isInput() const
    {
        return (direction == INPUT);
    }
    
    bool Pin::isOutput() const
    {
        return (direction == OUTPUT);
    }
    
    bool Pin::isValid(void) const
    {
        return (this->id != 0xffffff && this->direction != UNDEFINED);
    }
    
    void Pin::write()
    {
        if(!analog)
        {
            writeTo(this->value_str, value);
        }
    }
    
    void Pin::read()
    {
        if(!analog)
        {
            int value = readFrom<int>(fmt::format("/sys/class/gpio/gpio{}/value", id));
            this->value = (value != 0u) ? 0xFF : 0x00;
        }
        else
        {
            this->value = readFrom<int>(fmt::format("/sys/bus/iio/devices/iio:device0/in_voltage{}_raw", id));
        }
    }

    void Pin::setValue(uint32_t value)
    {
        if(!analog)
        {
            bool same = ((this->value != 0) == (value != 0u));
            
            if(this->value != value)
            {
                this->value = value;
                this->write();
            }
            
            if(!same && haveSource())
            {
                this->execFuction((this->value != 0u) ? FTN_ON_ACTIVE : FTN_ON_DESACTIVE);
            }
        }
    }
}
