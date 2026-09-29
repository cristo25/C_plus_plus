// Binary search trees (BST)
//
// This BST places smaller values on the left and larger ones on the right, rejecting duplicates.
// Insertion, search and removal cost O(h), where h is height. Removing a node with two children
// replaces it with the smallest value in its right subtree. An unbalanced BST may become a
// chain.
//
// Analogy: Each node in a number guide tells you whether to follow smaller or larger values.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Insert already sorted numbers and draw the tree. Compare its height with another
// insertion order.

#include "../Tree.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    // Removing a root with two children uses its successor to preserve the BST rule.
    if (!(!tree.contains(8) && !tree.remove(8))) {
        return 1;
    }
    for (int value : {8, 3, 10, 1, 6}) {
        if (!(tree.insert(value))) {
            return 1;
        }
    }
    if (tree.insert(8)) {
        return 1;
    }

    if (!(tree.remove(8))) {
        return 1; // Root with two children.
    }

    for (int value : tree.values()) {
        cout << value << ' ';
    }
    cout << "\n";
    if (!(tree.remove(1) && tree.remove(3))) {
        return 1; // A leaf, then a node with one child.
    }
}
