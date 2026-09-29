// Recursión
//
// Una función recursiva se llama a sí misma con un problema menor. El caso base detiene las
// llamadas. Sin caso base o sin avance, la pila de llamadas puede agotarse.
//
// Analogía: Abres una caja que contiene otra más pequeña, hasta llegar a una caja vacía.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja las llamadas de factorial(3) y su regreso. Después escribe la versión con
// for.

#include <iostream>
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Usa un numero entre 0 y 12");
    }
    // Caso base: 0! y 1! valen 1. Sin un caso que termine, la recursión no se detendría.
    if (n <= 1) {
        return 1;
    }
    // Cada llamada resuelve un problema menor; al regresar se multiplican los resultados.
    return n * factorial(n - 1);
}

int main() {

    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
