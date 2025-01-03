//
// Created by MacBook on 26/12/2024.
//
#include <iostream>
#include "User.h"

#include "Catalogue.h"
#include "Transaction.h"

int User::nextId = 1;

User::User () {
    id = nextId++;
}

User::User(const std::string &username, const std::string &password)
    : username(username), password(password) {
    id = nextId++;
}

std::string User::getPassword() const{
    return password;
}

// Reader

Reader::Reader() = default;

Reader::Reader(const std::string &username, const std::string &password) : User(username, password) {}

void Reader::borrowBook(Book &book) {
    if (book.isAvailable()) {
        // Create a transaction
        Transaction transaction(*this, book, std::chrono::system_clock::now(), 14);
        // Update the number of copies of the book
        book.setNumCopies(book.getNumCopies() - 1);
        std::cout << "Book borrowed successfully" << std::endl;
        if (!book.isAvailable()) {
            std::cout << "User borrowed the last copy!" << std::endl;
        }
    } else {
        std::cout << "Sorry! this book is not available" << std::endl;
    }
}

 void Reader::displayRole() const {
    std::cout << "Role: Reader" << std::endl;
}

// Staff

Staff::Staff(const std::string &username, const std::string &password) : User(username, password){}

void Staff::addBook(const std::string &ISBN, const std::string &title,
    const Author &author, int numCopies, const BookCategory category) {
    Catalogue::addBook(ISBN, title, author, category);
}

void Staff::removeBook(const Book &book) {
    Catalogue::removeBook(book);
}

void Staff::updateBook(const Book &book) {
    Catalogue::updateBook(book);
}

void Staff::displayRole() const {
    std::cout << "Role: Staff" << std::endl;
}
