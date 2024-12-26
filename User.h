//
// Created by MacBook on 26/12/2024.
//

#ifndef USER_H
#define USER_H
#include<string>
#include <vector>
#include "Book.h"
#include "Catalogue.h"


class User {
protected:
    static int nextId;
    int id;
    std::string username;
    std::string password;
};

class Reader : public User {
private:
    std::vector<Book> borrwedBooks;

public:
    // Constructor
    Reader(const std::string& username, const std::string &password);
    // Borrow a book
    void borrowBook(const Book& book);
};

class Staff : public User {
    void Catalogue::addBook(Book book);
    void Catalogue::removeBook(Book book);
    void Catalogue::updateBook(Book book);
};



#endif //USER_H
