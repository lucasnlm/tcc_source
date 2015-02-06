#include "analog.hpp"
#include "util.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

namespace controller
{
    namespace Analog
    {
        /*void readTo(int& analog, const char* line)
        {
            std::ifstream file(line);

            try
            {
                file >> analog;
            }
            catch(...)
            {
                // Ocorreu um erro. Pode ser:
                //  - Falta de permissão de leitura.
                //  - Formato inválido.
                //  - Arquivo não encontrado.
                //  - Driver do ADC mal instalado.
            }
        }*/
        
        class AnalogManager 
        {
            public:
                AnalogManager(const char* pin) : file(pin)
                {}
                
                inline int getValue() const 
                {
                    return this->value;
                }
                
                void refresh()
                {
                    try
                    {
                        file.seekg(0);
                        file >> value;
                    }
                    catch(std::exception& e)
                    {
                        // Ocorreu um erro. Pode ser:
                        //  - Falta de permissão de leitura.
                        //  - Formato inválido.
                        //  - Arquivo não encontrado.
                        //  - Driver do ADC mal instalado.
                    }
                }
            
            private:
                std::ifstream file;
                
                int value;
        };
        
        // As sete entradas analógicas.
        AnalogManager g_analog[] = 
        {
            {"/sys/bus/iio/devices/iio:device0/in_voltage0_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage1_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage2_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage3_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage4_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage5_raw"},
            {"/sys/bus/iio/devices/iio:device0/in_voltage6_raw"}
        };

        int AIN0()
        {
            return g_analog[0].getValue();
        }

        int AIN1()
        {
            return g_analog[1].getValue();
        }

        int AIN2()
        {
            return g_analog[2].getValue();
        }

        int AIN3()
        {
            return g_analog[3].getValue();
        }

        int AIN4()
        {
            return g_analog[4].getValue();
        }

        int AIN5()
        {
            return g_analog[5].getValue();
        }

        int AIN6()
        {
            return g_analog[6].getValue();
        }
        
        void refresh()
        {
            for(int i = 0; i < 7; i++)
                g_analog[0].refresh();
            
            /*readTo(g_analog[0], "/sys/bus/iio/devices/iio:device0/in_voltage0_raw");
            readTo(g_analog[1], "/sys/bus/iio/devices/iio:device0/in_voltage1_raw");
            readTo(g_analog[2], "/sys/bus/iio/devices/iio:device0/in_voltage2_raw");
            readTo(g_analog[3], "/sys/bus/iio/devices/iio:device0/in_voltage3_raw");
            readTo(g_analog[4], "/sys/bus/iio/devices/iio:device0/in_voltage4_raw");
            readTo(g_analog[5], "/sys/bus/iio/devices/iio:device0/in_voltage5_raw");
            readTo(g_analog[6], "/sys/bus/iio/devices/iio:device0/in_voltage6_raw");*/
        }
    }
}
