// Conditionals
//
// Choose execution paths, then combine switch and if to calculate a discounted price. The
// integration example produces 25.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <iostream>

using namespace std;

int price(int option, bool isStudent) {
    int base = 0;
    // switch selects a price by option; break prevents falling through to the next case.
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
    // After choosing the price, apply the discount only when its condition holds.
    if (isStudent) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Drink 2 with discount: " << price(2, true) << "\n";
}
