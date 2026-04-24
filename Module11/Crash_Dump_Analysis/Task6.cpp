//
// Created by AbhishekJalkhare on 22-04-2026.
//
//
// Created by AbhishekJalkhare on 21-04-2026.
//
// div_by_zero.cpp
#include <iostream>
int main() {
    int a = 10 / 0; // Division by zero
    std::cout << "Result: " << a << std::endl;
    return 0;
}
/*gdb) run
Starting program: C:\CPP_DEV\Module11\Crash_Dump_Analysis\Task6.exe
[New Thread 36252.0xa8f8]
[New Thread 36252.0x2fd4]
[New Thread 36252.0x9b98]

Thread 1 received signal SIGFPE, Arithmetic exception.
0x00007ff6ed1b15f8 in main () at Task6.cpp:7
7           int a = 10 / 0; // Division by zero
(gdb) bt
#0  0x00007ff6ed1b15f8 in main () at Task6.cpp:7
(gdb) l
2       // Created by AbhishekJalkhare on 21-04-2026.
3       //
4       // div_by_zero.cpp
5       #include <iostream>
6       int main() {
7           int a = 10 / 0; // Division by zero
8           std::cout << "Result: " << a << std::endl;
9           return 0;
10      } */