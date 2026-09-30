// Doubly linked list
//
// We will add a second arrow to each node: one to the next and another to the previous node. This
// lets us traverse in both directions. We also keep the first and last addresses so appending
// adjusts a few arrows without traversing the list. When removing a node we repair both
// connections, like removing a train carriage linked at both ends. We can follow those pointer
// changes in DoublyLinkedList.h.
//
// Practice: We will create a list that can be traversed both ways.
// - We will add three values and show forward and reverse order.
// - We will remove the first or last node without breaking the remaining links.

#include "DoublyLinkedList.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    DoublyLinkedList list;
    // Previous links allow traversal from the tail: 30, 20, 10.
    if (!(list.reversed().empty() && !list.remove(5))) {
        return 1;
    }
    list.append(10);
    list.append(20);
    list.append(30);

    for (int value : list.reversed()) {
        cout << value << ' ';
    }
    cout << "\n";
    if (!(list.remove(20))) {
        return 1;
    }

    if (!(list.remove(10) && list.remove(30))) {
        return 1;
    }

    list.append(40);
}
