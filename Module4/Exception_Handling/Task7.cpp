//
// Created by AbhishekJalkhare on 18-02-2026.
//
#include <iostream>
using namespace std;

class BankAccount {
    string owner;
    int accountNumber;
    double balance;

public:
    [[nodiscard]] string getOwner() const {
        return owner;
    }

    [[nodiscard]] int getAccountNumber() const {
        return accountNumber;
    }

    [[nodiscard]] double getBalance() const {
        return balance;
    }

    BankAccount(const string& owner, const int account_number, const double balance)
        : owner(owner),
          accountNumber(account_number),
          balance(balance) {
    }
    void deposit(const double amount) {
        if (amount < 0)
            throw std::invalid_argument("Deposit amount cannot be negative.");
        this->balance += amount;
    }
    void withdraw (double amount) {
        if (amount < 0)
            throw invalid_argument("Amount can't be negative");
        if (amount > this->balance) {
            throw runtime_error("insufficient funds");
        }
        this->balance -= amount;
    }

    bool transfer(BankAccount& target , double amount)noexcept {
        if (amount < 0 || amount > this->balance) return false;
        target.balance += amount;
        this->balance -= amount;
        return true;
    }

    void display() const {
        cout<<"------- Account information --------"<<endl;
        cout<<"Account Holder name  : "<<getOwner();
        cout<<"Account Number : "<<getAccountNumber();
        cout<<"Account balance : "<<getBalance();
    }

};


int main(int argc, char* argv[]) {
    BankAccount alice("Alice", 1001, 500.0);
    BankAccount bob("Bob", 1002, 300.0);
    try{
        alice.deposit(1000);
        alice.display();

        alice.deposit(-1000);
    }
    catch (const exception& e) {
        cout<<"Deposit error: " << e.what() << std::endl;
    }
    cout<<"State after invalid operation"<<endl;
    alice.display();

    bob.withdraw(12);
    bob.display();
    try{
        bob.withdraw(100000900);
    }
    catch (const exception& e) {
        cout<<"Error encountered"<<e.what();
    }
    cout<<"State of bob after invalid withdraw operation"<<endl;
    bob.display();

    alice.transfer(bob , 100);
    cout<<"State  of alice account after transfer"<<endl;
    alice.display();
    cout<<"state of bob accout after transfer"<<endl;
    bob.display();

    bool transfer =alice.transfer(bob , -1000);
    if (!transfer ) cout<<"Failed transfer"<<endl;
    cout<<"State  of alice account after failed transfer"<<endl;
    alice.display();
    cout<<"state of bob accout after failed transfer"<<endl;
    bob.display();
}
