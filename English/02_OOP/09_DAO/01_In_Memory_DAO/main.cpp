// In-memory DAO and CRUD
//
// We will bring storing, finding, updating and removing books together in BookDAO. We can picture a
// catalog keeper: we request a book by its id, a number identifying it. DAO is the usual name for a
// class dedicated to data access. Here we keep books in a vector, so they disappear when the
// program ends. find lends a pointer to a book, or returns nullptr if it is missing. We check
// before reading it; after changing the catalog we find it again because the vector may move its
// books.
//

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
    // We receive a borrowed catalog address. After changing its books, we search again before using
    // an address.
    const Book* book = dao.findById(1);

    cout << book->title << "\n";
    if (!(dao.remove(1))) {
        return 1;
    }
    if (!(!dao.findById(1) && !dao.remove(1))) {
        return 1;
    }
}
