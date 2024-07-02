#include "../include/bank.h"
#include<iostream>
#include<limits>

void printMenu(){
    std::cout<<"1. Create Account"<<std::endl;
    std::cout<<"2. Deposit"<<std::endl;
    std::cout<<"3. Withdraw"<<std::endl;
    std::cout<<"4. Display Account"<<std::endl;
    std::cout<<"5. List All Accounts"<<std::endl;
    std::cout<<"6. Exit"<<std::endl;
    std::cout<<"Enter your choice"<<std::endl;
}

int main(){
    Bank bank;
    int choice;

    do{
        printMenu();
        std::cin>>choice;
        switch(choice){
            case 1:{
                std::string name;
                double initialBalance;
                std::cout<<"Enter your account number"<<std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin,name);
                std::cout<<"Enter initial balance: "<<std::endl;
                std::cin>>initialBalance;
                bank.createAccount(name,initialBalance);
                break;
            }
            case 2:{
                int accNum;
                double amount;
                std::cout<<"Enter your account number"<<std::endl;
                std::cin>>accNum;
                std::cout<<"Enter amount to be deposited"<<std::endl;
                std::cin>>amount;
                if(bank.deposit(accNum,amount)){
                    std::cout<<amount<<" succesfully deposited into account "<<accNum<<std::endl;
                }
                else{
                    std::cout<<"Sorry:(\n"<<amount<<" not deposited, either account not found or server error"<<std::endl;
                }
                break;
            }
            case 3:{
                int accNum;
                double amount;
                std::cout<<"Enter your account number"<<std::endl;
                std::cin>>accNum;
                std::cout<<"Enter amount to be deposited"<<std::endl;
                std::cin>>amount;
                if(bank.withdraw(accNum,amount)){
                    std::cout<<amount<<" succesfully withdrawn from account "<<accNum<<std::endl;
                }
                else{
                    std::cout<<"Sorry:(\nThere are three reason for this failure\n1.Insufficient balance\n2.Account not found\n3.Server error"<<std::endl;
                }
                break;
            }
            case 4:{
                int accNum;
                std::cout<<"Enter your account number"<<std::endl;
                std::cin>>accNum;
                bank.displayAccount(accNum);
                break;
            }
            case 5:
                bank.listAccounts();
                break;
            case 6:
                std::cout<<"Thank you for banking with us"<<std::endl;
                break;
            default:
                std::cout<<"Invalid choice please try again"<<std::endl;
        }
    }while(choice!=6);

    return 0;
}