#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <ctime>

namespace controller
{
    class Timer
    {
        public:
            Timer();

            void resetTimer();

            std::time_t getDiff() const;

        private:
            static std::time_t getMiliseconds();

        private:
            std::time_t last;
    };
}

#endif // TIMER_HPP_INCLUDED
