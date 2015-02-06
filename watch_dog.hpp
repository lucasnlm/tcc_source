#ifndef WATCH_DOG_HPP_INCLUDED
#define WATCH_DOG_HPP_INCLUDED

#include "timer.hpp"

namespace controller
{
    enum BootStatus 
    {
        UNKNOWN = -1,
        WATCH_DOG,
        POWER_ON_RESET
    };
    
    class WatchDog : public Timer
    {
        public:        
            /**
             * Constructor.
             **/
            WatchDog();

            /**
             * Feed the dog.
             **/
            void feed();

            /**
             * Set the limit time to Watch Dog action.
             * @param limitTime the limit time to feed the dog.
             **/
            void setInterval(time_t limitTime);

            /**
             * @return Returns the watch dog limit time.
             ***/
            time_t getInterval() const
            {
                return this->limitTime;
            }

            /**
             * Wake up the watch dog.
             **/
            void wakeUp();
            
            /**
             * Reads the current watch dog interval from drive.
             **/
            int readInterval();

            /**
             * Reads last boot status.
             **/
            BootStatus readBootStatus();
            
            /**
             * Turn off watch dog timer.
             **/
            void deactivate();

            /**
             * Kick the watch dog.
             * System will reset.
             **/
            void kick();

        private:
            // Watchdog timeout interval (in secs)
            time_t limitTime;
            
            // File handler for watchdog
            int fd;
            
            // Watchdog default device file
            char *dev;
            
            bool angry;
    };
}

#endif
