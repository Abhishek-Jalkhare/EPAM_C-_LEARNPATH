//
// Created by AbhishekJalkhare on 22-04-2026.
//
//
// Created by AbhishekJalkhare on 21-04-2026.
//
#include <iostream>
void recurse() {
    recurse(); // No base case!
}
int main() {
    recurse();
    return 0;
}
// (gdb) r
// Starting program: C:\CPP_DEV\Module11\Crash_Dump_Analysis\Task4.exe
// [New Thread 27196.0xac70]
// [New Thread 27196.0x7594]
// [New Thread 27196.0x2f68]
//
// Thread 1 received signal SIGSEGV, Segmentation fault.
// recurse () at Task4.cpp:6
// 6           recurse(); // No base case!
//
// (gdb) bt
// #0  recurse () at Task4.cpp:6
// #1  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #2  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #3  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #4  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #5  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #6  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #7  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #8  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #9  0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #10 0x00007ff65e2815ed in recurse () at Task4.cpp:6
// #11 0x00007ff65e2815ed in recurse () at Task4.cpp:6

