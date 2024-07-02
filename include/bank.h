#ifndef BANK_H
#define BANK_H

#include<vector>
#include "account.h"

class Bank{
    private:
        std::vector<Account> accounts;
        int nextAccountNumber;

        void loadAccounts();
        void saveAccounts() const;
    
    public:
        Bank();
        ~Bank();
    
    void createAccount(const std::string& name,double initialBalance);
    bool deposit(int accountNumber,double amount);
    bool withdraw(int accountNumber,double amount);
    void displayAccount(int accountNumber) const;
    void listAccounts() const;
};

#endif