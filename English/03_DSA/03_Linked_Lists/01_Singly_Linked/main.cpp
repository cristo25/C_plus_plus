// Singly linked list
//
// Every node holds a value and the address of the next node. The last points to nullptr. There
// is no direct index access; traversing and searching cost O(n). The header appends values,
// removes the first matching value and releases all nodes. Appending here costs O(n).
//
// Analogy: A treasure hunt: every card contains a value and a clue pointing to the next card;
// the last says end.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw links before and after removing the first node. Add a contains method.

#include "SinglyLinkedList.h"
#include <iostream>
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
