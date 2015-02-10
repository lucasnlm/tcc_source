/**
 * Copyright 2014 Lucas Nunes de Lima
 * 
 * Based on http_server from Christopher M. Kohlhoff (chris at kohlhoff dot com).
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

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>

namespace controller 
{
    namespace http 
    {
        struct Reply;
        struct Request;
        class Connection;

/**
 * Manipulador de Requisições.
 **/
class RequestHandler
{
    public:
        /**
         * Cancela o contrustor de cópia e atribuição.
         **/
        RequestHandler(const RequestHandler&) = delete;
        RequestHandler& operator=(const RequestHandler&) = delete;

        /// Construct with a directory containing files to be served.
        explicit RequestHandler(const std::string& doc_root);

        /// Handle a request and produce a reply.
        void handleRequest(const Connection* conn, const Request& req, Reply& rep);
        
        /**
         * Executa uma função REST.
         * @return Retorna false se não forma uma função REST do controlador.
         **/
        bool call(const Request& req, Reply& rep);

    private:
        /// The directory containing the files to be served.
        std::string doc_root_;

        /// Perform URL-decoding on a string. Returns false if the encoding was
        /// invalid.
        static bool urlDecode(const std::string& in, std::string& out);
};

} } 

#endif // HTTP_REQUEST_HANDLER_HPP