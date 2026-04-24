//
// Created by AbhishekJalkhare on 23-04-2026.
//
// uninit_demo.cpp
#include <iostream>
int main() {
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " "; // UNINITIALIZED READ!
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}
/*
 * ==8870== Memcheck, a memory error detector
==8870== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==8870== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==8870== Command: ./Task9
==8870==
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A5A7D: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870== Use of uninitialised value of size 8
==8870==    at 0x49A595B: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49A5AA7: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A596D: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49A5AA7: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A5ADC: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
0 0 0 0 0
==8870==
==8870== HEAP SUMMARY:
==8870==     in use at exit: 0 bytes in 0 blocks
==8870==   total heap usage: 3 allocs, 3 frees, 74,772 bytes allocated
==8870==
==8870== All heap blocks were freed -- no leaks are possible
==8870==
==8870== ERROR SUMMARY: 20 errors from 4 contexts (suppressed: 0 from 0)
==8870==
==8870== 5 errors in context 1 of 4:
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A5ADC: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870==
==8870== 5 errors in context 2 of 4:
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A596D: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49A5AA7: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870==
==8870== 5 errors in context 3 of 4:
==8870== Use of uninitialised value of size 8
==8870==    at 0x49A595B: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49A5AA7: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
==8870==
==8870== 5 errors in context 4 of 4:
==8870== Conditional jump or move depends on uninitialised value(s)
==8870==    at 0x49A5A7D: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x49B63C1: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
==8870==    by 0x109212: main (Task9.cpp:9)
==8870==  Uninitialised value was created by a heap allocation
==8870==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8870==    by 0x1091DE: main (Task9.cpp:7)
==8870==
 */