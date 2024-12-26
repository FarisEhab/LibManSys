//
// Created by MacBook on 26/12/2024.
//
//TODO:: Check if the user is a reader or a staff member in signUp and logIn methods and  check the user type before logging in
#include "Library.h"
void Library::run(){
    int choice;
    bool success = false;
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
            if (authManager.signUp(username, password)) {
                success = true;
            };
            break;
            case 2:
                std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (authManager.logIn(username, password)) {
                success = true;
            };
            break;
            case 3:
                std::cout << "Exiting..." << std::endl;
            break;
            default:
                std::cout << "Invalid choice... Please try again" << std::endl;
        }
    } while (choice != 3 && !success);
}