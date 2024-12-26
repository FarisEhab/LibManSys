//
// Created by MacBook on 26/12/2024.
//
#include "Book.h"
#include <chrono>
#include "Transaction.h"
#include "Catalogue.h"

Transaction::Transaction(const Reader &reader, const Book &book, std::chrono::system_clock::time_point dateBorrowed, int allowedDays)
    : reader(reader), book(book), dateBorrowed(dateBorrowed), allowedDays(allowedDays) {
    Catalogue::addTransaction(*this);

}
//TODO:: Check the implementation of the calculateReturnDate function and the calculateFine function
int Transaction::calculateReturnDate(std::chrono::system_clock::time_point currentDate) {
    // Calculate the difference in hours between the current date and the date the book was borrowed
    auto diff = std::chrono::duration_cast<std::chrono::hours>(currentDate - dateBorrowed).count();

    // Calculate the number of days remaining until the book is due
    return allowedDays - (diff / 24);
}

double Transaction::calculateFine(std::chrono::system_clock::time_point currentDate) {
    // Calculate the difference in hours between the current date and the date the book was borrowed
    auto diff = std::chrono::duration_cast<std::chrono::hours>(currentDate - dateBorrowed).count();

    // Calculate the number of days the book is overdue
    int daysOverdue = (diff / 24) - allowedDays;

    // Calculate the fine
    return daysOverdue * 10;
}