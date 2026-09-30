// Singly linked list
//
// We will build a chain of boxes called nodes. Each node stores a value and a pointer to the next
// node, like a note showing where the next box is. The list stores the first address; the last
// points to nullptr. To search we follow the notes one at a time and may visit all nodes. When
// removing a node we join its previous neighbor to the next before releasing the box. We can see
// those steps inside SinglyLinkedList.h.
//
// Practice: We will create a list that advances from node to node.
// - We will add three values and traverse them from the first node.
// - We will remove one value and check that the link still works.

#include "SinglyLinkedList.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    SinglyLinkedList list;
    if (!(list.values().empty() && !list.remove(99))) {
        return 1;
    }
    // The nodes will form 10 -> 20 -> 30; the header implements the links.
    list.append(10);
    list.append(20);
    list.append(30);
    if (!(list.remove(20))) {
        return 1;
    }

    for (int value : list.values()) {
        cout << value << ' ';
    }
    cout << "\n";
    if (!(list.remove(10) && list.remove(30))) {
        return 1;
    }
}
