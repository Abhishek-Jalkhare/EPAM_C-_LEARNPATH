//
// Created by AbhishekJalkhare on 02-04-2026.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

int counter = 0;
mutex mt;
void fun() {
    for (int i = 0; i < 1000; i++) {
        lock_guard<mutex> lg(mt);
        counter++;
    }
}

int main(int argc, char* argv[]) {
    vector<thread> threads;

    for (int i = 0; i < 4; i++) {
        threads.emplace_back(fun);
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "Final counter value : " << counter << "\n\n";


    return 0;
}