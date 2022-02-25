#pragma once

// Github repo link https://github.com/Imaaaaaaaaaaaaaaan/IcLogger/tree/main
// This library is under the MIT licence 

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#endif // _WIN32

#define _IC_COLOUR_WHITE 1
#define _IC_COLOUR_GREEN 2
#define _IC_COLOUR_YELLOW 3
#define _IC_COLOUR_RED 4
#define _IC_COLOUR_FATAL_RED 5

#ifndef NDEBUG

#define IC_DEBUG_LOG_TRACE(msg, ...) _log("Debug Trace", msg, _IC_COLOUR_GREEN, __VA_ARGS__)
#define IC_DEBUG_LOG_INFO(msg, ...)  _log("Debug Info", msg, _IC_COLOUR_WHITE, __VA_ARGS__)
#define IC_DEBUG_LOG_WARNING(msg, ...)  _log("Debug Warning", msg, _IC_COLOUR_YELLOW, __VA_ARGS__)
#define IC_DEBUG_LOG_ERROR(msg, ...)  _log("Debug Error", msg, _IC_COLOUR_RED, __VA_ARGS__)
#define IC_DEBUG_LOG_FATAL_ERROR(msg, ...)  _log("Debug Fatal Error", msg, _IC_COLOUR_FATAL_RED, __VA_ARGS__)

#else

#define IC_DEBUG_LOG_TRACE(msg, ...)
#define IC_DEBUG_LOG_INFO(msg, ...)
#define IC_DEBUG_LOG_WARNING(msg, ...)
#define IC_DEBUG_LOG_ERROR(msg, ...)
#define IC_DEBUG_LOG_FATAL_ERROR(msg, ...)

#endif

#define IC_LOG_TRACE(msg, ...) _log("Trace", msg, _IC_COLOUR_GREEN, __VA_ARGS__)
#define IC_LOG_INFO(msg, ...)  _log("Info", msg, _IC_COLOUR_WHITE, __VA_ARGS__)
#define IC_LOG_WARNING(msg, ...)  _log("Warning", msg, _IC_COLOUR_YELLOW, __VA_ARGS__)
#define IC_LOG_ERROR(msg, ...)  _log("Error", msg, _IC_COLOUR_RED, __VA_ARGS__)
#define IC_LOG_FATAL_ERROR(msg, ...)  _log("Fatal Error", msg, _IC_COLOUR_FATAL_RED, __VA_ARGS__)


// DO NOT USE
extern void _platformLog(const char* msg, int colour);

// DO NOT USE
extern void _log(const char* prefix, const char* msg, int colour, ...);