// DAO: separating data access
//
// We will follow the catalog's whole workflow: create books, change a title, remove a book and
// restore saved data. Here we use stringstream from <sstream> as a temporary notebook in memory: we
// can write into it and read back without creating a disk file. We then try input with repeated
// ids. Our rule is simple: if we cannot restore every record correctly, we keep the catalog we
// already had.
//

#include "BookDAO.h"
#include <iostream>
// We read or write text in memory as if it were a file.
#include <sstream>

using namespace std;
using namespace course;

int main() {
    BookDAO original;
    if (!original.create({1, "Structures"})) {
        return 1;
    }
    if (!original.create({2, "Objects"})) {
        return 1;
    }
    if (!original.update(2, "Objects and \"classes\"")) {
        return 1;
    }
    if (!original.remove(1)) {
        return 1;
    }
    // Simulate a file in memory to save and restore without creating disk data.
    stringstream file;
    if (!original.save(file)) {
        return 1;
    }
    BookDAO copy;
    if (!copy.load(file)) {
        return 1;
    }
    if (copy.all().size() != 1) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    const Book* book = copy.findById(2);
    if (book == nullptr || book->title != "Objects and \"classes\"") {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    istringstream duplicates("2\n2\nOne\n2\nTwo\n");
    if (copy.load(duplicates)) {
        return 1;
    }
    if (copy.all().size() != 1) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << book->title << "\n";
}

// Integration practice: let's manage and restore a catalog of three books.
// - Change one title, remove one book and save the remaining books.
// - Load the data into another catalog and check its titles.
// - Try repeated data and keep the old catalog if loading fails.
