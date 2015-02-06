#include "authentication.hpp"
#include "connection.hpp"
#include "base64.hpp"
#include "util.hpp"

namespace controller
{
    namespace http
    {
        const std::string& getAuthentication(void)
        {
            using namespace controller::util;
            
            static std::string g_pass = []() -> std::string
            {
                std::string pass = getFileContent("http_key.b64");
                
                if(pass.empty())
                {
                    writeFileContent("http_key.b64", "cm9vdDo=");
                    
                    // Se o arquivo da senha não for encontrado,
                    // usa root sem senha.
                    return "cm9vdDo=";
                }
                else
                {
                    return pass;
                }
            }();
            
            return g_pass;
        }

        void checkAuthentication(Connection* conn, const std::string& msg)
        {
            std::string line;
            std::istringstream ss(msg);
            
            std::string base = "Authorization: Basic ";
            
            while (std::getline(ss, line)) 
            {
                if(line.find(base) != std::string::npos)
                {
                    std::string user_pass = line.substr(base.size(), std::string::npos);                

                    if(user_pass.size() != 0)
                    {                                   
                        if(user_pass.find(getAuthentication()) != std::string::npos)
                        {
                            conn->authenticate();
                        }
                        
                        return;
                    }
                }
            }
        }
    }
}
