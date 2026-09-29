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
