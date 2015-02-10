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

#ifndef PIN_HPP_INCLUDED
#define PIN_HPP_INCLUDED

#include "pins_definitions.hpp"
#include "luawrapper/LuaContext.hpp"

#include <fstream>

namespace controller
{
    enum FunctionID
    {
        FTN_ON_ACTIVE = 0,
        FTN_ON_DESACTIVE,
        FTN_WHILE_ACTIVE,
        FTN_WHILE_DESACTIVE,
        FTN_ON_CLICK,
        FTN_ON_CHANGE = 0
    };
   
    class Pin
    {
        public:
            // Cancela o construtor de cópia e atribuição.
            Pin(const Pin&) = delete;
            Pin& operator=(const Pin&) = delete;
        
            /**
             * Construtor.
             * @param id O ID do pino.
             * @param idname O apelido do pino.
             * @param analog Se true, é uma entrada analógica.
             **/
            Pin(PinCode id, const std::string idname);

            /**
             * Destrutor.
             **/
            ~Pin();

            /**
             * Define a direção do pino.
             * @param direction true define o pino como entrada.
             **/
            void setDirection(Direction direction);

            /**
             * @return Retorna true se o pino é de entrada.
             **/
            bool isInput() const;
            
            /**
             * @return Retorna true se o pino é de saída
             **/
            bool isOutput() const;

            /**
             * @return Retorna o nível do pino.
             **/
            uint32_t getValue() const
            {
                return this->value;
            }
            
            Direction getDirection() const
            {
                return this->direction;
            }

            /**
             * Modifica o nível do pino.
             * @param value O nível que será definido. 
             **/
            void setValue(uint32_t value);

            /**
             * Inverte o valor do pino.
             * @warning Se o pino estiver como IN não faz efeito.
             **/
            void invertValue();

            /**
             * @return Retorna o ID do pino.
             **/
            int getID() const
            {
                return id;
            }

            /**
             * @return Retorna o nome atribuído ao pino.
             **/
            const std::string& getName() const
            {
                return this->name;
            }

            /**
             * Modifica o nome do pino.
             * @param name O novo nome do pino.
             **/
            void setName(const std::string& name)
            {
                this->name = name;
            }

            /**
             * Verifica a validade do pino.
             * @return Returna true se o objeto é válido.
             **/
            bool isValid() const;
            
            /**
             * Atualiza as leituras do pino.
             **/
            void refresh();
            
            /**
             * Atualiza a entrada do pino.
             **/
            void updateInput();
            
            /**
             * @return Retorna true se o pino está ativado.
             **/
            bool isEnabled() const
            {
                return this->enabled;
            }

            void setContext(LuaContext* lua, int index);
            
            void setSource(const std::string& source)
            {
                this->source = source;
            }
            
            bool haveSource() const
            {
                return !source.empty();
            }
            
        private:
            /**
             * Exporta o pino.
             * /sys/class/gpio/export
             **/
            bool exportIt();

            /**
             * Deporta o pino.
             * /sys/class/gpio/unexport
             **/
            bool deportIt();

            void write();
            
            void read();

            void execFuction(FunctionID funct);

        private:

            int id;

            Direction direction;
            
            uint32_t value;
            
            std::string id_name;

            std::string name;
            
            std::string source;
            
            std::string value_str;
            
            LuaContext* lua;
            
            std::vector<std::string> fcnts;
            
            bool analog;
            
            bool enabled = false;
    };
}

#endif
