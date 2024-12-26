//
// Created by MacBook on 26/12/2024.
//
#include <iostream>
#include "User.h"

int User::nextId = 1;

User::User(const std::string &username, const std::string &password)
    : username(username), password(password) {
    id = nextId++;
}

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

void Reader::displayRole() const override {
    std::cout << "Role: Reader" << std::endl;
}

void Staff::addBook(const std::string &ISBN, const std::string &title,
    const Author &author, int numCopies, const BookCategory category) {
    const Book book(ISBN, title, author, category);
    Catalogue::addBook(book);
}

void Staff::removeBook(Book book) {
    Catalogue::removeBook(book);
}

void Staff::updateBook(Book book) {
    Catalogue::updateBook(book);
}

void Staff::displayRole() const override {
    std::cout << "Role: Staff" << std::endl;
}
