//
// Created by AbhishekJalkhare on 04-02-2026.
//
#include <iostream>
using namespace std;

class Logger {
public:
    virtual ~Logger() {
        cout<<"base destroyed"<<endl;
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
    Logger * b = new ConsoleLogger();
    delete b;
}
