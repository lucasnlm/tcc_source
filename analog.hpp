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
