// Linked lists
//
// We will compare all three lists using the same numbers. In the singly linked list we follow one
// arrow, in the doubly linked list we can go back, and in the circular list we return to the
// beginning. We insert 10, 20 and 30, remove 20 and check what remains. The main difference is how
// we link nodes and when traversal stops. We can draw the same three boxes and change only their
// arrows to understand it.
//

#include "01_Singly_Linked/SinglyLinkedList.h"
#include "02_Doubly_Linked/DoublyLinkedList.h"
#include "03_Circular/CircularList.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    SinglyLinkedList singly;
    DoublyLinkedList doubly;
    CircularList circular;
    // Use the same values to compare the links of all three lists.
    for (int value : {10, 20, 30}) {
        singly.append(value);
        doubly.append(value);
        circular.append(value);
    }
    if (!(singly.remove(20) && doubly.remove(20) && circular.remove(20))) {
        return 1;
    }
    const vector<int> expected{10, 30};
    if (!(singly.values() == expected && doubly.values() == expected)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(circular.values() == expected)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!((doubly.reversed() == vector<int>{30, 10}))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << "Simple: ";
    for (int value : singly.values()) {
        cout << value << ' ';
    }
    cout << "\nDoubly linked, reversed: ";
    for (int value : doubly.reversed()) {
        cout << value << ' ';
    }
    cout << "\nCircular (one lap): ";
    for (int value : circular.values()) {
        cout << value << ' ';
    }
    cout << "\n";
}
