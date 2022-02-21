#include "IC_Logger.h"

#ifdef __linux__
    #include <string.h>
#endif

void _platformLog(const char* msg, int colour) {
        switch (colour) {
            case _IC_COLOUR_WHITE: {
                // Check out https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal
                // this is where I found out how this stuff works
                printf("\033[0;37m%s\033[0m", msg);
                break;
            }
            case _IC_COLOUR_GREEN: {
                printf("\033[0;32m%s\033[0m", msg);
                break;
            }
            case _IC_COLOUR_YELLOW: {
                printf("\033[0;33m%s\033[0m", msg);
                break;
            }
            case _IC_COLOUR_RED: {
                printf("\033[0;31m%s\033[0m", msg);
                break;
            }
            case _IC_COLOUR_FATAL_RED: {
                printf("\033[;41m\033"); // Sets the background to red
                printf("\033[4;30m%s\033[0m", msg);
                break;
        }
    };
}

int _ic_vscprintf (const char * format, va_list pargs) { 
    int retval; 
    va_list argcopy; 
    va_copy(argcopy, pargs); 
    retval = vsnprintf(NULL, 0, format, argcopy); 
    va_end(argcopy); 
    return retval; 
}   

void _log(const char* prefix, const char* msg, int colour, ...) {
    //char* fmtBuffer = new char[ strlen(prefix) + strlen(msg) ];
    char* fmtBuffer = (char*)malloc( strlen(prefix) * sizeof(char) + strlen(msg) * sizeof(char) );
    // Copy formated string into the fmtBuffer
    sprintf(fmtBuffer, "%s: %s", prefix, msg);

    va_list args;

    va_start(args, colour);

    // returns the length of the formated string
    // I'm not sure why you have to add 1 to this but I
    // think _vscprintf and _ic_vscprintf doesn't count \0 as a character
    // but vsprintf_s and vsprintf_s needs that \0 
    size_t msgLen = _ic_vscprintf(fmtBuffer, args) + 1;
    
    //char* msgBuffer = new char[msgLen];
    char* msgBuffer = (char*)malloc( msgLen * sizeof(char) );
    
    // This is different from sprintf becuase it takes in a va_list instead of variable args
    #if defined(_WIN32) && defined(_MSVC_VER) || defined(_WIN32) && defined(__clang__)
        vsprintf_s(msgBuffer, msgLen, fmtBuffer, args);
    #else
        // MSVC complains about this function being depracted
        vsprintf(msgBuffer, fmtBuffer, args);
    #endif 

    va_end(args);

    _platformLog(msgBuffer, colour);

    printf("\n");
}


