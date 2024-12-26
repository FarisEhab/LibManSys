//
// Created by MacBook on 26/12/2024.
//

#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H
#include <unordered_map>
#include <string>


class AuthManager {
private:
    std::unordered_map<std::string, std::string> users; // username -> password

public:
    //signup method
    bool signUp(const std::string &username, const std::string &password);

    bool logIn(const std::string &username, const std::string &password);

    int getUserCount() const;
};



#endif //AUTHMANAGER_H
