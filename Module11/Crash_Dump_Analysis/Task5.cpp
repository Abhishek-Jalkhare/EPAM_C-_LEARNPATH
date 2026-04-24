//
// Created by AbhishekJalkhare on 22-04-2026.
//


// use_after_free.cpp
#include <iostream>
int main() {
    int* p = new int(7);
    delete p;
    *p = 42;               // Use-after-free crash or undefined behavior
    std::cout << *p << std::endl;
    return 0;
}


// ./use_after_free
// # May cause a crash (segmentation fault) or print garbage value (undefined)
// Debug in gdb
//
// gdb ./use_after_free
// (gdb) run
// # Program receives SIGSEGV or misbehaves
// (gdb) bt         # Backtrace
// (gdb) l          # List source at crash