//
// Created by AbhishekJalkhare on 16-02-2026.
//
#include <iostream>
using namespace std;

class LogSession {
    int id;

public:
    LogSession(int id) : id(id) {
        cout << "[LogSession " << id << "] started." << endl;
    }

    ~LogSession() {
        cout << "[LogSession " << id << "] ended." << endl;
    }
};

void performDataValidation(int data_value) {
    LogSession session3(3);

    cout << "[LogSession 3] Validating data..." << endl;

    if (data_value < 0) {
        throw "Invalid Data";
    }

    cout << "[LogSession 3] data validated successfully." << endl;
}

void processTransaction(int data_value) {
    LogSession session2(2);

    performDataValidation(data_value);

    cout << "[LogSession 2] transaction processed." << endl;
}

void startCriticalOperation(int data_value) {
    LogSession session1(1);

    processTransaction(data_value);

    cout << "[LogSession 1] critical operation completed." << endl;
}

int main() {
    cout << "Starting main block." << endl;

    try {
        startCriticalOperation(-5);
    }
    catch (const char* msg) {
        cout << "Inside the main Catch handler: " << msg << endl;
    }

    return 0;
}
