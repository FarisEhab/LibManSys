//
// Created by MacBook on 26/12/2024.
//

#ifndef USER_H
#define USER_H
#include<string>
#include <vector>
#include "Book.h"


class User {
protected:
    static int nextId;
    int id;
    std::string username;
    std::string password;

public:
    User();

    User(const std::string& username, const std::string& password);

    std::string getPassword() const;

    virtual ~User() = default;

    virtual void displayRole() const = 0;

};

class Reader final : public User {
private:
    std::vector<Book> borrowedBooks;

public:
    Reader();
    Reader(const std::string &username, const std::string &password);
    //polymporphism
    void displayRole() const override;
    // Borrow a book
    void borrowBook(Book& book);
};

class Staff final : public User {

public:
    Staff(const std::string& username, const std::string& password);
    void displayRole() const override;
    static void addBook(const std::string& ISBN, const std::string& title,
        const Author& author,
        int numCopies, BookCategory category);
    static void removeBook(const Book &book);
    static void updateBook(const Book &book);
};



#endif //USER_H
