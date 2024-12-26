cmake_minimum_required(VERSION 3.28)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagementSystem main.cpp
        Book.h
        Author.h
        Author.cpp
        Book.cpp
        Library.h
        User.h
        User.cpp
        AuthManager.h
        AuthManager.cpp
        Library.cpp
        Transaction.cpp
        Catalogue.h
        Catalogue.cpp
)
