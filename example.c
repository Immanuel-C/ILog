#include "ILog.h"

int main() 
{
    I_FILE_LOG("example.log", "%d World Hello! %f", "w", 5, 6.5f);
    
    FILE* file;

    file = fopen("example.log", "a");
    I_FS_LOG(file, "Hello World! %d", 10);



    return 0;
}