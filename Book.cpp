//
// Created by MacBook on 25/12/2024.
//

#include "Book.h"



Book::Book(const std::string& ISBN, const std::string& title, const Author& author, BookCategory category) {
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->category = category;
    numCopies = 1;

}

std::string Book::getISBN() const {
    return ISBN;
}

bool Book::isAvailable() const {
    if(numCopies > 0){
        return true;
    }
    return false;
}

int Book::getNumCopies() const {
    return numCopies;
}

void Book::setNumCopies(int numCopies) {
    this->numCopies = numCopies;
}