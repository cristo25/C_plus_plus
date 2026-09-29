#include "../09_DAO/BookDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace course;

class Library {
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
    unique_ptr<View> view = make_unique<DetailView>();

    cout << view->render(library.catalog());
    view = make_unique<SummaryView>();

    cout << view->render(library.catalog());
}
