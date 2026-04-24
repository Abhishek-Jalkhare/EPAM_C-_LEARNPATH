//
// Created by AbhishekJalkhare on 22-04-2026.
//
// access_violation.cpp
#include <iostream>
int main() {
    int* ptr = nullptr;
    {
        int local = 42;
        ptr = &local;
    } // local goes out of scope, ptr now dangling
    std::cout << *ptr << std::endl; // Access violation/undefined behavior!
    return 0;
}
// Compile with Debug Info
//
// g++ -g -o access_violation access_violation.cpp
// Run and Observe
//
// ./access_violation
// # Possible outcomes:
// # - Segmentation fault (core dumped)
// # - Garbage value (undefined behavior)
// Crash Analysis with GDB
//
// gdb ./access_violation
// (gdb) run
// # Program crashes or shows unexpected output
// (gdb) bt   # Backtrace
// (gdb) l    # List source at error