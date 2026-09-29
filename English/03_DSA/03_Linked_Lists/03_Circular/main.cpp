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
