#if !defined(ILOG_CORE_H)
#define ILOG_CORE_H

#if defined(_WIN32)
#if defined(ILOG_DLL)
#if defined(ILOG_BUILD_DLL)
#define ILOG_API __declspec(dllexport)
#else 
#define ILOG_API __declspec(dllimport)
#endif
#else
#define ILOG_API
#endif
#endif

#endif