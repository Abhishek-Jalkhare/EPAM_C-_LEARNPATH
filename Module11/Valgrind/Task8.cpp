//
// Created by AbhishekJalkhare on 23-04-2026.
//
// leak_demo.cpp
#include <iostream>
int main() {
    int* arr = new int[100]; // Leaked memory
    // no delete[] arr;
    return 0;
}
/*==8181== Memcheck, a memory error detector
==8181== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==8181== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==8181== Command: ./Task8
==8181==
==8181==
==8181== HEAP SUMMARY:
==8181==     in use at exit: 400 bytes in 1 blocks
==8181==   total heap usage: 2 allocs, 1 frees, 74,128 bytes allocated
==8181==
==8181== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8181==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8181==    by 0x10915E: main (Task8.cpp:7)
==8181==
==8181== LEAK SUMMARY:
==8181==    definitely lost: 400 bytes in 1 blocks
==8181==    indirectly lost: 0 bytes in 0 blocks
==8181==      possibly lost: 0 bytes in 0 blocks
==8181==    still reachable: 0 bytes in 0 blocks
==8181==         suppressed: 0 bytes in 0 blocks
==8181==
==8181== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)*/