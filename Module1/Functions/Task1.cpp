//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;


static float balance = 0.0f;


void deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit Successful!" << endl;
        cout << "Deposited Amount: Rs. " << amount << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}


void withdraw(float amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
    }
    else if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    }
    else {
        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
        cout << "Withdrawn Amount: Rs. " << amount << endl;
    }
}


float checkBalance() {
    return balance;
}

int main() {
    int choice;
    float amount;

    do {
        cout << "\n===== Banking System Menu =====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit(amount);
            cout << "Current Balance: Rs. " << checkBalance() << endl;
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(amount);
            cout << "Current Balance: Rs. " << checkBalance() << endl;
            break;

        case 3:
            cout << "Current Balance: Rs. " << checkBalance() << endl;
            break;

        case 4:
            cout << "Thank you for using the banking system." << endl;
            break;

        default:
            cout << "Invalid choice! Please select a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}
