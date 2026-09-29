#include <iostream>
#include <string>

using namespace std;

int main() {
    const string producto = "Cuaderno";
    int cantidad = 3;
    const double precio = 12.5;
    const char categoria = 'A';
    const bool disponible = cantidad > 0;
    const double total = cantidad * precio;

    cout << producto << ": " << total << "\n";
    cout << categoria << " disponible: " << boolalpha << disponible << "\n";
    cout << "Division entera: " << 5 / 2 << "\n";
    cout << "Division decimal: " << 5.0 / 2 << "\n";
}
