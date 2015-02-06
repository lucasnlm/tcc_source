#ifndef HTTP_MIME_TYPES_HPP
#define HTTP_MIME_TYPES_HPP

#include <string>

namespace controller 
{ 
    namespace http 
    {
        /**
         * Retorna o tipo em formato MIME dada a extensão do arquivo.
         * @param extension A extensão do arquivo.
         * @return Retorna em formato MIME.
         **/
        const std::string& extensionToType(const std::string& extension);
    } 
}

#endif // HTTP_MIME_TYPES_HPP
