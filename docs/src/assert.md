{{#title Assertions in ILog}}

# Assertions In ILog

ILog asserts have two levels fatal error and error. 
If an assertion fails it will trigger a debug breakpoint (for debug mode) and ```getchar()``` in optomized buids if you are on windows and using the MSVC or Clang + MSVC standard library. If you aren't then it will call the ```getchar();``` function on debug and optomized modes.

An ILog assert takes in two or more arguments a condition, a message and variable arguments (for formating the message). The message will be printed with the file name and the line the assertion took place on if the assertion fails. The assertion works like an if statment if the statment is true then it the assertion fails, if not then it just continuous.

Code example:

```c
#include <ILog.h>

int main() 
{
    I_ASSERT_ERROR(0, ":)"); // Doesn't fail

    I_ASSERT_ERROR(1, "Oh No!");
    I_ASSERT_FATAL_ERROR(1, "Oh No! %d", 10);

    return 0;
}
```

Output:

![Assert Output](images/assertPageNonDebugExample.png)

Asserts also have debug equivilants.