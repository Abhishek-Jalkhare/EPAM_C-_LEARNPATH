//
// Created by AbhishekJalkhare on 28-01-2026.
//
//Write a C++ program that: Defines a class Tracker that overloads operator
//new and operator delete (class Tracker) Prints a message
//each time memory is allocated or freed by Tracker’s new/delete operators (std::cout)
//Allocates multiple Tracker objects using the new operat
//or (dynamic memory allocation) Deliberately omits delete for
//some objects to simulate leaks Counts the number of active allocations; displays the
//count at program termination Reports which memory allocations were not
//freed (extension: counter implementation)

#include <iostream>
using namespace std;


class Tracker {
public:
    inline static int count = 0;
    void* operator new(size_t ){
        void* ptr = malloc(sizeof(Tracker));
        if (!ptr) {
            throw bad_alloc();
        }
        cout<<"Memory Allocated on address : " <<ptr<<" of size : " << sizeof(Tracker) <<endl;
        count++;
        return ptr;
    }

    void operator delete(void * ptr){
        free(ptr);
        count--;
        cout<<"Memory Freed"<<endl;
    }

};

int main(int argc, char *argv[]) {
    Tracker *t1 = new Tracker();
    Tracker *t2 = new Tracker();
    Tracker *t3 = new Tracker();
    Tracker *t4 = new Tracker();
    delete(t4);
    cout<<"number of outstanding allocations:"<<Tracker::count<<endl;

}
