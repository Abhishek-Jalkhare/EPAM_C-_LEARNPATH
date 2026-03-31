//
// Created by AbhishekJalkhare on 30-03-2026.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrivalTime;
    Patient(const string& n, int s, int t) : name(n), severity(s), arrivalTime(t) {}

    bool operator<(const Patient& other) const {
        if (this->severity != other.severity) return this->severity > other.severity;
        else return this->arrivalTime > other.arrivalTime;
    }
};

int main(int argc, char* argv[]) {
    priority_queue<Patient , std::vector<Patient>> pq;
    pq.push(Patient("Bob", 1, 5));
    pq.push(Patient("Charlie", 3, 8));
    pq.push(Patient("David", 2, 12));
    pq.push(Patient("Eve", 1, 7));
    pq.push(Patient("Alice", 3, 10));
    pq.push(Patient("Grace", 3, 10));
    pq.push(Patient("Frank", 5, 2));
    while (!pq.empty()) {
        Patient p = (pq.top());
        cout<< "Processing patient ["<<p.name << "]: Severity ["<<p.severity
        << "], Arrived at ["<<p.arrivalTime << "]"<<endl;
        pq.pop();
    }
}
