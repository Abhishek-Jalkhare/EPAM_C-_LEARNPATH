//
// Created by AbhishekJalkhare on 13-02-2026.
//
#include <stdexcept>

#include <iostream>

using namespace std;

double divide(int numerator, int denominator) {
    if (denominator == 0) throw runtime_error("Denominator can not be zero");
    return static_cast<double>(numerator)/denominator;
}


int main(int argc, char* argv[]) {
    int numerator , denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    try {
        cout<<"Result of Division : "<<divide(numerator , denominator)<<endl;

    }
    catch ( const runtime_error& err ) {
        cout<<err.what()<<endl;
    }
    cout<<"END OF PROGRAMM"<<endl;
}
