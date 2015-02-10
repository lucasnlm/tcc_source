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

#ifndef BASE64_HPP_INCLUDED
#define BASE64_HPP_INCLUDED

#include <string>
#include <cstdlib>

namespace controller
{
    namespace base64
    {
        /**
         * Codifica uma mensagem em base64.
         * @param msg A mensagem que será codificada.
         * @return Retorna a mensagem codificada em base64.
         **/
        std::string encode(const std::string& msg);
        
        /**
         * Codifica um login e uma senha para base64.
         * @param login O login que será codifica.
         * @param pass A senha que será codifica.
         * @return Retorna os valores em codificados em base64.
         **/
        std::string encodeAccount(const std::string& login,
                                  const std::string& pass);
        
        /**
         * Decodifica um login e uma senha em base64.
         * @param encoded O valor que será decodifica.
         * @return Retorna os valores decodificados em forma de "login:senha".
         **/
        std::string decode(const std::string& encoded);
    }
}

#endif