//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>

std::atomic<bool> ready{false};
int data = 0;

void A() {
    data = 42;
    ready.store(true , std::memory_order_release); // this ensures all operations
    // before this store are visible to other threads that acquire the same atomic variable
}

void B() {
    while (!ready.load(std::memory_order_acquire)) { //this ensures that all operations after this
        //load will see the effects of operations before the corresponding store in thread A

        // wait
    }
    std::cout<<"Data : "<<data<<std::endl;
}

int main(int argc, char *argv[]) {
    std::thread t1(A);
    std::thread t2(B);

    t1.join();
    t2.join();

    return 0;
}
