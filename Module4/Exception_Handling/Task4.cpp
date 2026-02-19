//
// Created by AbhishekJalkhare on 16-02-2026.
//
#include <cmath>
#include <iomanip>
#include <iostream>

#include <unordered_set>

using namespace std;

unordered_set<string>accounts;

class InsufficientFundsException : public runtime_error{
    string accountNumber;
    double currentBalance;
    double requestedAmount;
    // build message need to be static because it is used in construction and before construction no this
    // exist so it can not invoke memeber fucntion
    [[nodiscard]]static string buildMessage(const string& accountNumber , const double currentBalance , double amount)  {
        return  ("Insufficient funds for account " + accountNumber
            +". Current balance: " + to_string(currentBalance)
            + ", Requested amount: " +to_string(amount));
    }
public:
    InsufficientFundsException(const std::string& account, const double balance, double amount) :
    std::runtime_error(buildMessage(account , balance ,amount)),
    accountNumber(account),currentBalance(balance),
    requestedAmount(amount){}
};


class InvalidAmountException : public std::invalid_argument {
    double invalidAmount;
    std::string operationName;

    static std::string buildMessage(const double amount,
                                    const std::string& operation) {
         return ("Invalid amount (" + to_string(amount)
            + ") for operation: " + (operation));
    }

public:
    InvalidAmountException(const double amount,
                           const std::string& operation)
        : std::invalid_argument(buildMessage(amount, operation)),
          invalidAmount(amount),
          operationName(operation)
    {}
    //do not build message in what() because it is noexpect, and it can't throw exception and string
    // concatenation may throw some error
};


class AccountNotFoundException : public out_of_range {
    string accountNumber;

public:
    explicit AccountNotFoundException(const string& account_number)
        : out_of_range("No account found for account number : " + account_number), accountNumber(account_number) {
    }
};


class TransactionLimitExceededException : public std::logic_error {
    double attemptedAmount;
    double dailyLimit;

    static string buildMessage(double amount, double limit) {

        return "Transaction limit exceeded. Attempted: "
            + to_string(amount)
            + ", Daily limit: "
            + to_string(limit);
        }
public:
    TransactionLimitExceededException(double amount, double limit)
        : std::logic_error(buildMessage(amount, limit)),
        attemptedAmount(amount),
        dailyLimit(limit)
    {}
};


class BankSystemException : public std::runtime_error {
    std::string componentName;
    std::string errorDescription;

    static std::string buildMessage(const std::string& component,
                                    const std::string& error)
    {
        return "Bank system error in [" + component +
               "]: " + error;
    }

public:
    BankSystemException(const std::string& component,
                        const std::string& error)
        : std::runtime_error(buildMessage(component, error)),
          componentName(component),
          errorDescription(error)
    {}
};


class BankAccount {
    string accountNumber;
    string holderName ;
    string balance ;
    string dailyWithdrawllimit ;
    string dailyWithdrawnAmount;

    void validateAmount(double amount, const std::string& operation) const {
        if (amount < 0) throw InvalidAmountException(amount , operation);
        if (isnan(amount) || isinf(amount)) throw InvalidAmountException(amount , operation);
    }

public:
    BankAccount(const string& account_number, const string& holder_name, const string& balance)
        : accountNumber(account_number),
          holderName(holder_name),
          balance(balance) , dailyWithdrawllimit("50000") , dailyWithdrawnAmount("0") {
        double dbl_balance = getBalance();
        if (accounts.contains(account_number)) throw logic_error("Account already Exist ");
        if (dbl_balance < 0) throw InvalidAmountException(dbl_balance , "Intialising account");
        if (account_number.empty() || holder_name.empty()) throw invalid_argument("account number or holder name can't not be empty");
        accounts.insert(account_number);
    }

    BankAccount() = default;

    void deposit(const double amount) {
        validateAmount(amount , "deposit");
        if (amount > 1000000)
            throw BankSystemException("Deposit" ,"amount is more than Rs. 10,000,00");
        double dbl_balance = getBalance();
        dbl_balance += amount;
        this->balance = to_string(dbl_balance);
    }

    void withdraw(const double amount) {
        validateAmount(amount,"withdraw");
        double dbl_balance = stod(balance);
        if (amount > dbl_balance)
            throw InsufficientFundsException(this->accountNumber , dbl_balance,amount);
        double dbl_daily_withdrawn_amt = getDailyWithdrawnAmount();
        const double dbl_daily_withdraw_limit = getDailyWithdrawlLimit();
        if (dbl_daily_withdrawn_amt + amount > dbl_daily_withdraw_limit)
            throw TransactionLimitExceededException(dbl_daily_withdrawn_amt+amount , dbl_daily_withdraw_limit);
        if (amount > 100000)throw BankSystemException("Fraud Detection" , "Amount greater than 100000");
        dbl_balance -= amount;
        dbl_daily_withdrawn_amt += amount;
        this->balance = to_string(dbl_balance);
        this->dailyWithdrawnAmount = to_string(dbl_daily_withdrawn_amt);
    }

    void transferTo(BankAccount& recipient , const double amount) {
        validateAmount(amount, "transfer");
        if (!accounts.contains(recipient.accountNumber)) throw AccountNotFoundException(recipient.accountNumber);
        if (this->accountNumber == recipient.accountNumber)
                throw logic_error("Can't transfer to self");
        withdraw(amount);
        recipient.deposit(amount);

    }


    [[nodiscard]] string getAccountNumber() const {
        return accountNumber;
    }

    [[nodiscard]] string getHolderName() const {
        return holderName;
    }

    [[nodiscard]] double getBalance() const {
        return stod(balance);
    }

    [[nodiscard]] double getDailyWithdrawlLimit() const {
        return stod(dailyWithdrawllimit);
    }

    [[nodiscard]] double getDailyWithdrawnAmount() const {
        return stod(dailyWithdrawnAmount);
    }
};


int main(int argc, char* argv[]) {
    try{
        BankAccount a1{"101","Abhishek" , "1000"};
        BankAccount a2{"102" , "Sam" , "300"};
        a1.deposit(100);
        cout<<"Balance of a1 after deposit : "<<a1.getBalance()<<endl;
        a1.withdraw(300);
        cout<<"Balance of a1 after withdrwal : "<<a1.getBalance()<<endl;
        a1.transferTo(a2 , 50);
        cout<<"Balance of a1 after transfer : "<<a1.getBalance()<<"\n"<<"Balance of a2 after transfer : "<<a2.getBalance()<<endl;
        BankAccount a3{"101" ,"Abhishek" , "100" }; // account duplication
        BankAccount blank;
        a1.transferTo(blank , 1); // transferring to non-existent account
        a1.deposit(55000);
        a1.withdraw(60000);
        a1.withdraw(50001); // limit exceed
        a1.deposit(10000000000000) ;// bank system exception
    }
    catch (const InsufficientFundsException& e) {
        cout<<"Insufficient Funds Exception : "<<e.what()<<endl;
    }
    catch (const InvalidAmountException& e) {
        cout<<"Invalid Amount Exception "<<e.what()<<endl;;
    }
    catch (const AccountNotFoundException& e) {
        cout<<"Accoutn NOt found Exception : "<<e.what()<<endl;
    }
    catch (const TransactionLimitExceededException& e) {
        cout<<"Transaction Limit Exceeded Exception : "<<e.what()<<endl;
    }
    catch (const BankSystemException& e) {
        cout<<"Bank SystemException "<<e.what()<<endl;
    }
    catch (const std::out_of_range& e) {
        cout<<"Out of range exception "<<e.what()<<endl;
    }
    catch (const std::invalid_argument& e) {
        cout<<"Invalid Argument exception : "<<e.what()<<endl;
    }
    catch (const std::logic_error& e) {
        cout<<"Logic Error : "<<e.what()<<endl;
    }
    catch (const std::runtime_error& e) {
        cout<<"Runtime error : "<<e.what();
    }
    catch (const std::exception& e) {
        cout<<"Exception Caught : "<<e.what()<<endl;
    }
    catch (...) {
        cout<<"Unexpected error occured"<<endl;
    }


}
