#include "../include/bank.h"
#include "../include/utils.h"
#include<iostream>
#include<limits>
#include<conio.h>

void printMenu(){
    std::cout<<"1. Create Account"<<std::endl;
    std::cout<<"2. Deposit"<<std::endl;
    std::cout<<"3. Withdraw"<<std::endl;
    std::cout<<"4. Display Account"<<std::endl;
    std::cout<<"5. List All Accounts (Admin)"<<std::endl;
    std::cout<<"6. Exit"<<std::endl;
    std::cout<<"Enter your choice"<<std::endl;
}

int main(){
    Bank bank;
    int choice;
    do {
        printMenu();
        std::cin>>choice;
        switch(choice){
            case 1:{
                std::string name, password, confirmPassword;
                double initialDeposit;
                std::cout<<"Enter your name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin,name);
                std::cout<<"Enter initial deposit: ";
                std::cin>>initialDeposit;
                do {
                    std::cout<<"Enter password: ";
                    password=Utils::getPassword();
                    std::cout<<"Confirm password: ";
                    confirmPassword=Utils::getPassword();
                    if(password !=confirmPassword){
                        std::cout<<"Passwords do not match. Please try again."<<std::endl;
                    }
                }while(password!= confirmPassword);
                bank.createAccount(name, initialDeposit, password);
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                std::string password;
                std::cout<<"Enter account number: ";
                std::cin>>accountNumber;
                std::cout<<"Enter amount to deposit: ";
                std::cin>>amount;
                std::cout<<"Enter password: ";
                password=Utils::getPassword();
                if(!bank.deposit(accountNumber, amount, password)){
                    std::cout<<"Deposit failed. Check your credentials and try again."<<std::endl;
                }
                break;
            }
            case 3:{
                int accountNumber;
                double amount;
                std::string password;
                std::cout<<"Enter account number: ";
                std::cin>>accountNumber;
                std::cout<< "Enter amount to withdraw: ";
                std::cin>>amount;
                std::cout<<"Enter password: ";
                password=Utils::getPassword();
                if(!bank.withdraw(accountNumber, amount, password)){
                    std::cout<<"Withdrawal failed. Check your credentials and try again."<<std::endl;
                }
                break;
            }
            case 4:{
                int accountNumber;
                std::string password;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter password: ";
                password=Utils::getPassword();
                bank.displayAccount(accountNumber, password);
                break;
            }
            case 5:{
                std::string adminUsername, adminPassword;
                std::cout << "Admin Username: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin,adminUsername);
                std::cout << "Admin Password: ";
                adminPassword=Utils::getPassword();
                if(bank.adminLogin(adminUsername, adminPassword)){
                    bank.listAccounts();
                }
                else{
                    std::cout << "Invalid Admin Credentials" << std::endl;
                }
                break;
            }
            case 6:
                std::cout << "Thank you for banking with us" << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again" << std::endl;
        }
    }while(choice != 6);

    return 0;
}