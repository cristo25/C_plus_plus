// Repetir con for
//
// for reúne inicio, condición y avance. Es apropiado cuando conoces cuántas repeticiones
// necesitas.
//
// Analogía: Recorres cinco casilleros, uno por uno, sin saltarte ninguno.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Imprime la tabla del 7 con un ciclo de diez repeticiones.

#include <iostream>

using namespace std;

int sumaHasta(int limite) {
    int suma = 0;
    // Empieza en 1, continúa hasta limite y aumenta numero después de cada vuelta.
    for (int numero = 1; numero <= limite; ++numero) {
        suma += numero;
    }
    return suma;
}

int main() {

    cout << sumaHasta(5) << "\n";
}
