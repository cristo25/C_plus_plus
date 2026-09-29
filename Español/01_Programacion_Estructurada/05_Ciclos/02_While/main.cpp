// Repetir con while
//
// while comprueba la condición antes de cada vuelta. Puede ejecutarse cero veces; modifica algo
// que permita terminar.
//
// Analogía: Llenas una alcancía mientras no alcanzas la meta.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Cambia la meta a 110. Explica por qué el ahorro final es 125.

#include <iostream>

using namespace std;

int main() {
    int ahorro = 0;
    int semanas = 0;
    // La condición se revisa antes del bloque; semanas cuenta cuántos depósitos hacen falta.
    while (ahorro < 100) {
        ahorro += 25;
        ++semanas;
    }

    cout << semanas << " semanas\n";
}
