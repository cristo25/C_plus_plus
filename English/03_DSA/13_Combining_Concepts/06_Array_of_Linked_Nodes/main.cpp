// 6. Nodes inside an array, connected by pointers
//
// Node contains a Product and a card pointing to another Node. The array
// stores complete nodes and manages their lifetimes. Links only describe
// the visit order: 0 -> 2 -> 1, which can differ from physical array order.
// The last link is nullptr. Do not use delete: no node was created with new.
// Copying this array copies the links unchanged: they would still point to the
// original array. An independent copy would need to rebuild its links.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Link 2 -> 0 -> 1 and change the start. Why is there a visit limit?

#include <array>
#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

struct Node {
    Product product;
    Node* next = nullptr;
};

int main() {
    array<Node, 3> nodes{
        Node{Product("Notebook", 300)},
        Node{Product("Pencil", 100)},
        Node{Product("Book", 500)}
    };
    nodes.at(0).next = &nodes.at(2);
    nodes.at(2).next = &nodes.at(1);

    const Node* cursor = &nodes.at(0);
    size_t visited = 0;
    // With three nodes, more than three visits means repeating a node: a cycle.
    while (cursor != nullptr && visited < nodes.size()) {
        cout << cursor->product.getName() << "\n";
        cursor = cursor->next;
        ++visited;
    }
    if (cursor != nullptr) {
        cerr << "The links form a cycle\n";
        return 1;
    }
}
