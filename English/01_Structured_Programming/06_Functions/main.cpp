// Functions
//
// We will combine functions that calculate with functions that modify. First we obtain a subtotal
// from price and quantity. Then we pass the total by reference to apply a coupon to that same
// variable. We can picture a cash register: one task calculates and another updates the amount.
// This lets us follow each step without putting everything inside main.
//

// Practice: Let's write an integrated purchase program with a coupon.
//
// - Calculate the subtotal in a function that returns a number.
// - Apply the discount through a reference to the total.
// - Keep the discount from making the total negative.
// - Display the subtotal and final total.

#include <iostream>

using namespace std;

// Value parameters are copies; return sends the result back.
int subtotal(int count, int price) {
    return count * price;
}
// int& gives another label to the original total: the discount changes the variable in main.
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
