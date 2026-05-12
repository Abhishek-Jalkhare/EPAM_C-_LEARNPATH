#include <iostream>
#include <string>
#include <thread>
#include <shared_mutex>
#include <chrono>
#include <mutex>

using namespace std;

string unsafe_dat = "";
string safe_dat = "";
shared_mutex mtx;

void unsafe_reader() {
    for(int i = 0; i < 5 ; i++) {
        // Data race: Reading while another thread might be writing (std::string reallocation can cause a crash here)
        cout << "[Thread " << this_thread::get_id() << "] Unsafe Read : " << unsafe_dat << "\n";
        this_thread::sleep_for(chrono::milliseconds(10)); // Force overlap
    }
}

void unsafe_writer() {
    for(int i = 0; i < 5 ; i++){
        unsafe_dat += "a"; // Data race: Modifying shared string without lock
        cout << "[Thread " << this_thread::get_id() << "] Unsafe Write: " << unsafe_dat << "\n";
        this_thread::sleep_for(chrono::milliseconds(10)); // Force overlap
    }
}


void safe_reader() {
    for(int i = 0; i < 5 ; i++) {
        // shared_lock allows multiple readers simultaneously, but blocks writers
        shared_lock<shared_mutex> sl(mtx);
        cout << "[Thread " << this_thread::get_id() << "] Safe Read   : " << safe_dat << "\n";
        sl.unlock(); 
        
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void safe_writer() {
    for(int i = 0; i < 5 ; i++){
        // unique_lock requires exclusive access, blocking all other readers and writers
        unique_lock<shared_mutex> ul(mtx);
        safe_dat += "a";
        cout << "[Thread " << this_thread::get_id() << "] Safe Write  : " << safe_dat << "\n";
        ul.unlock(); 
        
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main() {

    thread t1(unsafe_reader);
    thread t2(unsafe_writer);
    
    t1.join();
    t2.join();

    thread t3(safe_reader);
    thread t4(safe_writer);
    
    t3.join();
    t4.join();

    return 0;
}