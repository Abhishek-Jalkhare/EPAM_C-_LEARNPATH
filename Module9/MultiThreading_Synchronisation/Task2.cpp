//
// Created by AbhishekJalkhare on 02-04-2026.
//
#include <iostream>
#include <thread>

using namespace std;

void worker() {
    this_thread::sleep_for(std::chrono::seconds(2));
    cout<<"Hello From Worker thread"<<endl; // this message may or may not printed
    // if the main thread finishes execution before this   thread will be
    // killed abruptly
}

int main(int argc, char* argv[]) {
    thread t(worker);
    t.detach();
    cout<<"Main Thread Ends"<<endl;
}
