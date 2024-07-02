#include "bank.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <sstream>

Bank::Bank() : nextAccountNumber(1){
    loadAccounts();
}

Bank::~Bank(){
    saveAccounts();
}

void Bank::loadAccounts(){
    std::ifstream db("data/accounts.txt");
    if(!db.is_open()){
        std::cout<<"Sorry:(\nError with database"<<std::endl;
        return;
    }
    std::string line;
    while(getline(db,line)){
        std::vector<std::string> fields = Utils::split(line,',');
        if(fields.size()!=3)
            continue;
        
        int accNumber = std::stoi(fields[0]);
        std::string accHolderName = fields[1];
        double balance = std::stod(fields[2]);

        accounts.emplace_back(accNumber, accHolderName, balance);

        if(accNumber>=nextAccountNumber){
            nextAccountNumber= accNumber+1;
        }
    }
}

void Bank::saveAccounts() const{
    std::ofstream db("data/accounts.txt");
    if(!db.is_open())
        return;
    
    for(const auto& acc: accounts){
        db<<acc.toString()<<std::endl;
    }
}

void Bank::createAccount(const std::string& name, double initialBalance){
    accounts.emplace_back(nextAccountNumber++,name,initialBalance);
    saveAccounts();
}

bool Bank::deposit(int accountNumber,double amount){
    for(auto& acc: accounts){
        if(acc.getAccountNumber() == accountNumber){
            acc.deposit(amount);
            saveAccounts();
            return true;
        }
    }
    return false;
}

bool Bank::withdraw(int accountNumber,double amount){
    for(auto& acc: accounts){
        if(acc.getAccountNumber() == accountNumber){
            if(acc.withdraw(amount)){
                saveAccounts();
                return true;
            }
        }
    }
    return false;
}

void Bank::displayAccount(int accountNumber) const{
    for(const auto& acc: accounts){
        if(acc.getAccountNumber() == accountNumber){
            std::cout<<"Account Number: "<<acc.getAccountNumber()<<std::endl;
            std::cout<<"Account Holder's Name: "<<acc.getAccountHolderName()<<std::endl;
            std::cout<<"Balance: "<<acc.getBalance()<<std::endl;
            return;
        }
    }
    std::cout<<"Sorry Account not found"<<std::endl;
}

void Bank::listAccounts() const{
    for(const auto& acc: accounts){
        std::cout<<acc.toString()<<std::endl;
    }
}