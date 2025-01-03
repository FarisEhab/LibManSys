//
// Created by MacBook on 26/12/2024.
//

#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H
#include <map>
#include <string>

#include "User.h"


class AuthManager {
private:

    std::unordered_map<std::string, Staff> admins; // username -> password
    std::unordered_map<std::string, Reader> readers; // username -> password

public:
    //signup method
    bool signUp(const std::string &username, const std::string &password);

    bool logIn(const std::string &username, const std::string &password);

    int getUserCount() const;

    ~AuthManager() = default;
};



#endif //AUTHMANAGER_H
