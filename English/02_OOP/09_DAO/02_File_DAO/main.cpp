// Persisting a DAO in a file
//
// save serializes a snapshot and load validates it before replacing memory contents. quoted
// preserves spaces and quotes. Each snapshot begins with its book count. The example appends
// snapshots and reads the latest complete one. It reports damaged snapshots without silently
// discarding them.
//
// Analogy: The librarian photographs the catalog at closing time and restores its latest
// photograph when reopening.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Save a title containing quotes. Duplicate an ID in a copy of the file and verify
// rejection.

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
    // Append a snapshot; reading restores complete snapshots in order.
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
