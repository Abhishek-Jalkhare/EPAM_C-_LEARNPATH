//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2;


    cout << "===== Calculator Menu =====" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;


    switch (choice) {

    case 1:
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        cout << "Result = " << (num1 + num2) << endl;
        break;

    case 2:
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        cout << "Result = " << (num1 - num2) << endl;
        break;

    case 3:
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        cout << "Result = " << (num1 * num2) << endl;
        break;

    case 4:
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        if (num2 != 0)
            cout << "Result = " << (num1 / num2) << endl;
        else
            cout << "Error: Division by zero is not allowed" << endl;
        break;

    default:
        cout << "Invalid choice! Please select between 1 and 4." << endl;
    }

    return 0;
}
