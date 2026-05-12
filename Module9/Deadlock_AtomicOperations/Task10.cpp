//
// Created by AbhishekJalkhare on 20-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    atomic<int> value{10};
    int prev = value.fetch_add(5); // Atomically adds 5 and returns the previous value
    cout << "Previous Value: " << prev << endl; // Outputs 10
    cout << "Current Value: " << value.load() << endl; // Outputs 15

    prev = value.fetch_sub(3);
    cout<< "Previous Value: " << prev << endl; // Outputs 15
    cout << "Current Value: " << value.load() << endl; // Outputs 12

    prev = value.exchange(12);
    cout << "Previous Value: " << prev << endl; // Outputs 12
    cout << "Current Value: " << value.load() << endl; // Outputs 12

}
