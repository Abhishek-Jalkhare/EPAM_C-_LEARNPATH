//
// Created by AbhishekJalkhare on 02-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
mutex mtx;

class Logger {
    inline static Logger* instance;
    inline static once_flag flag ;

    Logger() {
        cout<<"Logger Instance created"<<endl;
    }


public:
    void log() const {
        lock_guard<mutex> lock(mtx); // Protect console output
        cout << "[Thread ID: " << this_thread::get_id() << "] "
             << "Address Of Instance: " << this<<endl;
    }

    static Logger& getInstance() {
        call_once(flag,[]() {
            instance = new Logger();
        });
        return *instance;
    }
};

void worker() {
    const Logger& lg = Logger::getInstance();
    lg.log();
}

int main(int argc, char* argv[]) {
    Logger& lg1 = Logger::getInstance();
    vector<thread> threads;
    for (int i = 1; i <= 5; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
    }
}