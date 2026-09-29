// Tree traversals
//
// Preorder visits root, left, right. Inorder visits left, root, right. Postorder visits left,
// right, root. Inorder produces sorted values in a BST. A traversal visits every node, so its work
// grows with the n nodes (O(n)). It also keeps calls waiting to return: there can be one for each
// level on the current path, up to the tree height h (O(h) memory for those calls). The output
// vector needs room for the n results.
//
// Analogy: Visit a house and record each room before its annexes, between its annexes, or after
// them.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the tree and reproduce each traversal with arrows before running it.

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

    // Preorder: root first. Inorder: root between branches. Postorder: root last.
    for (Traversal order : {Traversal::Preorder, Traversal::Inorder, Traversal::Postorder}) {
        for (int value : tree.values(order)) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
