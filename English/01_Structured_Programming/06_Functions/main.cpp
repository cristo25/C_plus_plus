#include <iostream>

using namespace std;

int subtotal(int count, int price) {
    return count * price;
}
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
