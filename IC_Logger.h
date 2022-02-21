#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

#ifdef _WIN32
    #include <windows.h>
#endif // _WIN32


enum struct ConsoleColour {
    WHITE,
    GREEN,
    YELLOW,
    RED,
    FATAL_RED
};

#ifndef NDEBUG

#define IC_DEBUG_LOG_TRACE(msg, ...) _log("Debug Trace", msg, ConsoleColour::GREEN, __VA_ARGS__)
#define IC_DEBUG_LOG_INFO(msg, ...)  _log("Debug Info", msg, ConsoleColour::WHITE, __VA_ARGS__)
#define IC_DEBUG_LOG_WARNING(msg, ...)  _log("Debug Warning", msg, ConsoleColour::YELLOW, __VA_ARGS__)
#define IC_DEBUG_LOG_ERROR(msg, ...)  _log("Debug Error", msg, ConsoleColour::RED, __VA_ARGS__)
#define IC_DEBUG_LOG_FATAL_ERROR(msg, ...)  _log("Debug Fatal Error", msg, ConsoleColour::FATAL_RED, __VA_ARGS__)

#else

#define IC_DEBUG_LOG_TRACE(msg, ...)
#define IC_DEBUG_LOG_INFO(msg, ...)
#define IC_DEBUG_LOG_WARNING(msg, ...)
#define IC_DEBUG_LOG_ERROR(msg, ...)
#define IC_DEBUG_LOG_FATAL_ERROR(msg, ...)

#endif

#define IC_LOG_TRACE(msg, ...) _log("Trace", msg, ConsoleColour::GREEN, __VA_ARGS__)
#define IC_LOG_INFO(msg, ...)  _log("Info", msg, ConsoleColour::WHITE, __VA_ARGS__)
#define IC_LOG_WARNING(msg, ...)  _log("Warning", msg, ConsoleColour::YELLOW, __VA_ARGS__)
#define IC_LOG_ERROR(msg, ...)  _log("Error", msg, ConsoleColour::RED, __VA_ARGS__)
#define IC_LOG_FATAL_ERROR(msg, ...)  _log("Fatal Error", msg, ConsoleColour::FATAL_RED, __VA_ARGS__)


// Do not use
extern void _platformLog(const char* msg, ConsoleColour colour);

// Do not use
extern void _log(const char* prefix, const char* msg, ConsoleColour colour, ...);
