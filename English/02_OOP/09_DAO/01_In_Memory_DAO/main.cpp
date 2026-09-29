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
    const Book* book = dao.findById(1);

    cout << book->title << "\n";
    if (!(dao.remove(1))) {
        return 1;
    }
    if (!(!dao.findById(1) && !dao.remove(1))) {
        return 1;
    }
}
