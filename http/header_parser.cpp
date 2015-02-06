#include "header_parser.hpp"
#include "connection.hpp"

#include <iostream>

namespace controller 
{
    namespace http 
    {   
        void processHeaders(Connection* conn, const std::string& msg)
        {
            std::string line, header;
            std::istringstream ss(msg);
            
            std::string rqts;
            std::getline(ss, rqts);

            while (std::getline(ss, line)) 
            {
                std::size_t found = line.find_first_of(":");
                
                if(found != std::string::npos)
                {
                    header = line.substr(0, found);
                }
                else 
                {
                    return;
                }
            }
        }
    } 
}
