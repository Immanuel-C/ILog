{{#title Loging to files in ILog}}

# Loging to files in ILog

Loging to files is easy and simple with ILog.
There is two ways you can log to a file.

1. You can pass in your own ```FILE*``` into the ```I_FS_LOG();``` macro.
The ```I_FS_LOG();``` macro takes in a ```FILE*``` or an "std stream" like stdout, a message and then variable args (for formating the message).

2. You could let ILog handle the file creation and deletion with the ```I_FILE_LOG();``` macro. The ```I_FILE_LOG();``` macro takes in a file names, a message, a mode and variable args. Most of the parameters are self explanitory except the mode parameter. The mode parameter corresponds with the ```fopen();``` mode parameter (e.g. "w" for write, "a" for appened, etc.). To learn more about this check out this tutorial by [programiz](https://www.programiz.com/cpp-programming/library-function/cstdio/fopen) to learn more.

Code example:

```c
#include <ILog.h>

int main() 
{
    I_FILE_LOG("example.log", "%d World Hello! %d", "w", 5, 6);
    
    FILE* file;

    file = fopen("example.log", "a"); // You should error check
    I_FS_LOG(file, "Hello World! %d", 10);

    return 0;
}
```

Output:

![example.log](images/fileLogingExample.png)