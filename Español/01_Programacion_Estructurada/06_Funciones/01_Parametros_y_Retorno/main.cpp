// Funciones: parámetros y retorno
//
// Vamos a separar un cálculo en una función. Podemos imaginar una máquina pequeña: recibe
// ingredientes, trabaja y devuelve un resultado. A los datos de entrada los llamamos parámetros;
// con return entregamos el resultado. Cuando recibimos un int por valor, trabajamos con una copia:
// cambiarla dentro de la función no cambia la variable que enviamos.
//

// Práctica: Vamos a realizar un programa que convierta minutos a segundos.
//
// - Crear una función que reciba los minutos.
// - Devolver el resultado con return.
// - Llamar a la función con tres valores diferentes.
// - Mostrar los resultados desde main.

#include <iostream>

using namespace std;

// La función recibe una copia del número y devuelve su cuadrado.
int cuadrado(int numero) {
    return numero * numero;
}

int main() {

    cout << cuadrado(4) << "\n";
}
