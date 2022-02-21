#include "IC_Logger.h"

void _windowsLog(const char* msg, ConsoleColour colour) {
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

    _windowsLog(msgBuffer, colour);

    printf("\n");
}
