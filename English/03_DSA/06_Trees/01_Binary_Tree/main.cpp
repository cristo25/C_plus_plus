// Binary trees: roots, children and leaves
//
// We will link nodes into branches. In a binary tree each node can have at most one left child and
// one right child. We call the first node the root and a node with no children a leaf. Here we are
// building the shape only: having two branches does not require sorted numbers. To count, we add
// the current node and both branches recursively. We use unique_ptr so each branch releases its
// nodes when finished.
//

#include <iostream>
// We use unique_ptr to release its managed object automatically.
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
