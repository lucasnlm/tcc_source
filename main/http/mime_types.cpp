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

#include "mime_types.hpp"

namespace controller { namespace http { 

struct Mapping
{
    std::string extension;
    std::string mime_type;
}; 

Mapping mappings[] =
{
    { "htm"  , "text/html" },
    { "html" , "text/html" },
    { "jpg"  , "image/jpeg" },
    { "png"  , "image/png" },
    { "css"  , "text/css" },
    { "svg"  , "image/svg+xml" },
    { "plc"  , "text/plain; charset=utf-8" },
    { "json" , "application/json" },
    { "js"   , "application/javascript" }
};

const std::string& extensionToType(const std::string& extension)
{
    for (const Mapping& m : mappings)
    {
        if (extension == m.extension)
        {
            return m.mime_type;
        }
    }

    static const std::string plain = "text/plain";
    return plain;
}

} } 
