// Persisting a DAO in a file
//
// We will save the catalog in a file so we can retrieve it later. First we ask the DAO to write its
// books and then read them into another catalog. We append a complete copy each run; while reading,
// we keep the last complete copy. If data is invalid, we report it without replacing the catalog
// with an incomplete reading. To try that case we use istringstream: a tool from <sstream> that
// reads text already in memory as if it came from a file. This lets us test damaged input without
// damaging the real file.
//

#include "../BookDAO.h"
// We read and save files using ifstream and ofstream.
#include <fstream>
#include <iostream>
// We read or write text in memory as if it were a file.
#include <sstream>

using namespace std;
using namespace course;

int main() {
    BookDAO dao;
    if (!(dao.create({1, "C++ with examples"}))) {
        return 1;
    }
    // ponytail: append-only journal; compact if the file grows too large. Append a complete copy;
    // reading restores complete copies in order.
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

    // Rejecting a load preserves the restored catalog instead of leaving partial data.
    istringstream corrupt("1\n1 without_quotes\n");
    if (restored.load(corrupt)) {
        return 1;
    }
    cout << restored.findById(1)->title << "\n";
}
