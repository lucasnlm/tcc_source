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

#ifndef ANALOG_TO_DIGITAL_HPP
#define ANALOG_TO_DIGITAL_HPP

namespace controller
{
    namespace Analog
    {
        // Limites do Conversor
        const int MIN_VALUE = 0;
        const int MAX_VALUE = 4096;
        
        /**
         * Estrutura utilizada para interface com
         * a máquina Lua.
         **/
        class AIN
        {
            public:
                /**
                 * Construtor.
                 **/
                AIN() : value(0)
                {}
                
                void onChange(int value)
                {}
                
                /**
                 * Estrutura utilizada pela máquina Lua.
                 **/
                int value;
        };
        
        /**
         * @return Retorna a entrada AD #1.
         **/
        int AIN0();
        
        /**
         * @return Retorna a entrada AD #2.
         **/
        int AIN1();
        
        /**
         * @return Retorna a entrada AD #3.
         **/
        int AIN2();
        
        /**
         * @return Retorna a entrada AD #4.
         **/
        int AIN3();
        
        /**
         * @return Retorna a entrada AD #5.
         **/
        int AIN4();
        
        /**
         * @return Retorna a entrada AD #6.
         **/
        int AIN5();
        
        /**
         * @return Retorna a entrada AD #7.
         **/
        int AIN6();

        /**
         * Atualiza as leituras dos analógicos.
         **/
        void refresh();
    }
}

#endif
