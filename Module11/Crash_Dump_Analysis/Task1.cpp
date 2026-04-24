
 //
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
int main() {
    int* ptr = nullptr;
    *ptr = 10; // Deliberate null pointer dereference
    return 0;
}

// compile :g++ -g -o crash_nullptr crash_nullptr.cpp
// observe crash : ./crash_nullptr
// # Output: Segmentation fault (core dumped)
//
// Debug:
//
//
// gdb ./crash_nullptr
// (gdb) run
// # Program received signal SIGSEGV, Segmentation fault.
// (gdb) bt   # backtrace to show call stack
// (gdb) l    # list to show source at the crash