// Trees
//
// Distinguish binary trees from binary search trees, then study traversal orders. The
// integration example inserts, searches, traverses and removes. Recursive examples use small
// trees; balancing and iterative traversal are extensions for great depths.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include "Tree.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    // assert checks an integration result; it does not perform application operations.
    assert(tree.values().empty());
    for (int value : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(tree.insert(value))) {
            return 1;
        }
    }
    assert(tree.contains(4));
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
    assert((tree.values() == vector<int>{2, 3, 4, 6, 7, 8}));
    for (int value : {2, 3, 4, 6, 7, 8}) {
        if (!(tree.remove(value))) {
            return 1;
        }
    }
    assert(tree.values().empty());
}
