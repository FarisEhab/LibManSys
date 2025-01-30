//
// Created by MacBook on 25/12/2024.
//

#ifndef BOOK_H
#define BOOK_H
#include <string>

#include "Author.h"

enum class BookCategory {
    Science,
    Engineering,
    Mathematics,
    Literature,
    History,
    Art,
    Technology,
};


class Book {
private:
    std::string ISBN;
    std::string title;
    Author author;
    int numCopies;
    BookCategory category;

public:
    // Constructor
    Book();
    Book(const std::string& ISBN, const std::string& title,
        const Author& author,
        BookCategory category);

    std::string getISBN() const;
    // to check if the book is available in the cataloge or not
    bool isAvailable() const;

    int getNumCopies() const;

    void setNumCopies(int numCopies);
};



#endif //BOOK_H
