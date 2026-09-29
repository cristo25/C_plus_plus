// 8. A class manages struct nodes
//
// We will keep the chain and its rules inside Shelf. Each node contains a Product and a unique_ptr
// to the next node; the shelf is responsible for the first. From outside we request additions or
// queries without directly changing links. We can picture a shelf keeper arranging boxes and
// lending their labels for reading. first() and nextNode() lend addresses; getProduct() lends a
// read-only reference. Emptying the shelf invalidates those queries because their boxes no longer
// exist.
//

#include <iostream>
#include "../Shelf.h"

using namespace std;
using namespace course;

int main() {
    Shelf shelf("Stationery");
    shelf.add(Product("Notebook", 300));
    shelf.add(Product("Pencil", 100));

    const Shelf::Node* cursor = shelf.first();
    while (cursor != nullptr) {
        cout << cursor->getProduct().getName() << "\n";
        cursor = cursor->nextNode();
    }
    cout << "Total in cents: " << shelf.total() << "\n";
}
