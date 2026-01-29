//
// Created by AbhishekJalkhare on 29-01-2026.
//

// t: Creates a BankAccount class with private members: accountNumber (int), balance (double)
// Implements public functions: deposit(double amount), withdraw(double amount), and getBalance(
// ) Ensures that withdraw() validates funds, preventing withdrawal that would overdraw the account
// Demonstrates that accountNumber and balance cannot be accessed directly from outside the class

#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    double balance;

public:
    BankAccount(const int account_number, const double balance)
        : accountNumber(account_number),
          balance(balance) {
    }

    void deposit(const double amt) {
        if (amt <= 0) {
            cout<<"Enter a valid amount"<<endl;
            return;
        }
        this->balance += amt;
    }

    void withdraw(const double amt) {
        if (amt <= 0) {
            cout<<"Enter a valid amount"<<endl;
            return;
        }
        if ( amt > this->balance ) {
            cout<<"insufficient balance"<< endl;
        }

        this->balance -= amt;
    }

    [[nodiscard]] double getBalance () const {
        return this->balance;
    }


};

int main(int argc, char* argv[]){
    BankAccount b(1001 , 0.0);
    b.deposit(12);
    b.withdraw(1.3);
    double bal = b.getBalance();
    cout<<"Account balance : " <<bal;

    // int accountno = b.accountNumber;
    // this will give the error because we can not access the private accountnnumber field


}


