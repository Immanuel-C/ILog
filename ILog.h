#pragma once

// Github repo link https://github.com/Immanuel-C/ILog
// This library is under the MIT licence 

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>

#ifdef _WIN32
    #include <windows.h>
#endif // _WIN32

#define _I_COLOUR_WHITE 1
#define _I_COLOUR_GREEN 2
#define _I_COLOUR_YELLOW 3
#define _I_COLOUR_RED 4
#define _I_COLOUR_FATAL_RED 5

#if defined(_MSC_VER)
    #define __I_DEBUG_BREAK() __debugbreak();
#else
    #define __I_DEBUG_BREAK() raise(SIGTRAP)

#endif

#ifndef NDEBUG

#define I_DEBUG_LOG_TRACE(msg, ...) _i_log("Debug Trace:", msg, _I_COLOUR_GREEN, __VA_ARGS__)
#define I_DEBUG_LOG_INFO(msg, ...)  _i_log("Debug Info:", msg, _I_COLOUR_WHITE, __VA_ARGS__)
#define I_DEBUG_LOG_WARNING(msg, ...)  _i_log("Debug Warning:", msg, _I_COLOUR_YELLOW, __VA_ARGS__)
#define I_DEBUG_LOG_ERROR(msg, ...)  _i_log("Debug Error:", msg, _I_COLOUR_RED, __VA_ARGS__)
#define I_DEBUG_LOG_FATAL_ERROR(msg, ...)  _i_log("Debug Fatal Error:", msg, _I_COLOUR_FATAL_RED, __VA_ARGS__)

#define I_DEBUG_ASSERT_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Assert Error On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(buf, msg, _I_COLOUR_RED, __VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}


#define I_DEBUG_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                             \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Assert Fatal Error On Line: %u\nIn File: %s\n";                                                                                          \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(buf, msg, _I_COLOUR_FATAL_RED, __VA_ARGS__);                                                                                                                     \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}
                                                    


#else

#define I_DEBUG_LOG_TRACE(msg, ...)
#define I_DEBUG_LOG_INFO(msg, ...)
#define I_DEBUG_LOG_WARNING(msg, ...)
#define I_DEBUG_LOG_ERROR(msg, ...)
#define I_DEBUG_LOG_FATAL_ERROR(msg, ...)

#endif

#define I_LOG_TRACE(msg, ...) _i_log("Trace:", msg, _I_COLOUR_GREEN, __VA_ARGS__)
#define I_LOG_INFO(msg, ...)  _i_log("Info:", msg, _I_COLOUR_WHITE, __VA_ARGS__)
#define I_LOG_WARNING(msg, ...)  _i_log("Warning:", msg, _I_COLOUR_YELLOW, __VA_ARGS__)
#define I_LOG_ERROR(msg, ...)  _i_log("Error:", msg, _I_COLOUR_RED, __VA_ARGS__)
#define I_LOG_FATAL_ERROR(msg, ...)  _i_log("Fatal Error:", msg, _I_COLOUR_FATAL_RED, __VA_ARGS__)

#define I_ASSERT_ERROR(condition, msg, ...)                                                                                                                                         \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Assert Error On Line: %u\nIn File: %s\n";                                                                                                      \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(buf, msg, _I_COLOUR_RED, __VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}                                                       


#define I_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Assert Fatal Error On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(buf, msg, _I_COLOUR_FATAL_RED, __VA_ARGS__);                                                                                                                     \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}



// DO NOT USE
extern void _platformLog(const char* msg, int colour);

// DO NOT USE
extern void _i_log(const char* prefix, const char* msg, int colour, ...);