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
