#ifndef BANK_H
#define BANK_H

#include<vector>
#include "account.h"
#include <unordered_map>
#include<string>

class Bank{
    private:
        std::vector<Account> accounts;
        std::unordered_map<int,std::string> credentials;
        int nextAccountNumber;

        void loadAccounts();
        void saveAccounts() const;
        void loadCredentials();
        void saveCredentials() const;
        bool verifyUser(int accountNumber,const std::string& password) const;
    
    public:
        Bank();
        ~Bank();
    
    void createAccount(const std::string& name,double initialBalance,const std::string& password);
    bool deposit(int accountNumber,double amount,const std::string& password);
    bool withdraw(int accountNumber,double amount,const std::string& password);
    void displayAccount(int accountNumber,const std::string& password) const;
    void listAccounts() const;
    bool adminLogin(const std::string& username, const std::string& password) const;
};

#endif