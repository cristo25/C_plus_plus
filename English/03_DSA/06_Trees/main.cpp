// Trees
//
// We will integrate tree operations: insertion, search, traversal and removal. We use Tree.h to
// follow the same links in every case. First we check an empty tree, add values, compare its
// traversals and finally remove all nodes. We can picture maintaining a tree of folders: each
// change must preserve access to branches that still exist.
//
// Practice: We will manage numbers in a tree.
// - We will add numbers without duplicates and show all three traversals.
// - We will remove the root and check that the other numbers remain available.

#include "Tree.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    if (!(tree.values().empty())) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    for (int value : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(tree.insert(value))) {
            return 1;
        }
    }
    if (!(tree.contains(4))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    // The tree stays the same; change when the root is visited relative to its two branches.
    for (Traversal order : {Traversal::Preorder, Traversal::Inorder, Traversal::Postorder}) {
        for (int value : tree.values(order)) {
            cout << value << ' ';
        }
        cout << "\n";
    }
    if (!(tree.remove(5))) {
        return 1;
    }
    if (!((tree.values() == vector<int>{2, 3, 4, 6, 7, 8}))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    for (int value : {2, 3, 4, 6, 7, 8}) {
        if (!(tree.remove(value))) {
            return 1;
        }
    }
    if (!(tree.values().empty())) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
}
