#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i)
        arr[i] = i * 10;

    // Buffer overflow: Write past the end!
    arr[5] = 999; // Undefined behavior—heap corruption!

    delete[] arr;
    return 0;
}

//
//HEAP CORRUPTION DETECTED : after Normal block(#84) at 0x000001A1D6682D70.
//CRT detected that the application wrote to memory after end of heap buffer.
