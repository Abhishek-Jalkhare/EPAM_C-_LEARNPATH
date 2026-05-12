//
// Created by AbhishekJalkhare on 14-04-2026.
//
//
// Demonstrating and Fixing a Race Condition
//

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter_race = 0;
int counter_safe = 0;
mutex mtx;

/*
 * WHAT IS A RACE CONDITION?
 * A race condition occurs when multiple threads access and modify shared data
 * at the exact same time without proper synchronization.
 *
 * WHY IT OCCURS:
 * The operation 'counter++' is not atomic. It takes 3 distinct CPU steps:
 * 1. Read the current value from memory.
 * 2. Increment the value.
 * 3. Write the new value back to memory.
 * If Thread A and Thread B read the value simultaneously (e.g., both read 50),
 * both will increment it to 51 and write 51 back. An increment is completely lost!
 */
void increment_with_race() {
    // Increased loop count to 10,000 to guarantee thread overlap and force the collision
    for (int i = 0 ; i < 10000; i++) {
        counter_race++;
    }
}

/*
 * HOW TO FIX IT:
 * We use a std::mutex (Mutual Exclusion) to protect the shared variable.
 * A lock ensures that only ONE thread can execute the protected critical section
 * at a time. It forces the Read/Modify/Write steps to complete entirely before
 * another thread is allowed to access the variable.
 */
void increment_safely() {
    for (int i = 0 ; i < 10000; i++) {
        // lock_guard automatically locks 'mtx' here and unlocks it at the end of the loop scope
        lock_guard<mutex> lock(mtx);
        counter_safe++;
    }
}

int main() {
    cout << "--- SCENARIO 1: THE RACE CONDITION ---\n";
    cout << "Initial Value : " << counter_race << "\n";
    cout << "Expected Value: 50000 (5 threads * 10,000 loops)\n";

    thread t1(increment_with_race);
    thread t2(increment_with_race);
    thread t3(increment_with_race);
    thread t4(increment_with_race);
    thread t5(increment_with_race);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "Actual Value  : " << counter_race << "  <-- (Data loss occurred!)\n\n";

    cout << "--- SCENARIO 2: THE FIXED VERSION (USING MUTEX AND LOCKGUARD) ---\n";
    cout << "Initial Value : " << counter_safe << "\n";
    cout << "Expected Value: 50000 (5 threads * 10,000 loops)\n";

    thread s1(increment_safely);
    thread s2(increment_safely);
    thread s3(increment_safely);
    thread s4(increment_safely);
    thread s5(increment_safely);

    s1.join();
    s2.join();
    s3.join();
    s4.join();
    s5.join();

    cout << "Actual Value  : " << counter_safe << "  <-- (Perfectly synchronized!)\n";

    return 0;
}