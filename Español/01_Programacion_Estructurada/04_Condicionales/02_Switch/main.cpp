// Elegir con switch
//
// Vamos a elegir una bebida mediante un número. Con switch comparamos ese número con cada case,
// como al escoger una opción de un menú. Con break salimos del switch después de atender la opción;
// con default respondemos cuando el número no coincide con ninguna. Nos sirve cuando tenemos
// opciones concretas, por ejemplo 1, 2 y 3. En este ejemplo devolvemos directamente la bebida con
// return: salimos de la función y no necesitamos break en esos casos.
//
// Práctica: Vamos a realizar un programa con un menú de tres bebidas.
//
// - Asignar un número a cada bebida.
// - Mostrar el nombre y precio de la opción elegida.
// - Informar cuando la opción no exista.
// - Usar break para terminar cada caso.

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
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
