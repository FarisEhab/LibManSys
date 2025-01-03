//
// Created by MacBook on 26/12/2024.
//

#include "Catalogue.h"
#include "Book.h"
#include <map>
#include <iostream>

bool Catalogue::findByISBN(const std::string &ISBN) {
    return books.find(ISBN) != books.end();
};

void Catalogue::addBook(const std::string &ISBN, const std::string &title, const Author &author, BookCategory category) {
    // add the book to the catalogue
    // check if the book is already in the catalogue
    if (findByISBN(ISBN)) {
        std::cout << "Book already exists in the catalogue" << std::endl;
    } else {
        // if not, add the book to the catalogue
        Book book(ISBN, title, author, category);
        books[book.getISBN()] = book;
    }
};

void Catalogue::removeBook(const Book &book) {
    if (!findByISBN(book.getISBN())) {
        std::cout << "Book is already not in the catalogue" << std::endl;
    } else {
        books.erase(book.getISBN());
    }
};

void Catalogue::updateBook(const Book &book) {
    if (!findByISBN(book.getISBN())) {
        std::cout << "Book is not in the catalogue" << std::endl;
    } else {
        books[book.getISBN()] = book;
    }
};

void Catalogue::addTransaction(const Transaction &transaction) {
    transactions.push_back(transaction);
};



