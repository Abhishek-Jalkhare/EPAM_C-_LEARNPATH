//
// Created by AbhishekJalkhare on 03-04-2026.
//

// Defines a shared integer variable Launches several reader threads that repeatedly acquire a shared (read) lock
// and print the value Launches one writer thread that periodically acquires an exclusive (write) lock and
// updates the value Uses std::shared_mutex to ensure:
//
// Multiple readers can read at the same time
// Readers block while a writer holds the lock (and vice versa) Lets threads run for several iterations,
// demonstrating correct synchronization

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int shared_value = 0;
shared_mutex mt;

void writer() {
    cout << "[W] Requesting Write Lock..." << endl;
    unique_lock<shared_mutex> ul(mt);
    cout << "[W] Writing: Value is now " << ++shared_value << endl;
    this_thread::sleep_for(chrono::milliseconds(500)); // Longer sleep to observe
    cout << "[W] Finished Writing. Releasing Lock." << endl;
}

void reader() {
    shared_lock<shared_mutex> sl(mt);
    cout << "[R] Reading Value: " << shared_value << " (ID: " << this_thread::get_id() << ")" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "[R] Finished Reading (ID: " << this_thread::get_id() << ")" << endl;
}

int main(int argc, char* argv[]) {
    thread t1 (writer);
    thread t2 (reader);
    thread t3 (reader);
    thread t4 (reader);


    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
