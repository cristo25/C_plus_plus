// Punteros: una caja, una tarjeta y una tarjeta de otra tarjeta
//
// La variable es una caja; un puntero es una tarjeta que guarda su dirección.
// & obtiene una dirección y * sigue la dirección una vez. int** permite localizar
// una tarjeta, leerla y después llegar a la caja. Copiar una tarjeta no copia la caja.
// Un puntero no mantiene vivo su destino: aquí los enteros locales son propietarios.
// nullptr significa sin destino; nunca lo desreferencies. Un puntero no nulo también
// puede estar colgando si su objeto ya murió. No retornes direcciones de variables locales.
// No hace falta new para observar objetos que ya existen.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Añade const int* const y explica qué dos cosas ya no puedes cambiar.

#include <iostream>

using namespace std;

// Se copia la tarjeta con la dirección; el entero al que apunta sigue siendo el original.
void sumarDesdeDireccion(int* direccion) {
    if (direccion != nullptr) {
        ++*direccion;
    }
}

void redirigirCopia(int* direccion, int& otro) {
    // Solo redirigimos la copia local de la tarjeta. El puntero del llamador no cambia.
    direccion = &otro;
    cout << "Destino de la copia local: " << *direccion << "\n";
}

void redirigirReferencia(int*& direccion, int& otro) {
    // int*& es un alias de la tarjeta del llamador: podemos cambiar su destino.
    direccion = &otro;
}

void redirigirDoble(int** direccion, int& otro) {
    // int** guarda la dirección de una tarjeta. *direccion es esa tarjeta, no el entero.
    if (direccion != nullptr) {
        *direccion = &otro;
    }
}

int main() {
    cout << boolalpha;
    int caja = 10;
    int otraCaja = 20;

    // &caja obtiene su dirección; int* declara una tarjeta para un entero.
    int* direccion = &caja;
    int* alias = direccion;
    *direccion = 25;
    cout << "Dos tarjetas, una caja: " << *alias << "\n";

    sumarDesdeDireccion(direccion);
    sumarDesdeDireccion(nullptr);
    cout << "Caja tras int*: " << caja << "\n";

    redirigirCopia(direccion, otraCaja);
    cout << "La tarjeta original sigue en caja: " << (direccion == &caja) << "\n";

    redirigirReferencia(direccion, otraCaja);
    cout << "Referencia redirigió la tarjeta: " << (direccion == &otraCaja) << "\n";

    // &direccion señala la variable puntero. ** de esa dirección alcanzaría el entero.
    redirigirDoble(&direccion, caja);
    cout << "Doble puntero la devolvió a caja: " << (direccion == &caja) << "\n";

    const int* soloLectura = &caja;
    // El dato no se puede cambiar por soloLectura; la tarjeta sí puede cambiar de destino.
    soloLectura = &otraCaja;
    cout << "Lectura por const int*: " << *soloLectura << "\n";

    int* const direccionFija = &caja;
    // La tarjeta no puede redirigirse; el contenido de su destino sí puede modificarse.
    *direccionFija = 30;
    cout << "Escritura por int* const: " << caja << "\n";

    // nullptr no libera caja ni anula otras tarjetas. Cada observador es independiente.
    direccion = nullptr;
    alias = nullptr;
}
