#include "connection_manager.hpp"

namespace controller
{
    namespace http 
    { 
        ConnectionManager::ConnectionManager()
        {}

        void ConnectionManager::start(connection_ptr c)
        {
            mtx.lock();
            connections.insert(c);
            c->start();
            mtx.unlock();
        }

        void ConnectionManager::stop(connection_ptr c)
        {
            mtx.lock();
            connections.erase(c);
            c->stop();
            mtx.unlock();
        }
        
        void ConnectionManager::checkLife()
        {
            if(connections.size() > 0u)
            {
                for (auto c : connections)
                {
                    if(c->isTimeOver())
                    {
                        stop(c);
                        return;
                    }
                }
            }
        }

        void ConnectionManager::stopAll()
        {
            for (auto c : connections)
            {
                c->stop();
            }
    
            connections.clear();
        }

    }
} 
