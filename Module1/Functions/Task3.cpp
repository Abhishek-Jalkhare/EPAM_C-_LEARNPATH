//
// Created by AbhishekJalkhare on 02-02-2026.

//

#include <iostream>
using namespace std;

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
    return num1 / num2;
}

int main() {
    float num1, num2;
    int choice;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "\n--- Calculator Menu ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Addition Result: " << add(num1, num2) << endl;
        break;

    case 2:
        cout << "Subtraction Result: " << subtract(num1, num2) << endl;
        break;

    case 3:
        cout << "Multiplication Result: " << multiply(num1, num2) << endl;
        break;

    case 4:
        cout << "Division Result: " << divide(num1, num2) << endl;
    }
}