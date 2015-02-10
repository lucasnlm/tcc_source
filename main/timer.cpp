/**
 * Copyright 2014 Lucas Nunes de Lima
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

#include "timer.hpp"

#include <chrono>

namespace controller
{
    Timer::Timer()
    {
        this->resetTimer();
    }

    void Timer::resetTimer()
    {
        this->last = Timer::getMiliseconds();
    }

    std::time_t Timer::getDiff() const
    {
        return (Timer::getMiliseconds() - this->last);
    }

    std::time_t Timer::getMiliseconds()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
}
