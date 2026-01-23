#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

/* Log levels */
#define ERROR 1
#define WARN  2
#define INFO  3
#define DEBUG 4

#ifndef LOG_LEVEL
#define LOG_LEVEL INFO
#endif

#if LOG_LEVEL >= DEBUG

#define LOG(level, msg)                                   \
    do {                                                  \
        if ((level) == ERROR)                             \
            std::cout << "[ERROR] " << msg << std::endl; \
        else if ((level) == WARN)                         \
            std::cout << "[WARN] " << msg << std::endl;  \
        else if ((level) == INFO)                         \
            std::cout << "[INFO] " << msg << std::endl;  \
        else if ((level) == DEBUG)                        \
            std::cout << "[DEBUG] " << msg << std::endl; \
    } while (0)

#elif LOG_LEVEL >= INFO

#define LOG(level, msg)                                   \
    do {                                                  \
        if ((level) == ERROR)                             \
            std::cout << "[ERROR] " << msg << std::endl; \
        else if ((level) == WARN)                         \
            std::cout << "[WARN] " << msg << std::endl;  \
        else if ((level) == INFO)                         \
            std::cout << "[INFO] " << msg << std::endl;  \
    } while (0)

#elif LOG_LEVEL >= WARN

#define LOG(level, msg)                                   \
    do {                                                  \
        if ((level) == ERROR)                             \
            std::cout << "[ERROR] " << msg << std::endl; \
        else if ((level) == WARN)                         \
            std::cout << "[WARN] " << msg << std::endl;  \
    } while (0)

#else 

#define LOG(level, msg)                                   \
    do {                                                  \
        if ((level) == ERROR)                             \
            std::cout << "[ERROR] " << msg << std::endl; \
    } while (0)

#endif

#endif
