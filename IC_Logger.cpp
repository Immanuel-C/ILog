#include "IC_Logger.h"


#ifdef _WIN32
    void _platformLog(const char* msg, ConsoleColour colour) {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        uint32_t colourBits = 0;

        switch (colour) {
            case ConsoleColour::WHITE: {
                colourBits = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
                break;
            }
            case ConsoleColour::GREEN: {
                colourBits = FOREGROUND_GREEN;
                break;
            }
            case ConsoleColour::YELLOW: {
                colourBits = FOREGROUND_GREEN | FOREGROUND_RED;
                break;
            }
            case ConsoleColour::RED: {
                colourBits = FOREGROUND_RED;
                break;
            }
            case ConsoleColour::FATAL_RED: {
                colourBits = COMMON_LVB_UNDERSCORE | BACKGROUND_RED | BACKGROUND_INTENSITY;
                break;
            }
        };

        SetConsoleTextAttribute(consoleHandle, colourBits);

        WriteConsoleA(consoleHandle, msg, strlen(msg), nullptr, nullptr);

        SetConsoleTextAttribute(consoleHandle, 
        FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }

    void _log(const char* prefix, const char* msg, ConsoleColour colour, ...) {
        char* fmtBuffer = new char[ strlen(prefix) + strlen(msg) ];
        // Copy formated string into the fmtBuffer
        sprintf(fmtBuffer, "%s: %s", prefix, msg);

        va_list args;

        va_start(args, colour);

        // returns the length of the formated string
        // I'm not sure why you have to add one to this but I
        // think _vscprintf doesn't count \0 as a character
        // but vsprintf_s needs that \0 
        size_t msgLen = _vscprintf(fmtBuffer, args) + 1;
        
        char* msgBuffer = new char[msgLen];
        
        // This is different from sprintf becuase it takes in a va_list instead of variable args
        vsprintf_s(msgBuffer, msgLen, fmtBuffer, args);

        va_end(args);

        _platformLog(msgBuffer, colour);

        printf("\n");
    }

#endif

#ifdef __linux__
    #include <string.h>

    void _platformLog(const char* msg, ConsoleColour colour) {
        switch (colour) {
            case ConsoleColour::WHITE: {
                // Check out https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal
                // this is where I found out how this stuff works

                // I think \033 tells linux were trying to create coloured text
                // [1; is for things like bold text, underline, etc
                // 37m is the colour and [0m resets the colour to the default 
                // 4X is for background
                printf("\033[0;37m%s\033[0m", msg);
                break;
            }
            case ConsoleColour::GREEN: {
                printf("\033[0;32m%s\033[0m", msg);
                break;
            }
            case ConsoleColour::YELLOW: {
                printf("\033[0;33m%s\033[0m", msg);
                break;
            }
            case ConsoleColour::RED: {
                printf("\033[0;31m%s\033[0m", msg);
                break;
            }
            case ConsoleColour::FATAL_RED: {
                printf("\033[;41m\033"); // Sets the background to red
                printf("\033[4;30m%s\033[0m", msg);
                break;
            }
        };
    }

    // This is windows only so we have to create our own function for this
    int _vscprintf (const char * format, va_list pargs) { 
      int retval; 
      va_list argcopy; 
      va_copy(argcopy, pargs); 
      retval = vsnprintf(NULL, 0, format, argcopy); 
      va_end(argcopy); 
      return retval; 
   }

    void _log(const char* prefix, const char* msg, ConsoleColour colour, ...) {
        char* fmtBuffer = new char[ strlen(prefix) + strlen(msg) ];
        // Copy formated string into the fmtBuffer
        sprintf(fmtBuffer, "%s: %s", prefix, msg);

        va_list args;

        va_start(args, colour);

        // returns the length of the formated string
        // I'm not sure why you have to add one to this but I
        // think _vscprintf doesn't count \0 as a character
        // but vsprintf_s needs that \0 
        size_t msgLen = _vscprintf(fmtBuffer, args) + 1;
        
        char* msgBuffer = new char[msgLen];
        
        // This is different from sprintf becuase it takes in a va_list instead of variable args
        vsprintf(msgBuffer, fmtBuffer, args);

        va_end(args);

        _platformLog(msgBuffer, colour);

        printf("\n");
    }
#endif // __linux__


