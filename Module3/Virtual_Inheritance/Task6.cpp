//
// Created by AbhishekJalkhare on 05-02-2026.
//
#include <iostream>
#include <vector>
using namespace std;

class Logger {
public:
    virtual ~Logger() {
        cout<<"Logger destroyed"<<endl;
    }

    virtual void log() = 0;
};

class FileLogger : public Logger {
public:
    void log() override {
        cout<<"File Logged"<<endl;
    }

    ~FileLogger() override { // here we override destructor
        cout<<"FileLogger Destroyed"<<endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void log() override {
        cout<<"Console Logged"<<endl;
    }

    ~ConsoleLogger() override {
        cout<<"Console logger destroyed"<<endl;
    }
};

int main(int argc, char* argv[]) {
     vector<Logger *> vec {new ConsoleLogger() , new FileLogger()};
     for (const auto b : vec) {
         b->log();
         delete b;
     }
}
