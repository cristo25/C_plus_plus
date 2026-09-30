// Variables, types and operators
//
// We will store data in variables. We can picture each variable as a named box: int stores whole
// numbers, double and float store numbers with decimal places, char stores one character, bool
// stores true or false, and string stores text. In count we store the number of notebooks; we
// multiply it by price to get total. With const we protect a value that should stay unchanged.
// Dividing whole numbers drops the decimal part: 5 / 2 gives 2, whereas 5.0 / 2 gives 2.5.
//

// Practice: Let's write a program that calculates a purchase total.
//
// - Store a product name, quantity and price.
// - Calculate and display a total with decimal places.
// - Use const for a price that stays unchanged during the program.

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    // const protects unchanged data; quantity remains a variable we can modify.
    const string product = "Notebook";
    int count = 3;
    const double price = 12.5;
    const char category = 'A';
    const bool available = count > 0;
    const double total = count * price;

    cout << product << ": " << total << "\n";
    cout << category << " available: " << boolalpha << available << "\n";
    // Two integers use integer division: 5 / 2 is 2. A double operand preserves the fraction.
    cout << "Integer division: " << 5 / 2 << "\n";
    cout << "Floating-point division: " << 5.0 / 2 << "\n";
}
