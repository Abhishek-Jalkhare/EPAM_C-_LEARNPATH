//
// Created by AbhishekJalkhare on 24-04-2026.
//
#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <crtdbg.h>
#endif

void mayThrow(bool doThrow) {
    int* data = new int[100];
    if (doThrow)
        throw std::runtime_error("Boom!");
    delete[] data; // Only called if no exception
}

// fix
/*void mayThrow(bool doThrow) {
    std::unique_ptr<int[]> data(new int[100]);
    if (doThrow)
        throw std::runtime_error("Boom!");
    // Memory is automatically freed—even if exception is thrown!
}*/

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    try {
        mayThrow(true);  // This leaks
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

/*abhishekjalkhare@EPINHYDW180A:~/CPP_DEV_LINUX/Valgrind$ valgrind -s --leak-check=full ./Task14
==11033== Memcheck, a memory error detector
==11033== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==11033== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==11033== Command: ./Task14
==11033==
Caught exception: Boom!
==11033==
==11033== HEAP SUMMARY:
==11033==     in use at exit: 400 bytes in 1 blocks
==11033==   total heap usage: 5 allocs, 4 frees, 75,326 bytes allocated
==11033==
==11033== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==11033==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11033==    by 0x1092A6: mayThrow(bool) (Task14.cpp:11)
==11033==    by 0x10933B: main (Task14.cpp:30)
==11033==
==11033== LEAK SUMMARY:
==11033==    definitely lost: 400 bytes in 1 blocks
==11033==    indirectly lost: 0 bytes in 0 blocks
==11033==      possibly lost: 0 bytes in 0 blocks
==11033==    still reachable: 0 bytes in 0 blocks
==11033==         suppressed: 0 bytes in 0 blocks
==11033==
==11033== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)*/
