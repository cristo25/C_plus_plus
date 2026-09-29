#include "Tree.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    assert(tree.values().empty());
    for (int value : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(tree.insert(value))) {
            return 1;
        }
    }
    assert(tree.contains(4));
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
