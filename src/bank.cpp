#include "Bank.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <sstream>

Bank::Bank() : nextAccountNumber(1){
    loadAccounts();
}

Bank::~Bank(){
    saveAccounts();
}