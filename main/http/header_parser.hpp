#ifndef HEADER_FILTER_HPP
#define HEADER_FILTER_HPP

#include <string>

namespace controller
{
    namespace http
    {
        class Connection;
        
        void processHeaders(Connection* conn, const std::string& msg);
    }
}

#endif
