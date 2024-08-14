#include "../include/utils.h"
#include <sstream>
#include<iostream>
#include<conio.h>

std::vector<std::string> Utils::split(const std::string& str, char delimiter){
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;
    while(getline(ss,item,delimiter)){
        tokens.push_back(item);
    }
    return tokens;
}

std::string Utils::getPassword(){
    std::string password;
    char ch;
    while ((ch = _getch()) != '\r') {  // Enter key
        if (ch == '\b') {  // backspace
            if (!password.empty()) {
                std::cout << "\b \b"; 
                password.pop_back();
            }
        }
        else {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << std::endl;  // Move to the next line after Enter is pressed
    return password;
}