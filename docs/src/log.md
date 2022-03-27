{{#title Loging In ILog}}

# Loging in ILog

ILog's main purpose is to make loging with colours easy and simple.
ILog also has loging levels like the error level, the warning level, etc. These do nothing other than make your text a certain colour and have a specific prefix for each level (e.g "Error" for the error level), but it can be useful to quickly figure out if a message is an error or something else. ILog also has a logging levels for debug and optimized modes. 

ILog can also log to files streams with a simple command or create a file and write to it.

# Code Time!

A Loging function takes in a message then variable arguments.
These variable arguments are useful for added variables values to a message. 
You can insert things variables with regular printf formating (e.g. ```%d``` for int's or ```%p``` for pointers).

Example code:

```c
#include <ILog.h>

int main() 
{
    void* info = malloc(2);
    I_LOG_INFO("Hello: %p", info);
    I_LOG_TRACE("Hello: %d", 10);
    I_LOG_WARNING("Hi: %u", 21);
    I_LOG_ERROR(":(%s", ")");
    I_LOG_FATAL_ERROR("! %zu",  100);

    return 0;
}
```

Output:

![Loging Output](images/logPageNonDebugExample.png)

Each ILog macro has a debug equivalent

Example code:

```c
#include <ILog.h>

int main() 
{
    void* info = malloc(2);
    I_DEBUG_LOG_INFO("Hello: %p", info);
    I_DEBUG_LOG_TRACE("Hello: %d", 10);
    I_DEBUG_LOG_WARNING("Hi: %u", 21);
    I_DEBUG_LOG_ERROR(":(%s", ")");
    I_DEBUG_LOG_FATAL_ERROR("! %zu",  100);

    return 0;
}
```

Output:

![Loging Output](images/logPageDebugExample.png)

**The file macros do not have debug equivlilents.**
