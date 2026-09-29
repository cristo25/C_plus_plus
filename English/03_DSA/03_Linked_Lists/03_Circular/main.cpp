// Circular linked list
//
// The last node points to the first. Stop on returning to the start; waiting for nullptr would loop
// forever. Keeping the last node lets us append by adjusting a few links without traversing the
// list (O(1)). Searching or removing by value may require inspecting all n nodes (O(n)); n is the
// node count. This variant is singly linked and circular.
//
// Analogy: A wheel of turns returns to the first person after serving the last.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw a single-node ring, which points to itself. Explain why removing it needs a
// special case.

#include "CircularList.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    CircularList turns;
    if (!(turns.values().empty() && !turns.remove(1))) {
        return 1;
    }
    // The last node points to the first. values() returns one lap to avoid an infinite loop.
    turns.append(1);
    turns.append(2);
    turns.append(3);
    if (turns.remove(9)) {
        return 1;
    }
    if (!(turns.remove(2))) {
        return 1;
    }

    for (int turn : turns.values()) {
        cout << turn << ' ';
    }
    cout << "\n";
    if (!(turns.remove(3) && turns.remove(1))) {
        return 1;
    }

    turns.append(4);
}
