// Funciones
//
// Divide un problema en tareas pequeñas. El integrador calcula un subtotal por valor y aplica un
// cupón por referencia; el total es 50.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>

using namespace std;

// Los parámetros por valor son copias; el resultado regresa con return.
int subtotal(int cantidad, int precio) {
    return cantidad * precio;
}
// int& es un alias del total original: el descuento sí cambia la variable de main.
void aplicarCupon(int& total) {
    if (total >= 50) {
        total -= 10;
    }
}

int main() {
    int total = subtotal(3, 20);
    aplicarCupon(total);

    int pequeno = 20;
    aplicarCupon(pequeno);

    cout << "Total: " << total << "\n";
}
