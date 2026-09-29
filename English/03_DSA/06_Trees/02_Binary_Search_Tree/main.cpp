#include "../Tree.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Tree tree;
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
