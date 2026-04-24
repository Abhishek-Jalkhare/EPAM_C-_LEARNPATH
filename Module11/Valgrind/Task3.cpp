//
// Created by AbhishekJalkhare on 23-04-2026.
//
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

// //Output from Valgrind
// abhishekjalkhare@EPINHYDW180A:~/CPP_DEV_LINUX/Valgrind$ valgrind --leak-check=full ./Task3
// ==5571== Memcheck, a memory error detector
// ==5571== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==5571== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==5571== Command: ./Task3
// ==5571==
// ==5571==
// ==5571== HEAP SUMMARY:
// ==5571==     in use at exit: 20 bytes in 5 blocks
// ==5571==   total heap usage: 11 allocs, 6 frees, 73,768 bytes allocated
// ==5571==
// ==5571== 20 bytes in 5 blocks are definitely lost in loss record 1 of 1
// ==5571==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==5571==    by 0x1091BD: main (Task3.cpp:18)
// ==5571==
// ==5571== LEAK SUMMARY:
// ==5571==    definitely lost: 20 bytes in 5 blocks
// ==5571==    indirectly lost: 0 bytes in 0 blocks
// ==5571==      possibly lost: 0 bytes in 0 blocks
// ==5571==    still reachable: 0 bytes in 0 blocks
// ==5571==         suppressed: 0 bytes in 0 blocks
// ==5571==
// ==5571== For lists of detected and suppressed errors, rerun with: -s
// ==5571== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)