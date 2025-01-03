//
// Created by MacBook on 26/12/2024.
//

#include "AuthManager.h"

#include <iostream>
//TODO:: Create a Reader signup method and a staff signup method
//TODO:: Create a Reader login method and a staff login method

bool AuthManager::signUp(const std::string &username, const std::string &password) {
    // check if the username already exists
    if (readers.find(username) != readers.end()) {
        std::cerr << "Username already exists" << std::endl;
        return false;
    }
    // add the user to the map
    const Reader reader(username, password);
    readers[username] = reader;
    std::cout << "User created successfully" << std::endl;
    return true;
};

bool AuthManager::logIn(const std::string &username, const std::string &password) {
    auto it = readers.find(username);
    if (it == readers.end()) {
        std::cerr << "Username does not exist" << std::endl;
        return false;
    }
    // check password
    //second means the "value" of the key-value pair which is "User" object
    if (it->second.getPassword() != password) {
        std::cerr << "Incorrect password" << std::endl;
        return false;
    }
    std::cout << "User logged in successfully" << std::endl;
    return true;
};

int AuthManager::getUserCount() const {
    return readers.size();
};



