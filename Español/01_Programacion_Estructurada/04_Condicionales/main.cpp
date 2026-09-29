// Condicionales
//
// Aprende a elegir caminos y luego calcula un precio combinando switch e if. Resultado del
// integrador: 25.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>

using namespace std;

int precio(int opcion, bool estudiante) {
    int base = 0;
    // switch elige un precio por opción; break impide pasar al siguiente caso.
    switch (opcion) {
        case 1:
            base = 20;
            break;
        case 2:
            base = 30;
            break;
        default:
            return -1;
    }
    // Después de elegir el precio, aplicamos el descuento solo si se cumple la condición.
    if (estudiante) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Bebida 2 con descuento: " << precio(2, true) << "\n";
}
