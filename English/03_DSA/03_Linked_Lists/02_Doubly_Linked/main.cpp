// Doubly linked list
//
// Each node knows its previous and next node. Keeping a head and tail lets us append by adjusting a
// fixed number of links, without traversing the list (O(1)). We can also traverse in either
// direction. Searching for a value may require inspecting all n nodes (O(n)); unlinking an already
// located node adjusts its neighboring links.
//
// Analogy: Train cars have couplings at both ends, allowing travel in either direction.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the two links changed when removing a middle node.

#include "DoublyLinkedList.h"
#include <iostream>
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
