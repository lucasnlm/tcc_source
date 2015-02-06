#ifndef HTTP_CONNECTION_MANAGER_HPP
#define HTTP_CONNECTION_MANAGER_HPP

#include <set>
#include <mutex>

#include "connection.hpp"

namespace controller 
{
    namespace http 
    { 
        /**
         * Descreve o gerenciador de conexões.
         **/
        class ConnectionManager
        {
            public:
                // Cancela construtores de cópia e atribuição.
                ConnectionManager(const ConnectionManager&) = delete;
                ConnectionManager& operator=(const ConnectionManager&) = delete;

                /**
                 * Construtor.
                 **/
                ConnectionManager();

                /**
                 * Adiciona uma nova conexão a lista.
                 **/
                void start(connection_ptr c);

                /**
                 * Para uma conexão.
                 **/
                void stop(connection_ptr c);

                /**
                 * Para todas as conexões.
                 **/
                void stopAll();
                
                /**
                 * A quantida de conexões cadastradas.
                 **/
                size_t count() const
                {
                    return connections.size();
                }
                
                void checkLife();

            private:
                // A lista de conexões.
                std::set<connection_ptr> connections;
                
                // Mutex utilizada nas funções de manipulação do std::set.
                std::mutex mtx;
        };
} }


#endif // HTTP_CONNECTION_MANAGER_HPP
