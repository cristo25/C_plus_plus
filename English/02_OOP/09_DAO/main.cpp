// DAO: separating data access
//
// Study in-memory CRUD and persistence. The integration example combines CRUD and serialization
// using a string stream without writing files. Definitions inside classes are implicitly inline.
// This DAO uses linear queries and allows at most 10,000 books; a database is a later step when
// needed.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include "BookDAO.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;
using namespace course;

int main() {
    BookDAO original;
    if (!(original.create({1, "Structures"}))) {
        return 1;
    }
    if (!(original.create({2, "Objects"}))) {
        return 1;
    }
    if (!(original.update(2, "Objects and \"classes\""))) {
        return 1;
    }
    if (!(original.remove(1))) {
        return 1;
    }
    // Simulate a file in memory to save and restore without creating disk data.
    stringstream file;
    if (!(original.save(file))) {
        return 1;
    }
    BookDAO copy;
    if (!(copy.load(file))) {
        return 1;
    }
    // assert checks an integration result; it does not perform application operations.
    assert(copy.all().size() == 1);
    assert(copy.findById(2)->title == "Objects and \"classes\"");
    istringstream duplicates("2\n2 \"One\"\n2 \"Two\"\n");
    if (copy.load(duplicates)) {
        return 1;
    }
    assert(copy.all().size() == 1);
    cout << copy.findById(2)->title << "\n";
}
