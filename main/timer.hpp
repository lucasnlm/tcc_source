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

#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <ctime>

namespace controller
{
    /**
     * Descreve um temporizador.
     */
    class Timer
    {
        public:
            /**
             * @brief Construtor. Inicia a contagem.
             */
            Timer();

            /**
             * @brief Reseta o temporizador.
             */
            void resetTimer();

            /**
             * @return Retorna o diferença entre o tempo agora e quando o temporizador foi iniciado.
             */
            std::time_t getDiff() const;

        private:
            /**
             * @return Retorna o tempo em milisegundos de agora.
             */
            static std::time_t getMiliseconds();

        private:
            // armazena os milisegundos da último reset.
            std::time_t last;
    };
}

#endif // TIMER_HPP_INCLUDED
