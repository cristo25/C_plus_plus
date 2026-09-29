// Binary trees: roots, children and leaves
//
// A tree connects nodes without cycles. The root has no parent; leaves have no children. A
// binary tree allows at most two children per node. A binary tree need not order its values.
//
// Analogy: An organization chart starts with one manager and branches into subordinates, at most
// two per manager here.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the tree, identify its leaves and add a grandchild.

#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    explicit Node(int value) : value(value) {
    }
};

int countNodes(const Node* node) {
    // An empty branch contributes zero; each node counts itself plus its two children's nodes.
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->left.get()) + countNodes(node->right.get());
}

int main() {
    auto root = make_unique<Node>(10);
    root->left = make_unique<Node>(20); // Binary, without the search-tree ordering rule.
    root->right = make_unique<Node>(5);

    cout << "Nodes: " << countNodes(root.get()) << "\n";
}
