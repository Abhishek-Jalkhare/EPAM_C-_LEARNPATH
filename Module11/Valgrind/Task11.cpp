//
// Created by AbhishekJalkhare on 23-04-2026.
//
#include <vector>
#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    std::vector<int*> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(new int(i * 10));
    }
    // v.clear(); // or let v go out of scope
    // No deletes—memory leak!
    return 0;
}
/*
* ==10190== Memcheck, a memory error detector
==10190== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==10190== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==10190== Command: ./Task11
==10190==
==10190==
==10190== HEAP SUMMARY:
==10190==     in use at exit: 40 bytes in 10 blocks
==10190==   total heap usage: 16 allocs, 6 frees, 74,016 bytes allocated
==10190==
==10190== 40 bytes in 10 blocks are definitely lost in loss record 1 of 1
==10190==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10190==    by 0x109267: main (Task11.cpp:16)
==10190==
==10190== LEAK SUMMARY:
==10190==    definitely lost: 40 bytes in 10 blocks
==10190==    indirectly lost: 0 bytes in 0 blocks
==10190==      possibly lost: 0 bytes in 0 blocks
==10190==    still reachable: 0 bytes in 0 blocks
==10190==         suppressed: 0 bytes in 0 blocks
==10190==
==10190== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */