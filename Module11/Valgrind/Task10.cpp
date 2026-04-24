//
// Created by AbhishekJalkhare on 23-04-2026.
//
// double_delete.cpp
#include <iostream>
int main() {
    int* ptr = new int(42);
    delete ptr;

     delete ptr;         // Error: double free!

    // Use after free (uncomment to test):
    // std::cout << *ptr << std::endl;  // Error: use after free!

    return 0;
}
/*
* ==9512== Memcheck, a memory error detector
==9512== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9512== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==9512== Command: ./Task10
==9512==
==9512== Invalid free() / delete / delete[] / realloc()
==9512==    at 0x484A61D: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x1091B4: main (Task10.cpp:10)
==9512==  Address 0x4e1d080 is 0 bytes inside a block of size 4 free'd
==9512==    at 0x484A61D: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x10919E: main (Task10.cpp:8)
==9512==  Block was alloc'd at
==9512==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x10917E: main (Task10.cpp:7)
==9512==
==9512==
==9512== HEAP SUMMARY:
==9512==     in use at exit: 0 bytes in 0 blocks
==9512==   total heap usage: 2 allocs, 3 frees, 73,732 bytes allocated
==9512==
==9512== All heap blocks were freed -- no leaks are possible
==9512==
==9512== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
==9512==
==9512== 1 errors in context 1 of 1:
==9512== Invalid free() / delete / delete[] / realloc()
==9512==    at 0x484A61D: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x1091B4: main (Task10.cpp:10)
==9512==  Address 0x4e1d080 is 0 bytes inside a block of size 4 free'd
==9512==    at 0x484A61D: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x10919E: main (Task10.cpp:8)
==9512==  Block was alloc'd at
==9512==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9512==    by 0x10917E: main (Task10.cpp:7)
==9512==
==9512== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */
