#include "ILog.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define FILE_OPEN_SUCCESS 0

#ifdef __linux__
    #include <string.h>
#endif

void _platformLog(FILE* stream, const char* msg, int colour) {
        switch (colour) {
            case _I_COLOUR_WHITE: {
                // Check out https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal
                // this is where I found out how this stuff works
                fprintf(stream, "\033[0;37m%s\033[0m", msg);
                break;
            }
            case _I_COLOUR_GREEN: {
                fprintf(stream, "\033[0;32m%s\033[0m", msg);
                break;
            }
            case _I_COLOUR_YELLOW: {
                fprintf(stream, "\033[0;33m%s\033[0m", msg);
                break;
            }
            case _I_COLOUR_RED: {
                fprintf(stream, "\033[0;31m%s\033[0m", msg);
                break;
            }
            case _I_COLOUR_FATAL_RED: {
                fprintf(stream, "\033[;41m\033"); // Sets the background to red
                fprintf(stream, "\033[4;30m%s\033[0m", msg);
                break;
            }
            case 0: {
                fprintf(stream, "%s", msg);
            }
    };
}

int _i_vscprintf (const char * format, va_list pargs) { 
    int retval; 
    va_list argcopy; 
    va_copy(argcopy, pargs); 
    retval = vsnprintf(NULL, 0, format, argcopy); 
    va_end(argcopy); 
    return retval; 
}   

void _i_log(FILE* stream, const char* prefix, const char* msg, int colour, ...) {
    char* fmtBuffer = (char*)malloc( (strlen(prefix) + 1) * sizeof(char) + (strlen(msg) + 1) * sizeof(char) );
    // Copy formated string into the fmtBuffer
    sprintf(fmtBuffer, "%s%s", prefix, msg);

    va_list args;

    va_start(args, colour);

    // returns the length of the formated string
    // I'm not sure why you have to add 1 to this but I
    // think _vscprintf and _i_vscprintf doesn't count \0 as a character
    // but vsprintf_s and vsprintf_s needs that \0 
    size_t msgLen = _i_vscprintf(fmtBuffer, args) + 1;
    
    char* msgBuffer = (char*)malloc( msgLen * 2 * sizeof(char) );
    
    // This is different from sprintf becuase it takes in a va_list instead of variable args
    #if defined(_MSVC_VER) || defined(_WIN32) && defined(__clang__)
        vsprintf_s(msgBuffer, msgLen, fmtBuffer, args);
    #else
        // MSVC complains about this function being depracted
        vsprintf(msgBuffer, fmtBuffer, args);
    #endif 

    va_end(args);

    _platformLog(stream, msgBuffer, colour);

    fprintf(stream, "\n");
    
    free(fmtBuffer);
    free(msgBuffer);
}

void _f_i_log(const char* fileName, const char* msg, const char* mode, ...) {
    va_list args;

    va_start(args, mode);

    // returns the length of the formated string
    // I'm not sure why you have to add 1 to this but I
    // think _vscprintf and _i_vscprintf doesn't count \0 as a character
    // but vsprintf_s and vsprintf_s needs that \0 
    size_t msgLen = _i_vscprintf(msg, args) + 1;
    
    //char* msgBuffer = new char[msgLen];
    char* msgBuffer = (char*)malloc( (msgLen + 1) * sizeof(char) );

    
    // This is different from sprintf becuase it takes in a va_list instead of variable args
    #if defined(_MSVC_VER) || defined(_WIN32) && defined(__clang__)
        vsprintf_s(msgBuffer, msgLen, msg, args);
    #else
        // MSVC complains about this function being depracted
        vsprintf(msgBuffer, msg, args);
    #endif 

    va_end(args);

    FILE* fStream;    

    #if defined(_MSC_VER)
        if (fopen_s(&fStream, fileName, mode) != FILE_OPEN_SUCCESS) {
            fprintf(stderr, "ILog Internal Error: Failed to open file: %s", fileName);
        }
    #else
        fStream = fopen(fileName, mode);
        if (!fStream) {
            fprintf(stderr, "ILog Internal Error: Failed to open file: %s", fileName);
        }
    #endif

    _platformLog(fStream, msgBuffer, 0);


    fprintf(fStream, "\n");
    
    free(msgBuffer);

    fclose(fStream);
}


#if defined(__cplusplus)
}
#endif