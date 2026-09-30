// Binary search trees (BST)
//
// We will add a rule to the tree: smaller numbers go left and larger ones go right. When searching,
// we choose one branch and discard the other. We call this a binary search tree, or BST. Here we do
// not store duplicates. When removing a node with two children, we find a replacement that
// preserves the ordering. If the tree becomes a chain, we must traverse many nodes; calling it a
// tree does not guarantee fast searches.
//
// Practice: We will store numbers ordered by branches.
// - We will add values smaller and larger than the root without duplicates.
// - We will search for a present and an absent value; then remove one.

#include "../Tree.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    // When removing a root with two children, we use the smallest value in its right branch to
    // preserve ordering.
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
