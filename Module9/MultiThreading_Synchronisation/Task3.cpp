#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int counter = 0;

void fun() {
    for (int i = 0; i < 1000; i++) {
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

    cout << "--- Observation & Explanation ---\n";
    cout << "The final result is often less than 4000 due to a race condition. "
         << "The operation 'counter++' is not atomic; it consists of reading the value, "
         << "incrementing it, and writing it back to memory. Without synchronization, "
         << "multiple threads may read the same initial value, increment it, and write it "
         << "back simultaneously, effectively overwriting each other's increments.\n\n";

    cout << "To fix this issue, you can protect the 'counter++' operation with a "
         << "'std::mutex' to ensure mutually exclusive access, or change the variable "
         << "declaration to an atomic type like 'std::atomic<int> counter = 0;'.\n";

    return 0;
}