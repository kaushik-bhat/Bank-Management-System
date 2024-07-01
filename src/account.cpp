#include "account.h"
#include <sstream>  

//Constructor
Account::Account(int accNum, const std::string& name , double bal)
    : accountNumber(accNum) , accountHolderName(name) , balance(bal) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountHolderName() const{
    return accountHolderName;
}

double Account::getBalance() const{
    return balance;
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