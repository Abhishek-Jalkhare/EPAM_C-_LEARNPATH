//
// Created by AbhishekJalkhare on 24-04-2026.
//
#include <vector>
#include <memory>     // for std::unique_ptr
#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    std::vector<int *> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(new int(i*10));
    }

    std::vector<std::unique_ptr<int>> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(std::make_unique<int>(i * 10));
    }
    // No need to manually delete; unique_ptr will release memory automatically.
    std::vector<std::shared_ptr<int>> v3;
    for (int i = 0; i < 10; ++i) {
        v3.push_back(std::make_shared<int>(i * 10));
    }
    return 0;
}



/*
* ==10859== Memcheck, a memory error detector
==10859== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==10859== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==10859== Command: ./Task12
==10859==
==10859==
==10859== HEAP SUMMARY:
==10859==     in use at exit: 40 bytes in 10 blocks
==10859==   total heap usage: 46 allocs, 36 frees, 75,040 bytes allocated
==10859==
==10859== 40 bytes in 10 blocks are definitely lost in loss record 1 of 1
==10859==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10859==    by 0x10928D: main (Task12.cpp:17)
==10859==
==10859== LEAK SUMMARY:
==10859==    definitely lost: 40 bytes in 10 blocks
==10859==    indirectly lost: 0 bytes in 0 blocks
==10859==      possibly lost: 0 bytes in 0 blocks
==10859==    still reachable: 0 bytes in 0 blocks
==10859==         suppressed: 0 bytes in 0 blocks
==10859==
==10859== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */