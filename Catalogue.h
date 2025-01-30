//
// Created by MacBook on 26/12/2024.
//

#ifndef CATALOGUE_H
#define CATALOGUE_H
#include <map>

#include "Book.h"
#include "Transaction.h"

//static class to store all the books and transactions
class Catalogue {
private:
    static std::map<std::string, Book> books; // map of ISBN to Book
    static std::vector<Transaction> transactions; // list of transactions

public:
    // add a book to the catalogue
    static void addBook(const std::string &ISBN, const std::string &title,
        const Author &author, const BookCategory category);

    // remove a book from the catalogue
    static void removeBook(const Book &book);

    // update book details
    static void updateBook(const Book& book);

    // search for a book by ISBN
    static bool findByISBN(const std::string& ISBN);

    //add a transaction
    static void addTransaction(const Transaction& transaction);
};



#endif //CATALOGUE_H
