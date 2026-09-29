// In-memory DAO and CRUD
//
// DAO means Data Access Object: a data-access pattern, not a paradigm. BookDAO centralizes
// create, read, update and delete (CRUD). Call its operations without manipulating storage
// directly. For now, view vector as a growing collection; DSA studies it in detail. The
// educational DAO accepts at most 10,000 books, consistently across creation, saving and
// loading.
//
// Analogy: The librarian knows where books are stored. Ask for a book by its ID without
// inspecting every shelf.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add two books and list dao.all(). Verify that updating an unknown ID returns false.

#include "../BookDAO.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    BookDAO dao;
    if (!(dao.create({1, "Introductory C++"}))) {
        return 1;
    }
    if (dao.create({1, "Duplicate"})) {
        return 1;
    }
    if (dao.create({0, "Invalid"})) {
        return 1;
    }
    if (!(dao.update(1, "C++ step by step"))) {
        return 1;
    }
    // The query returns an observer of the catalog. Modifying the vector may invalidate it.
    const Book* book = dao.findById(1);

    cout << book->title << "\n";
    if (!(dao.remove(1))) {
        return 1;
    }
    if (!(!dao.findById(1) && !dao.remove(1))) {
        return 1;
    }
}
