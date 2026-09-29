// Circular linked list
//
// We will close the chain into a circle: the last node points back to the first. We can picture
// players taking repeated turns. Since we do not reach nullptr after one lap, we stop when we
// return to the start. We keep the last node to append with a few changes (O(1)). Removing the only
// node leaves an empty list; removing any other node keeps the circle closed.
//

#include "CircularList.h"
#include <iostream>
// We store a collection that can grow using vector.
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
