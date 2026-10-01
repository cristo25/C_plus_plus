// Condicionales
//
// Vamos a combinar las dos formas de decidir. Primero elegimos un precio con switch; después usamos
// if para aplicar un descuento a estudiantes. En precio recibimos la opción y si hay descuento. Si
// la opción no existe, devolvemos -1 como señal acordada de error. La idea es separar dos
// preguntas: qué se compra y qué descuento corresponde.
//
// Práctica: Vamos a realizar un programa integrador para cobrar una entrada al cine.
//
// - Elegir entre tres tipos de entrada con switch.
// - Aplicar un descuento con if cuando corresponda.
// - Rechazar opciones que no existan.
// - Mostrar el precio inicial, descuento y total.

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
