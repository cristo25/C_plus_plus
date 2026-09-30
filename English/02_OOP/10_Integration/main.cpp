// Integration: a library using objects
//
// We will build a small library with several cooperating classes. Library contains a DAO for
// storing books. A View decides how to show them: DetailView prints their details and SummaryView
// shows the count. We request the catalog in the same way even when changing views. This brings
// together composition, protected data, const queries and polymorphism. With unique_ptr we make
// clear who releases the view when we stop using it.
//

#include "../09_DAO/BookDAO.h"
#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store and work with text using string.
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
    if (!library.registerBook({1, "Learn C++"})) {
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

// Integration practice: let's add another way to show the library.
// - Create a TitleView that shows only the book titles.
// - Register two books and show their titles through a View pointer.
// - Show the summary afterward using the same view variable.
