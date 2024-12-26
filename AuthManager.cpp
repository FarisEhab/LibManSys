//
// Created by MacBook on 26/12/2024.
//

#include "AuthManager.h"

#include <iostream>

bool AuthManager::signUp(const std::string &username, const std::string &password) {
    if (users.find(username) != users.end()) {
        std::cerr << "Username already exists" << std::endl;
        return false;
    }
    users[username] = password;
    std::cout << "User created successfully" << std::endl;
    return true;
};

bool AuthManager::logIn(const std::string &username, const std::string &password) {
    auto it = users.find(username);
    if (it == users.end()) {
        std::cerr << "Username does not exist" << std::endl;
        return false;
    }
    // check password
    //second means the "value" of the key-value pair
    if (it->second != password) {
        std::cerr << "Incorrect password" << std::endl;
        return false;
    }
    std::cout << "User logged in successfully" << std::endl;
    return true;
};

int AuthManager::getUserCount() const {
    return users.size();
};

