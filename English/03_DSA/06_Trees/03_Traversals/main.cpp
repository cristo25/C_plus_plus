#include "../Tree.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
    for (int value : {4, 2, 6, 1, 3, 5, 7}) {
        tree.insert(value);
    }

    for (Traversal order : {Traversal::Preorder, Traversal::Inorder, Traversal::Postorder}) {
        for (int value : tree.values(order)) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
