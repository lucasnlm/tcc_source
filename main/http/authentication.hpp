#ifndef AUTHENTICATION_HPP_INCLUDED
#define AUTHENTICATION_HPP_INCLUDED

#include <string>

namespace controller
{
    namespace http
    {
        class Connection;
        
        /**
         * @return Retorna o código de autenticação em Base64.
         **/
        const std::string& getAuthentication();
        
        /**
         * Dada a reposta HTTP verifica possui autenticação.
         * Se tiver, autentica conexão.
         * 
         * @param conn A conexão que será verificada e ativada.
         * @param msg A mensagem que será verificada.
         **/
        void checkAuthentication(Connection* conn, const std::string& msg);
    }
}

#endif
