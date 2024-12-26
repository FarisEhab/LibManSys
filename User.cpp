//
// Created by MacBook on 26/12/2024.
//

#include "User.h"

int User::nextId = 1;

Reader::Reader(const std::string &username, const std::string &password) {
    id = nextId++;
    this->username = username;
    this->password = password;
};

void Reader::borrowBook(const Book &book) {
    //TODO:: Implement after the catalog class is implemented
}
