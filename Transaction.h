//
// Created by MacBook on 26/12/2024.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Book.h"
#include "User.h"
#include <chrono>

class Transaction {
private:
    Reader reader;
    Book book;
    std::chrono::system_clock::time_point dateBorrowed;
    int allowedDays;

public:
    Transaction(const Reader &reader, const Book &book, std::chrono::system_clock::time_point dateBorrowed, int allowedDays);
    double calculateFine(std::chrono::system_clock::time_point currentDate);
    int calculateReturnDate(std::chrono::system_clock::time_point currentDate);
};



#endif //TRANSACTION_H
