//
// Created by AbhishekJalkhare on 27-01-2026.

//
// Uses public methods: deposit(double amount), withdraw(double amount),
// getBalance() Includes a protected member ownerName (string)
// Derives a class VIPAccount from BankAccount, which demonstrates
// access to ownerName Shows how encapsulation restricts direct membe
// r access and enables safe operations
#include<iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber{};
    double balance{};
protected:
    string ownerName{};
public:
    void deposit (const double amount) {
        if (amount < 0) {
            cout<<"Invalid amount"<< endl;
            return;
        }
        this->balance += amount;
        cout<<"Amount deposited succesfully"<<endl;
    }
    void withdraw (const double amount) {
        if (amount < 0) {
            cout<<"Invalid amount "<<endl;
            return;
        }
        else if (amount > this->balance) {
            cout<<"insufficient balance"<<endl;
            return;
        }

        this->balance -= amount;
    }
    [[nodiscard]] double getBalance ()  const{
        return this->balance;
    }

    [[nodiscard]] int account_number() const {
        return accountNumber;
    }

    [[nodiscard]] string owner_name() const {
        return ownerName;
    }

    void set_account_number(int account_number) {
        accountNumber = account_number;
    }

    void set_balance(double balance) {
        this->balance = balance;
    }

    void set_owner_name(const string &owner_name) {
        ownerName = owner_name;
    }
};


class VIPAccount : public BankAccount {
public:


    void getOwnerName () const {
        cout<<"Owner Name : "<<BankAccount::ownerName;
        // cout<<BankAccount::balance;  this will give error
    }


};

int main(int argc, char *argv[]) {
    BankAccount acc ;
    // acc.accountNumber;  inaccesible memeber
    acc.set_account_number(123);
    acc.deposit(123);
    acc.withdraw(12);
    cout<<"current Balance :" << acc.getBalance();

    VIPAccount vip ;
    vip.set_owner_name("abcd");
    vip.getOwnerName();
}
