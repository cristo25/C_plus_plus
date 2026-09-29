// Integration: a library using objects
//
// Encapsulate a DAO using composition and practice polymorphism with two derived views. Reuse
// the previous header. unique_ptr owns the view, and a virtual destructor allows releasing its
// concrete type.
//
// Analogy: The library has a librarian and shows its catalog through either a detailed service
// window or a summary window.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a view that shows only titles and reuse the same DAO.

#include "../09_DAO/BookDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace course;

class Library {
    // Composition: the library delegates storage to the DAO.
    BookDAO dao;

public:
    bool registerBook(const Book& book) {
        return dao.create(book);
    }
    const BookDAO& catalog() const {
        return dao;
    }
};

class View {
public:
    virtual ~View() = default;
    virtual string render(const BookDAO& dao) const = 0;
};
class DetailView : public View {
public:
    string render(const BookDAO& dao) const override {
        string text;
        for (const auto& book : dao.all()) {
            text += to_string(book.id) + ": " + book.title + "\n";
        }
        return text;
    }
};
class SummaryView : public View {
public:
    string render(const BookDAO& dao) const override {
        return "Books: " + to_string(dao.all().size()) + "\n";
    }
};

int main() {
    Library library;
    if (!(library.registerBook({1, "Learn C++"}))) {
        return 1;
    }
    if (library.registerBook({1, "Duplicate"})) {
        return 1;
    }
    // Polymorphism lets one interface show details or a summary; unique_ptr manages its
    // lifetime.
    unique_ptr<View> view = make_unique<DetailView>();

    cout << view->render(library.catalog());
    view = make_unique<SummaryView>();

    cout << view->render(library.catalog());
}
