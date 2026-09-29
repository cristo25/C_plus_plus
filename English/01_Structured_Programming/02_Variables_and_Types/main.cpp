#include <iostream>
#include <string>

using namespace std;

int main() {
    const string product = "Notebook";
    int count = 3;
    const double price = 12.5;
    const char category = 'A';
    const bool available = count > 0;
    const double total = count * price;

    cout << product << ": " << total << "\n";
    cout << category << " available: " << boolalpha << available << "\n";
    cout << "Integer division: " << 5 / 2 << "\n";
    cout << "Floating-point division: " << 5.0 / 2 << "\n";
}
