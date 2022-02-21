# Ic Logger
The IcLogger is for people who need a simple logger. **Currently for windows and linux only.**
This logger is for C++ only.

This repo is under the MIT license, so you can modify this as much as you want and repost the code.

IC_DEBUG_* is for debug builds only while IC_* is for all builds.

To format things you can use the regular printf format options. (e.g. %p for pointer, %ull for unsigned long long, ...). 

# Compiling with g++

**IMPORTANT:** To compile with g++ on windows you need to change vsprintf_s(msgBuffer, msgLen, fmtBuffer, args); to vsprintf(msgBuffer, fmtBuffer, args); and remove the msgLen param from the function.

I didn't do this myself as clang++ and msvc will complain that vsprintf is depracated.

# Examples

![github image](https://github.com/Imaaaaaaaaaaaaaaan/IcLogger/blob/main/Example.PNG)
