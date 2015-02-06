#ifndef SYSTEM_HPP_INCLUDED
#define SYSTEM_HPP_INCLUDED

namespace controller
{
    class System
    {
        public:
            /**
             * @return Retorna o número do processo do programa.
             **/
            static int getPID();
            
            /**
             * @return Retorna o valor de nice do programa.
             **/
            static int getPriority();
            
            /**
             * Modifica a prioridade do programa (nice).
             * @param priority Um valor entre -20 e 20.
             **/
            static void setPriority(int priority);
            
            /**
             * Desliga o sistema.
             **/
            static void shutdown();
            
            /**
             * Reinicia o sistema.
             **/
            static void reboot();
    };
}

#endif
