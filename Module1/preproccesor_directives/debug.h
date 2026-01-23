#pragma once


#if defined(DEBUG)
    #define DEBUG_PRINT(x) (std::cout<<"debuggmode")

#else 
    #define DEBUG_PRINT(x)(std::cout<<"not debugmode")

#endif