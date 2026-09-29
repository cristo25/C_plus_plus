// Variables, tipos y operadores
//
// Declara int, double, char, bool y string. Usa const para datos que no cambian. La división
// entre enteros descarta la parte decimal; convierte un operando a double cuando necesites
// conservarla.
//
// Analogía: Una variable es una caja etiquetada; su tipo determina qué puede guardar. const pone
// un sello que impide cambiar el contenido.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Calcula el precio de cinco productos. Compara 7 / 2 con 7.0 / 2.
// También muestra división entera 2 y decimal 2.5.

#include <iostream>
#include <string>

using namespace std;

int main() {
    // const protege los datos que no cambian; cantidad sigue siendo una variable modificable.
    const string producto = "Cuaderno";
    int cantidad = 3;
    const double precio = 12.5;
    const char categoria = 'A';
    const bool disponible = cantidad > 0;
    const double total = cantidad * precio;

    cout << producto << ": " << total << "\n";
    cout << categoria << " disponible: " << boolalpha << disponible << "\n";
    // Dos enteros producen división entera: 5 / 2 da 2. Un operando double conserva la fracción.
    cout << "Division entera: " << 5 / 2 << "\n";
    cout << "Division decimal: " << 5.0 / 2 << "\n";
}
