#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

class Account{
    private:
        int accountNumber;
        std::string accountHolderName;
        double balance;
    
    public:
        Account(int accNum, const std::string& name , double bal);
        int getAccountNumber() const;
        std::string getAccountHolderName() const;
        double getBalance() const;

        void deposit(double amount);
        bool withdraw(double amount);
        std::string toString() const;

};

#endif