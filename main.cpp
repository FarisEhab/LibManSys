#include <iostream>
#include "AuthManager.h"
#include "Catalogue.h"
#include "Book.h"
#include "User.h"

int main() {
    AuthManager authManager;
    int choice;
    bool success = false;

    do {
        std::cout << "1. Sign Up \n2. Log In \n3. Exit" << std::endl;
        std::cin >> choice;
        std::string username, password;
        bool isStaff = false;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Are you a staff member? (1 for Yes, 0 for No): ";
                std::cin >> isStaff;
                if (isStaff) {
                    if (authManager.signUp(username, password)) {
                        std::cout << "Staff signed up successfully" << std::endl;
                    }
                } else {
                    if (authManager.signUp(username, password)) {
                        std::cout << "Reader signed up successfully" << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (authManager.logIn(username, password)) {
                    success = true;
                    if (authManager.isStaff(username)) {
                        std::cout << "Logged in as Staff" << std::endl;
                        int staffChoice;
                        do {
                            std::cout << "1. Add Book \n2. Remove Book \n3. Update Book \n4. Log Out" << std::endl;
                            std::cin >> staffChoice;
                            switch (staffChoice) {
                                case 1: {
                                    std::string ISBN, title;
                                    Author author;
                                    int numCopies;
                                    BookCategory category;
                                    std::cout << "Enter ISBN: ";
                                    std::cin >> ISBN;
                                    std::cout << "Enter title: ";
                                    std::cin >> title;
                                    // Assume author and category are set appropriately
                                    std::cout << "Enter number of copies: ";
                                    std::cin >> numCopies;
                                    Staff::addBook(ISBN, title, author, numCopies, category);
                                    break;
                                }
                                case 2: {
                                    std::string ISBN;
                                    std::cout << "Enter ISBN of the book to remove: ";
                                    std::cin >> ISBN;
                                    if (Catalogue::findByISBN(ISBN)) {
                                        Book book; // Assume book is retrieved appropriately
                                        Staff::removeBook(book);
                                    } else {
                                        std::cout << "Book not found" << std::endl;
                                    }
                                    break;
                                }
                                case 3: {
                                    std::string ISBN;
                                    std::cout << "Enter ISBN of the book to update: ";
                                    std::cin >> ISBN;
                                    if (Catalogue::findByISBN(ISBN)) {
                                        Book book; // Assume book is retrieved and updated appropriately
                                        Staff::updateBook(book);
                                    } else {
                                        std::cout << "Book not found" << std::endl;
                                    }
                                    break;
                                }
                                case 4:
                                    std::cout << "Logging out..." << std::endl;
                                    success = false;
                                    break;
                                default:
                                    std::cout << "Invalid choice... Please try again" << std::endl;
                            }
                        } while (staffChoice != 4);
                    } else {
                        std::cout << "Logged in as Reader" << std::endl;
                        int readerChoice;
                        do {
                            std::cout << "1. Borrow Book \n2. Log Out" << std::endl;
                            std::cin >> readerChoice;
                            switch (readerChoice) {
                                case 1: {
                                    std::string ISBN;
                                    std::cout << "Enter ISBN of the book to borrow: ";
                                    std::cin >> ISBN;
                                    if (Catalogue::findByISBN(ISBN)) {
                                        Book book; // Assume book is retrieved appropriately
                                        Reader reader(username, password);
                                        reader.borrowBook(book);
                                    } else {
                                        std::cout << "Book not found" << std::endl;
                                    }
                                    break;
                                }
                                case 2:
                                    std::cout << "Logging out..." << std::endl;
                                    success = false;
                                    break;
                                default:
                                    std::cout << "Invalid choice... Please try again" << std::endl;
                            }
                        } while (readerChoice != 2);
                    }
                }
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice... Please try again" << std::endl;
        }
    } while (choice != 3 && !success);

    return 0;
}