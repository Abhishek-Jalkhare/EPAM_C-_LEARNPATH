#ifndef CONFIG_H
    #define CONFIG_H
    #define VERSION 4
    #if VERSION >= 3
        #define CHECKVERSION() cout<<"Stable Version";
    #else 
        #define CHECKVERSION() cout<<"Beta Version"; 
    #endif

#endif