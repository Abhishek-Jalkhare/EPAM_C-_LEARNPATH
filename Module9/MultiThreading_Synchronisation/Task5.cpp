//
// Created by AbhishekJalkhare on 02-04-2026.
//

//
// Created by AbhishekJalkhare on 02-04-2026.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

int counter = 0;
mutex mtx;

void incrLockGuard() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

void incrUniqueLock() {
    for (int i = 0; i < 1000; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        ++counter;
        // Could call lock.unlock(), relock(), etc. here if needed.
    }
}



int main(int argc, char* argv[]) {
    vector<thread> threads;

    for (int i = 0; i < 4; i++) {
        threads.emplace_back(incrLockGuard);
    }
    for (int i = 0 ; i < 4 ;i++) {
        threads.emplace_back(incrUniqueLock);
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "Final counter value : " << counter << "\n\n";


    return 0;
}