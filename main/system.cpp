#include "system.hpp"
#include "util.hpp"

#include <cstdlib>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>

namespace controller
{
    int System::getPID()
    {
        return static_cast<int>(getpid());
    }
    
    void System::setPriority(int priority)
    {
        priority = util::clamp(priority, -20, 20);
        
        id_t pid = getpid();
        setpriority(PRIO_PROCESS, pid, priority);
    }
    
    int System::getPriority()
    {
        id_t pid = getpid();
        return getpriority(PRIO_PROCESS, pid);
    }
    
    void System::reboot()
    {
        system("shutdown -r now");
    }
    
    void System::shutdown()
    {
        system("poweroff");
    }
}
