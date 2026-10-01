// 9. A vector contains classes managing nodes
//
// We will store several shelves in a vector. Each shelf contains nodes and each node a product: we
// follow those layers one at a time. Growing the vector can move a shelf, so we clear pointers to
// the shelf itself before adding another shelf. Its nodes were created separately and do not move
// when their manager changes location. We can therefore keep a node query while the node still
// exists. Emptying its shelf destroys the node, so we must stop using that query.
//
// Practice: We will store several shelves with nodes in a vector.
// - We will add products to two shelves.
// - We will grow the vector and inspect a node while it still exists.

#include <iostream>
// We store a collection that can grow using vector.
#include <vector>
#include "../Shelf.h"

using namespace std;
using namespace course;

int main() {
    vector<Shelf> shelves;
    shelves.push_back(Shelf("Stationery"));
    shelves[0].add(Product("Notebook", 300));

    Shelf* shelfAddress = &shelves[0];
    const Shelf::Node* nodeAddress = shelfAddress->first();
    cout << "Before growing: " << shelfAddress->getName() << "\n";

    // Clear the shelf card before adding another shelf; we do not reuse it.
    shelfAddress = nullptr;
    shelves.push_back(Shelf("Books"));
    shelves[1].add(Product("Book", 500));

    // This node remains alive with the same logical owner and the same address.
    cout << boolalpha << "Node at the same address: " << (nodeAddress == shelves[0].first()) << "\n";
    cout << nodeAddress->getProduct().getName() << "\n";
    for (const Shelf& shelf : shelves) {
        cout << shelf.getName() << ": " << shelf.total() << "\n";
    }

    // Clearing destroys the nodes: first clear this list's observer.
    nodeAddress = nullptr;
    shelves[0].clear();
}
