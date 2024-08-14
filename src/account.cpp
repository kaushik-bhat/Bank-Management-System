#include "../include/account.h"
#include <sstream>  

//Constructor
Account::Account(int accNum, const std::string& name , double bal,const std::string& pwdHash)
    : accountNumber(accNum) , accountHolderName(name) , balance(bal), passwordHash(pwdHash) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountHolderName() const{
    return accountHolderName;
}

double Account::getBalance() const{
    return balance;
}

std::string Account::getPasswordHash() const {
    return passwordHash;
}

void Account::deposit(double amount){
    balance+=amount;
}

bool Account::withdraw(double amount){
    if(amount>balance)
        return false;
    else{
        balance-=amount;
        return true;
    }
}

std::string Account::toString() const{
    std::stringstream ss;
    ss << accountNumber << "," << accountHolderName << "," << balance;
    return ss.str();
}