//
// Created by AbhishekJalkhare on 24-04-2026.
//
#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    for (int i = 0; i < 100; ++i) {
        int* arr = new int[1000];
        // No delete[] arr;  // Intentional leak!
    }
    return 0;
}
/*==10949== Memcheck, a memory error detector
==10949== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==10949== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==10949== Command: ./Task13
==10949==
==10949==
==10949== HEAP SUMMARY:
==10949==     in use at exit: 400,000 bytes in 100 blocks
==10949==   total heap usage: 101 allocs, 1 frees, 473,728 bytes allocated
==10949==
==10949== 400,000 bytes in 100 blocks are definitely lost in loss record 1 of 1
==10949==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10949==    by 0x109167: main (Task13.cpp:14)
==10949==
==10949== LEAK SUMMARY:
==10949==    definitely lost: 400,000 bytes in 100 blocks
==10949==    indirectly lost: 0 bytes in 0 blocks
==10949==      possibly lost: 0 bytes in 0 blocks
==10949==    still reachable: 0 bytes in 0 blocks
==10949==         suppressed: 0 bytes in 0 blocks
==10949==
==10949== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)*/