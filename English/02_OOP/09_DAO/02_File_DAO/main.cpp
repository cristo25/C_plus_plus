#include "../BookDAO.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace course;

int main() {
    BookDAO dao;
    if (!(dao.create({1, "C++ with examples"}))) {
        return 1;
    }
    // ponytail: append-only journal; compact if the file grows too large.
    ofstream output("books_demo.txt", ios::app);
    if (!output || !dao.save(output)) {
        cerr << "Could not save the catalog.\n";
        return 1;
    }
    output.close();
    if (!output) {
        cerr << "Failed to close the file.\n";
        return 1;
    }

    ifstream input("books_demo.txt");
    if (!input) {
        cerr << "Could not open the catalog.\n";
        return 1;
    }
    BookDAO restored;
    while (input >> ws && input.peek() != char_traits<char>::eof()) {
        if (!restored.load(input)) {
            cerr << "Incomplete or invalid snapshot.\n";
            return 1;
        }
    }
    if (input.bad()) {
        cerr << "Read error.\n";
        return 1;
    }

    istringstream corrupt("1\n1 without_quotes\n");
    if (restored.load(corrupt)) {
        return 1;
    }
    cout << restored.findById(1)->title << "\n";
}
