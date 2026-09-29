#include "01_Singly_Linked/SinglyLinkedList.h"
#include "02_Doubly_Linked/DoublyLinkedList.h"
#include "03_Circular/CircularList.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    SinglyLinkedList singly;
    DoublyLinkedList doubly;
    CircularList circular;
    for (int value : {10, 20, 30}) {
        singly.append(value);
        doubly.append(value);
        circular.append(value);
    }
    if (!(singly.remove(20) && doubly.remove(20) && circular.remove(20))) {
        return 1;
    }
    const vector<int> expected{10, 30};
    assert(singly.values() == expected && doubly.values() == expected);
    assert(circular.values() == expected);
    assert((doubly.reversed() == vector<int>{30, 10}));
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
