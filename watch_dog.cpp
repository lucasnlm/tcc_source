#include "watch_dog.hpp"
#include "timer.hpp"
#include "logger.hpp"

#include <linux/watchdog.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h> 

namespace controller
{
    WatchDog::WatchDog()
    {
        this->fd = -1;
        this->limitTime = 30; // s
    }

    void WatchDog::feed()
    {
        if(!angry)
        {
            ioctl(fd, WDIOC_KEEPALIVE, 0);
        }
    }
    
    void WatchDog::deactivate()
    {
        if(fd > 0)
        {
            write(fd, "V", 1);
            close(fd);
        }
    }
    
    void WatchDog::kick()
    {
        logger.write("Algo inesperado ocorreu. O cão de guarda foi alertado.");
        this->angry = true;
    }
    
    BootStatus WatchDog::readBootStatus()
    {
        if(fd > 0)
        {
            int bootstatus;
            return (ioctl(fd, WDIOC_GETBOOTSTATUS, &bootstatus) == 0) ? WATCH_DOG : POWER_ON_RESET;
        }
        else
        {
            return UNKNOWN;
        }
    }
    
    int WatchDog::readInterval()
    {
        if(fd > 0)
        {
            int interval = -1;
            return (ioctl(fd, WDIOC_GETTIMEOUT, &interval) == 0) ? interval : -1;
        }
        else
        {
            return -1;
        }
     }

    void WatchDog::wakeUp()
    {
        // Once the watchdog device file is open,
        // the watchdog will be activated by the driver 
        fd = open("/dev/watchdog", O_RDWR);
        
        if(fd == -1)
        {
            logger.write("Erro ao acordar cão de guarda.");
            return;
        }
        
        write(fd, "\0", 1);
        
        if(ioctl(fd, WDIOC_SETTIMEOUT, &limitTime) != 0)
        {
            logger.write("Erro ao definir tempo do cão de guarda.");
            return;
        }
        
        
        write(fd, "w", 1);
        ioctl(fd, WDIOC_SETOPTIONS, WDIOS_ENABLECARD);
        
        logger.write("O cão de guarda foi acordado ({0}).", this->readInterval());
    }
}
