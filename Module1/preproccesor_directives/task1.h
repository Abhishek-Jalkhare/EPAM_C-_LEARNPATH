#ifndef PLATFORM_H
    #define PLATFORM_H
    #if defined(_WIN32 ) || defined(_WIN64)
        #define PLATFORM "Windows"

    #elif defined (__linux__)
        #define PLATFORM "Linux"

    #elif defined(__APPLE__) || defined(__MACH__)
        #define PLATFORM "macOS"

    #else
        #define PLATFORM "other"
    #endif
#endif
