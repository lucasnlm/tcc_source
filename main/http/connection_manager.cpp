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
