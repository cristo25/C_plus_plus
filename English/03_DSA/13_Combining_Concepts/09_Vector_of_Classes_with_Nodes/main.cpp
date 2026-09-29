// 9. A vector contains classes managing nodes
//
// vector<Shelf> holds complete shelves. Each shelf owns a list; each struct
// node stores a Product and owns the next node. Vector growth may move shelves:
// a Shelf* pointing to an element becomes invalid. Managed nodes keep their
// addresses because ownership is transferred. Shelf is not copied: copying
// would require duplicating the chain. Its noexcept move lets the vector
// relocate it. A reference to a relocated shelf would also be invalidated;
// being a reference does not grant address stability.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Add another shelf after reserve and check the borrowed node through the vector.

#include <iostream>
#include <vector>
#include "../Shelf.h"

using namespace std;
using namespace course;

int main() {
    vector<Shelf> shelves;
    shelves.emplace_back("Stationery");
    shelves.at(0).add(Product("Notebook", 300));

    Shelf* shelfAddress = &shelves.at(0);
    const Shelf::Node* nodeAddress = shelfAddress->first();
    cout << "Before growing: " << shelfAddress->getName() << "\n";

    // Clear the shelf card before forcing relocation; we do not reuse it.
    shelfAddress = nullptr;
    shelves.reserve(shelves.capacity() + 1);
    shelves.emplace_back("Books");
    shelves.at(1).add(Product("Book", 500));

    // This node remains alive with the same logical owner and the same address.
    cout << boolalpha << "Node at the same address: " << (nodeAddress == shelves.at(0).first()) << "\n";
    cout << nodeAddress->getProduct().getName() << "\n";
    for (const Shelf& shelf : shelves) {
        cout << shelf.getName() << ": " << shelf.total() << "\n";
    }

    // Clearing destroys the nodes: first clear this list's observer.
    nodeAddress = nullptr;
    shelves.at(0).clear();
}
