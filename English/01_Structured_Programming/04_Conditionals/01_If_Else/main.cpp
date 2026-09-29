#include <iostream>

using namespace std;

bool mayEnter(int age, bool hasTicket) {
    return age >= 18 && hasTicket;
}

int main() {

    if (mayEnter(20, true)) {
        cout << "Entry allowed\n";
    } else {
        cout << "Entry denied\n";
    }
}
