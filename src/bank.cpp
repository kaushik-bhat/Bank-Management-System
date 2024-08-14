#include "../include/bank.h"
#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<functional>

Bank::Bank() : nextAccountNumber(1){
    loadAccounts();
    loadCredentials();
}

Bank::~Bank(){
    saveAccounts();
    saveCredentials();
}

void Bank::loadAccounts(){
    std::ifstream db("D:/C++/Projects/Bank Management System/Bank-Management-System/data/accounts.txt");
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

        accounts.emplace_back(accNumber, accHolderName, balance,credentials[accNumber]);

        if(accNumber>=nextAccountNumber){
            nextAccountNumber= accNumber+1;
        }
    }
}

void Bank::saveAccounts() const{
    std::ofstream db("D:/C++/Projects/Bank Management System/Bank-Management-System/data/accounts.txt");
    if(!db.is_open())
        return;
    
    for(const auto& acc: accounts){
        db<<acc.toString()<<std::endl;
    }
}

void Bank::loadCredentials() {
    std::ifstream credFile("D:/C++/Projects/Bank Management System/Bank-Management-System/data/userCredentials.txt");
    if (!credFile.is_open()) {
        std::cout << "Error loading credentials" << std::endl;
        return;
    }
    std::string line;
    while (getline(credFile, line)) {
        std::vector<std::string> fields = Utils::split(line, ',');
        if (fields.size() != 2)
            continue;

        int accountNumber = std::stoi(fields[0]);
        std::string passwordHash = fields[1];

        credentials[accountNumber] = passwordHash;
    }
}

void Bank::saveCredentials() const {
    std::ofstream credFile("D:/C++/Projects/Bank Management System/Bank-Management-System/data/userCredentials.txt");
    if (!credFile.is_open())
        return;

    for (const auto& cred : credentials) {
        credFile << cred.first << "," << cred.second << std::endl;
    }
}

bool Bank::verifyUser(int accountNumber, const std::string& password) const {
    auto it = credentials.find(accountNumber);
    if (it == credentials.end())
        return false;

    std::hash<std::string> hasher;
    return hasher(password) == std::stoull(it->second);
}

void Bank::createAccount(const std::string& name, double initialBalance, const std::string& password) {
    std::hash<std::string> hasher;
    std::string passwordHash = std::to_string(hasher(password));

    std::cout << name << " your account number is " << nextAccountNumber << "\n" << "Please remember this for future transactions" << "\n";
    accounts.emplace_back(nextAccountNumber, name, initialBalance, passwordHash);
    credentials[nextAccountNumber] = passwordHash;

    nextAccountNumber++;
    saveAccounts();
    saveCredentials();
}

bool Bank::deposit(int accountNumber, double amount, const std::string& password) {
    if (!verifyUser(accountNumber, password)) {
        std::cout << "Invalid password" << std::endl;
        return false;
    }

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            acc.deposit(amount);
            saveAccounts();
            return true;
        }
    }
    return false;
}


bool Bank::withdraw(int accountNumber, double amount, const std::string& password) {
    if (!verifyUser(accountNumber, password)) {
        std::cout << "Invalid password" << std::endl;
        return false;
    }

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            if (acc.withdraw(amount)) {
                saveAccounts();
                return true;
            }
        }
    }
    return false;
}

void Bank::displayAccount(int accountNumber, const std::string& password) const {
    if (!verifyUser(accountNumber, password)) {
        std::cout << "Invalid password" << std::endl;
        return;
    }

    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            std::cout << "Account Number: " << acc.getAccountNumber() << std::endl;
            std::cout << "Account Holder's Name: " << acc.getAccountHolderName() << std::endl;
            std::cout << "Balance: " << acc.getBalance() << std::endl;
            return;
        }
    }
    std::cout << "Sorry, account not found" << std::endl;
}

void Bank::listAccounts() const{
    for(const auto& acc: accounts){
        std::cout<<acc.toString()<<std::endl;
    }
}

bool Bank::adminLogin(const std::string& username, const std::string& password) const {
    std::hash<std::string> hasher;
    std::unordered_map<std::string, std::string> adminCredentials;

    std::ifstream file("D:/C++/Projects/Bank Management System/Bank-Management-System/data/adminCredentials.txt");
    if(!file.is_open()){
        std::cout<<"Error could not open the admin credentials file"<<std::endl;
        return false;
    }
    std::string line;
    while(getline(file,line)){
        std::stringstream ss(line);
        std::string usernameFromFile, hashedPasswordFromFile;
        if(getline(ss,usernameFromFile,',')&&getline(ss,hashedPasswordFromFile)){
            adminCredentials[usernameFromFile]=hashedPasswordFromFile;
        }
    }
    file.close();
    auto it = adminCredentials.find(username);
    if (it != adminCredentials.end()) {
        return std::to_string(hasher(password)) == it->second;
    }
    return false;
}