//
// Created by MacBook on 26/12/2024.
//

#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include "AuthManager.h"


class Library {
private:
    AuthManager authManager;

public:
    void run() {
        int choice;
        do {
            std::cout << "1. Sign Up \n2. Log In \n3. Exit" << std::endl;
            std::cin >> choice;
            std::string username, password;
            switch (choice) {
                case 1:
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;
                    authManager.signUp(username, password);
                    break;
                case 2:
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;
                    authManager.logIn(username, password);
                    break;
                case 3:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice... Please try again" << std::endl;
            }
        } while (choice != 3);
    }
};



#endif //LIBRARY_H
