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
