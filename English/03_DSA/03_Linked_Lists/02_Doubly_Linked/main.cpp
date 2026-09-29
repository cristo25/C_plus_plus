#include "DoublyLinkedList.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    DoublyLinkedList list;
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
