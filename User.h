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

public:
    User(const std::string& username, const std::string& password);
    std::string getPassword() const;
    virtual ~User() = default;

    virtual void displayRole() const = 0;

};

class Reader : public User {
private:
    std::vector<Book> borrwedBooks;

public:
    Reader(const std::string &username, const std::string &password);
    //polymporphism
    void displayRole() const override;
    // Borrow a book
    void borrowBook(Book& book);
};

class Staff : public User {

public:
    Staff(const std::string& username, const std::string& password);
    void displayRole() const override;
    static void addBook(const std::string& ISBN, const std::string& title,
        const Author& author,
        int numCopies, BookCategory category);
    static void removeBook(Book book);
    static void updateBook(Book book);
};



#endif //USER_H
