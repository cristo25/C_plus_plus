// Variables, types and operators
//
// Declare int, double, char, bool and string. Use const for values that do not change. Integer
// division discards the fractional part; convert an operand to double to keep it.
//
// Analogy: A variable is a labeled box. Its type determines what it can hold. const seals its
// contents.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Compute the price of five products. Compare 7 / 2 with 7.0 / 2.
// Also prints integer division 2 and floating-point division 2.5.

#include <iostream>
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
