{{#title What is ILog?}}
# What is ILog?

ILog is a library that makes logging and assertion quick and easy.
ILog is a simple library that is beginner friendly.



Code example:
```c
#include <ILog.h>

int main() 
{
    I_LOG_ERROR("Something Happened!");
    // This will only run in unoptimized builds
    I_DEBUG_LOG_ERROR("Another Thing Happened!");

    return 0;
}
```

Console output:

![Example Output](images/frontPageExample.png)

# Important Stuff You Should Know About

Note that the color of the output maybe different because of the theme of your terminal and other factors!

Also note that if your compiler doesn't automatically define ```NDEBUG``` when compiling with optomization on, please define this as ILog depeneds on this define to know when you are not compiling in debug mode. 