// Linked lists
//
// All three implementations store integers to focus on links and ownership. Manual new/delete
// teaches the mechanism; standard containers manage storage for common applications. The
// integration example uses all three headers and removes 20 from each list. Compare traversals,
// then remove the first node, the last node and the only node.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

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
    // assert checks an integration result; it does not perform application operations.
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
