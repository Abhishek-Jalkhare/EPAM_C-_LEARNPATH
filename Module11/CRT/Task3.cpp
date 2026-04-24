#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    const int N = 10;
    int* pointers[N];

    for (int i = 0; i < N; ++i) {
        pointers[i] = new int(i * 10);
    }

    // Intentionally delete only even-indexed objects
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            delete pointers[i];
            pointers[i] = nullptr;
        }
        // Odd-indexed objects are purposely not deleted (leaked)
    }

    return 0; // Leaks for odd-indexed allocations
}


//Output for crt : 
/*Detected memory leaks!
Dumping objects ->
{93} normal block at 0x000002063C27D500, 4 bytes long.
 Data: <Z   > 5A 00 00 00 
{91} normal block at 0x000002063C27D4C0, 4 bytes long.
 Data: <F   > 46 00 00 00 
{89} normal block at 0x000002063C27DEC0, 4 bytes long.
 Data: <2   > 32 00 00 00 
{87} normal block at 0x000002063C26AA70, 4 bytes long.
 Data: <    > 1E 00 00 00 
{85} normal block at 0x000002063C26B070, 4 bytes long.v
 Data: <    > 0A 00 00 00 
Object dump complete. */