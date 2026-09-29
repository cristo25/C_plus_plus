#include <iostream>

using namespace std;

int price(int option, bool isStudent) {
    int base = 0;
    switch (option) {
        case 1:
            base = 20;
            break;
        case 2:
            base = 30;
            break;
        default:
            return -1;
    }
    if (isStudent) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Drink 2 with discount: " << price(2, true) << "\n";
}
