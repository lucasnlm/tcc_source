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

#ifndef HTTP_UTIL_HPP_INCLUDED
#define HTTP_UTIL_HPP_INCLUDED

#include <string>

namespace controller
{
    namespace http
    {
        namespace util
        {
            /**
             * @return Retorna true se o valor é um caractere HTTP.
             **/
            bool isChar(int value);

            /**
             * @return Retorna true se o valor é um caractere de controle HTTP.
             **/
            bool isControl(int value);

            /**
             * @return Retorna true se o valor é um caractere especial de digitação HTTP.
             **/
            bool isTypingSpecial(int value);

            /**
             * @return Retorna true se o valor é carectere dígito.
             **/
            bool isDigit(int value);
        }
    }

    namespace util
    {
        /**
         * Limita um determinado valor.
         * @param value O valor que será limitado.
         * @param upper O valor máximo.
         * @param min O valor mínimo.
         * @return O valor limitado.
         **/
        int clamp(int value, int lower, int upper);

        /**
         * Limita o valor lido em um ADC.
         * @param value O valor de entrada.
         * @return O valor limitado.
         **/
        int clampADC(int value);
        
        /**
         * Lê um arquivo e retorna o conteúdo.
         * @param path O arquivo que será lido.
         * @return O conteúdo do arquivo.
         **/
        std::string getFileContent(const std::string& path);
        
        /**
         * Escreve um arquivo.
         * @param path O diretório de escrita.
         * @param content O conteúdo de escrita.
         * @return Retorna true se tudo ocorrer como esperado.
         **/
        bool writeFileContent(const std::string& path, const std::string& content);
    }
}

#endif
