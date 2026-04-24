//
// Created by AbhishekJalkhare on 23-04-2026.
//
#include <iostream>
#include <string.h>

class Person {
    char* name;
public:
    Person(const char* nm) {
        size_t len = strlen(nm) + 1;
        name = new char[len];
        strcpy(name, nm);
    }
    // No destructor OR destructor without 'delete[] name' (intentional leak)
    ~Person() { /* missing delete[] name; */ }
    void greet() const {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    Person p1("Alice");
    Person p2("Bob");
    p1.greet();
    p2.greet();
    return 0; // 'name' buffers are leaked!
}
/*CRT OUTPUT
* Detected memory leaks!
Dumping objects ->
{162} normal block at 0x000002022E7AA730, 4 bytes long.
 Data: <Bob > 42 6F 62 00
{161} normal block at 0x000002022E7B1FE0, 6 bytes long.
 Data: <Alice > 41 6C 69 63 65 00
Object dump complete.
The program '[17876] Task4.exe' has exited with code 0 (0x0).
*/

/*
Valgrind Error :
Hello, my name is Alice
Hello, my name is Bob
==7316==
==7316== HEAP SUMMARY:
==7316==     in use at exit: 10 bytes in 2 blocks
==7316==   total heap usage: 4 allocs, 2 frees, 74,762 bytes allocated
==7316==
==7316== 4 bytes in 1 blocks are definitely lost in loss record 1 of 2
==7316==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==7316==    by 0x10931F: Person::Person(char const*) (Task4.cpp:12)
==7316==    by 0x109250: main (Task4.cpp:31)
==7316==
==7316== 6 bytes in 1 blocks are definitely lost in loss record 2 of 2
==7316==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==7316==    by 0x10931F: Person::Person(char const*) (Task4.cpp:12)
==7316==    by 0x10923A: main (Task4.cpp:30)
==7316==
==7316== LEAK SUMMARY:
==7316==    definitely lost: 10 bytes in 2 blocks
==7316==    indirectly lost: 0 bytes in 0 blocks
==7316==      possibly lost: 0 bytes in 0 blocks
==7316==    still reachable: 0 bytes in 0 blocks
==7316==         suppressed: 0 bytes in 0 blocks
==7316==
==7316== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
 */