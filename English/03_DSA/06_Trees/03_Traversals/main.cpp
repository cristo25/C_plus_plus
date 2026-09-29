// Tree traversals
//
// We will visit the same tree in three orders. In preorder we read the node before its branches; in
// inorder we read left branch, node, then right branch; in postorder we leave the node until last.
// In a search tree, inorder displays sorted numbers. We can picture visiting the same rooms but
// recording each name on entry, midway or on exit. In all three cases we visit all n nodes (O(n)).
//

#include "../Tree.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    for (int value : {4, 2, 6, 1, 3, 5, 7}) {
        tree.insert(value);
    }

    // Preorder: root first. Inorder: root between branches. Postorder: root last.
    for (Traversal order : {Traversal::Preorder, Traversal::Inorder, Traversal::Postorder}) {
        for (int value : tree.values(order)) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
