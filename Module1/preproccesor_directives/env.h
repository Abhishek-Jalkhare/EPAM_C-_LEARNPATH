#pragma once

#if defined(DEV) 
    #define API_URL "http://localhost"

#elif defined(TEST)
    #define API_URL "http://test-server"

#else
    #define API_URL "http://prod-server"

#endif
