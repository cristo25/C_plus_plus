// Repetir con do while
//
// do while evalúa la condición después del cuerpo, por lo que siempre ejecuta al menos una
// vuelta.
//
// Analogía: Pruebas una llave al menos una vez antes de decidir si necesitas seguir intentando.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Empieza con intentos = 3 y observa que el cuerpo se ejecuta igualmente.

#include <iostream>

using namespace std;

int main() {
    int intentos = 0;
    // Primero hacemos un intento; luego decidimos si repetir. Siempre habrá al menos uno.
    do {
        ++intentos;
        cout << "Intento " << intentos << "\n";
    } while (intentos < 3);
}
