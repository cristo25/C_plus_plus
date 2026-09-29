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
