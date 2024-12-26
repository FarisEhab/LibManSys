//
// Created by MacBook on 25/12/2024.
//

#include "Book.h"



Book::Book(const std::string& ISBN, const std::string& title, const Author& author, int numCopies, BookCategory category) {
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->numCopies = numCopies;
    this->category = category;
}

std::string Book::getISBN() const {
    return ISBN;
}

//TODO:: Implement the isAvailable method after implementing the Catalogue class