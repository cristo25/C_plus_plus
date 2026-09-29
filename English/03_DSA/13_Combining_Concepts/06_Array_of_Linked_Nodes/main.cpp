// 6. Nodes inside an array, connected by pointers
//
// We will store complete nodes in an array and link them with pointers. Each Node contains a
// Product and next, the next node's address. The boxes occupy positions 0, 1 and 2, but arrows can

#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

struct Node {
    Product product;
    Node* next = nullptr;
};

int main() {
    Node nodes[3]{
        Node{Product("Notebook", 300)},
        Node{Product("Pencil", 100)},
        Node{Product("Book", 500)}
    };
    nodes[0].next = &nodes[2];
    nodes[2].next = &nodes[1];

    const Node* cursor = &nodes[0];
    size_t visited = 0;
    // With three nodes, more than three visits means repeating a node: a cycle.
    while (cursor != nullptr && visited < 3) {
        cout << cursor->product.getName() << "\n";
        cursor = cursor->next;
        ++visited;
    }
    if (cursor != nullptr) {
        cerr << "The links form a cycle\n";
        return 1;
    }
}
