#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>

namespace controller { namespace http { 

struct Header
{
    std::string name;
    std::string value;
};

} } 

#endif // HTTP_HEADER_HPP