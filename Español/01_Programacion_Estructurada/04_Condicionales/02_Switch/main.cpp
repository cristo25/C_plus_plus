// Elegir con switch
//
// switch elige entre valores concretos de un entero, carácter o enumeración. break termina un
// caso; default atiende valores desconocidos.
//
// Analogía: Un menú de restaurante tiene opciones numeradas. Cada número lleva a una
// preparación.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una tercera bebida. Prueba también la opción 0.

#include <iostream>
#include <string>

using namespace std;

string bebida(int opcion) {
    // Cada case devuelve una bebida. return termina la función, por eso aquí no hace falta
    // break.
    switch (opcion) {
        case 1:
            return "Agua";
        case 2:
            return "Cafe";
        default:
            return "Opcion invalida";
    }
}

int main() {

    cout << bebida(2) << "\n";
}
