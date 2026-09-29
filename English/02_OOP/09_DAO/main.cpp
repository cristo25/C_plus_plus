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
    stringstream file;
    if (!(original.save(file))) {
        return 1;
    }
    BookDAO copy;
    if (!(copy.load(file))) {
        return 1;
    }
    assert(copy.all().size() == 1);
    assert(copy.findById(2)->title == "Objects and \"classes\"");
    istringstream duplicates("2\n2 \"One\"\n2 \"Two\"\n");
    if (copy.load(duplicates)) {
        return 1;
    }
    assert(copy.all().size() == 1);
    cout << copy.findById(2)->title << "\n";
}
