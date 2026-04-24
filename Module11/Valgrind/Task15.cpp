//
// Created by AbhishekJalkhare on 24-04-2026.
//
#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <crtdbg.h>
#endif

class A {
    int* arr;
public:
    A(size_t n) { arr = new int[n]; }
    ~A() { delete[] arr; } // Correct
};

class B {
    char* str;
public:
    B(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    ~B() {
        delete[] str;
    } // Leak
};

class C {
    double* data;
public:
    C(int v) { data = new double[10]; }
    ~C() { delete[] data; } // Correct
};

class D {
    int* x;
public:
    D() { x = new int(42); }
    ~D() {
        delete x;
    } // forgot delete x; // Leak
};

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    A a(20);
    B b("hello world");
    C c(10);
    D d;
    return 0;
}
//error message before fix
/*==11159== Memcheck, a memory error detector
==11159== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==11159== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==11159== Command: ./Task15
==11159==
==11159==
==11159== HEAP SUMMARY:
==11159==     in use at exit: 16 bytes in 2 blocks
==11159==   total heap usage: 5 allocs, 3 frees, 73,904 bytes allocated
==11159==
==11159== 4 bytes in 1 blocks are definitely lost in loss record 1 of 2
==11159==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11159==    by 0x10947F: D::D() (Task15.cpp:37)
==11159==    by 0x109288: main (Task15.cpp:48)
==11159==
==11159== 12 bytes in 1 blocks are definitely lost in loss record 2 of 2
==11159==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11159==    by 0x1093D9: B::B(char const*) (Task15.cpp:21)
==11159==    by 0x10926B: main (Task15.cpp:46)
==11159==
==11159== LEAK SUMMARY:
==11159==    definitely lost: 16 bytes in 2 blocks
==11159==    indirectly lost: 0 bytes in 0 blocks
==11159==      possibly lost: 0 bytes in 0 blocks
==11159==    still reachable: 0 bytes in 0 blocks
==11159==         suppressed: 0 bytes in 0 blocks
==11159==
==11159== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)*/