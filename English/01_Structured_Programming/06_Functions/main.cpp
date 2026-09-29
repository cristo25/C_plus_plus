// Functions
//
// Split a problem into small tasks. The integration example calculates a subtotal by value and
// applies a coupon by reference; the total is 50.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <iostream>

using namespace std;

// Value parameters are copies; return sends the result back.
int subtotal(int count, int price) {
    return count * price;
}
// int& aliases the original total: the discount changes the variable in main.
void applyCoupon(int& total) {
    if (total >= 50) {
        total -= 10;
    }
}

int main() {
    int total = subtotal(3, 20);
    applyCoupon(total);

    int small = 20;
    applyCoupon(small);

    cout << "Total: " << total << "\n";
}
