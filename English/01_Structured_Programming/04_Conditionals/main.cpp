// Conditionals
//
// We will combine both ways of making decisions. First we choose a price with switch; then we use
// if to apply a student discount. The price function receives the option and discount eligibility.
// For an unknown option we return -1 as an agreed error signal. We separate two questions: what is
// being bought and which discount applies.
//

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
