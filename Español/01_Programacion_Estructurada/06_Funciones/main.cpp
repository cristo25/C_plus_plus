// Funciones
//
// Vamos a combinar funciones que calculan con funciones que modifican. Primero obtenemos un
// subtotal a partir del precio y la cantidad. Después pasamos el total por referencia para aplicar
// un cupón sobre esa misma variable. Podemos imaginar una caja registradora: una tarea calcula y
// otra actualiza el importe. Así podemos seguir cada paso sin mezclar todo dentro de main.
//

// Práctica: Vamos a realizar un programa integrador de una compra con cupón.
//
// - Calcular el subtotal en una función que devuelva un número.
// - Aplicar el descuento mediante una referencia al total.
// - Impedir que el descuento deje un total negativo.
// - Mostrar subtotal y total final.

#include <iostream>

using namespace std;

// Los parámetros por valor son copias; el resultado regresa con return.
int subtotal(int cantidad, int precio) {
    return cantidad * precio;
}
// int& es otra etiqueta del total original: el descuento sí cambia la variable de main.
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
