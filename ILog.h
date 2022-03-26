#if !defined(ILOG_H)
#define ILOG_H

#if defined(__cplusplus)
extern "C" {
#endif

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

#if defined(_MSC_VER)

#if !defined(NDEBUG)

#define I_DEBUG_LOG_TRACE(msg, ...) _i_log(stdout, "Debug Trace: ", msg, _I_COLOUR_GREEN, __VA_ARGS__)
#define I_DEBUG_LOG_INFO(msg, ...)  _i_log(stdout, "Debug Info: ", msg, _I_COLOUR_WHITE, __VA_ARGS__)
#define I_DEBUG_LOG_WARNING(msg, ...)  _i_log(stdout, "Debug Warning: ", msg, _I_COLOUR_YELLOW, __VA_ARGS__)
#define I_DEBUG_LOG_ERROR(msg, ...)  _i_log(stderr, "Debug Error: ", msg, _I_COLOUR_RED, __VA_ARGS__)
#define I_DEBUG_LOG_FATAL_ERROR(msg, ...)  _i_log(stderr, "Debug Fatal Error: ", msg, _I_COLOUR_FATAL_RED, __VA_ARGS__)

#define I_DEBUG_FILE_LOG(fileName, msg, mode, ...) _f_i_log(fileName, msg, mode, __VA_ARGS__)
#define I_DEBUG_FS_LOG(stream, msg, ...) i_log(stream, msg, __VA_ARGS__)

#define I_DEBUG_ASSERT_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_RED, __VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}


#define I_DEBUG_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                             \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Fatal Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                          \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_FATAL_RED, __VA_ARGS__);                                                                                                                     \
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

#define I_DEBUG_ASSERT_ERROR(condition, msg, ...)                                                                                                                                   

#define I_DEBUG_ASSERT_FATAL_ERROR(condition, msg, ...)     

#define I_DEBUG_FILE_LOG(fileName, msg, ...)
#define I_DEBUG_FS_LOG(stream, msg, ...)


#endif

#define I_LOG_TRACE(msg, ...) _i_log(stdout, "Trace: ", msg, _I_COLOUR_GREEN, __VA_ARGS__)
#define I_LOG_INFO(msg, ...)  _i_log(stdout, "Info: ", msg, _I_COLOUR_WHITE, __VA_ARGS__)
#define I_LOG_WARNING(msg, ...)  _i_log(stdout, "Warning: ", msg, _I_COLOUR_YELLOW, __VA_ARGS__)
#define I_LOG_ERROR(msg, ...)  _i_log(stderr, "Error: ", msg, _I_COLOUR_RED, __VA_ARGS__)
#define I_LOG_FATAL_ERROR(msg, ...)  _i_log(stderr, "Fatal Error: ", msg, _I_COLOUR_FATAL_RED,  __VA_ARGS__)

#define I_FILE_LOG(fileName, msg, mode, ...) _f_i_log(fileName, msg, mode, __VA_ARGS__)
#define I_FS_LOG(stream, msg, ...) i_log(stream, msg, __VA_ARGS__)


#define I_ASSERT_ERROR(condition, msg, ...)                                                                                                                                         \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                      \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_RED, __VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}                                                       


#define I_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Fatal Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_FATAL_RED, __VA_ARGS__);                                                                                                                     \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}

#else

#if !defined(NDEBUG)

#define I_DEBUG_LOG_TRACE(msg, ...) _i_log(stdout, "Debug Trace: ", msg, _I_COLOUR_GREEN, ##__VA_ARGS__)
#define I_DEBUG_LOG_INFO(msg, ...)  _i_log(stdout, "Debug Info: ", msg, _I_COLOUR_WHITE, ##__VA_ARGS__)
#define I_DEBUG_LOG_WARNING(msg, ...)  _i_log(stdout, "Debug Warning: ", msg, _I_COLOUR_YELLOW, ##__VA_ARGS__)
#define I_DEBUG_LOG_ERROR(msg, ...)  _i_log(stderr, "Debug Error: ", msg, _I_COLOUR_RED, ##__VA_ARGS__)
#define I_DEBUG_LOG_FATAL_ERROR(msg, ...)  _i_log(stderr, "Debug Fatal Error: ", msg, _I_COLOUR_FATAL_RED, ##__VA_ARGS__)

#define I_DEBUG_FILE_LOG(fileName, msg, mode, ...) _f_i_log(fileName, msg, mode, ##__VA_ARGS__)
#define I_DEBUG_FS_LOG(stream, msg, ...) i_log(stream, msg, ##__VA_ARGS__)

#define I_DEBUG_ASSERT_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_RED, ##__VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}


#define I_DEBUG_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                             \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Debug Fatal Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                          \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_FATAL_RED, ##__VA_ARGS__);                                                                                                                     \
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

#define I_DEBUG_ASSERT_ERROR(condition, msg, ...)                                                                                                                                   

#define I_DEBUG_ASSERT_FATAL_ERROR(condition, msg, ...)     

#define I_DEBUG_FILE_LOG(fileName, msg, ...)
#define I_DEBUG_FS_LOG(stream, msg, ...)


#endif

#define I_LOG_TRACE(msg, ...) _i_log(stdout, "Trace: ", msg, _I_COLOUR_GREEN, ##__VA_ARGS__)
#define I_LOG_INFO(msg, ...)  _i_log(stdout, "Info: ", msg, _I_COLOUR_WHITE, ##__VA_ARGS__)
#define I_LOG_WARNING(msg, ...)  _i_log(stdout, "Warning: ", msg, _I_COLOUR_YELLOW, ##__VA_ARGS__)
#define I_LOG_ERROR(msg, ...)  _i_log(stderr, "Error: ", msg, _I_COLOUR_RED, ##__VA_ARGS__)
#define I_LOG_FATAL_ERROR(msg, ...)  _i_log(stderr, "Fatal Error: ", msg, _I_COLOUR_FATAL_RED, ##__VA_ARGS__)

#define I_FILE_LOG(fileName, msg, mode, ...) _f_i_log(fileName, msg, mode, ##__VA_ARGS__)
#define I_FS_LOG(stream, msg, ...) i_log(stream, msg, ##__VA_ARGS__)


#define I_ASSERT_ERROR(condition, msg, ...)                                                                                                                                         \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                      \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                   \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_RED, ##__VA_ARGS__);                                                                                                                           \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}                                                       


#define I_ASSERT_FATAL_ERROR(condition, msg, ...)                                                                                                                                   \
{                                                                                                                                                                                   \
        if(condition)                                                                                                                                                              \
        {                                                                                                                                                                           \
            const char* prefixMsg = "Fatal Error: Assertion Failed On Line: %u\nIn File: %s\n";                                                                                                \
            char* buf = (char*)malloc(strlen(prefixMsg) * sizeof(char) + strlen(__FILE__) * sizeof(char) + sizeof(unsigned int));                                                         \
            sprintf(buf, prefixMsg, (unsigned int)(__LINE__), __FILE__);                                                                                                            \
            _i_log(stderr, buf, msg, _I_COLOUR_FATAL_RED, ##__VA_ARGS__);                                                                                                                     \
            free(buf);                                                                                                                                                              \
            __I_DEBUG_BREAK();                                                                                                                                                      \
        }                                                                                                                                                                           \
}

#endif



// DO NOT USE
extern void _platformLog(FILE* stream, const char* msg, int colour);

// DO NOT USE
extern void _i_log(FILE* stream, const char* prefix, const char* msg, int colour, ...);
// DO NOT USE
extern void _f_i_log(const char* fileName, const char* msg, const char* mode, ...);

#endif

#if defined(__cplusplus)
}
#endif