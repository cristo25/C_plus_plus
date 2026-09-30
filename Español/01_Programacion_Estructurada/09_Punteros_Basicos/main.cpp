// Punteros: una caja, una tarjeta y una tarjeta de otra tarjeta
//
// Primero vamos a distinguir el dato de su dirección. Una variable como int es una caja que guarda
// un entero; un puntero también es una variable, pero guarda la dirección de otra caja. Podemos
// imaginar un dedo que señala dónde está el dato. Con & obtenemos esa dirección; con * seguimos la
// dirección para leer o cambiar el dato. Copiar el puntero copia la dirección, no la caja. Con
// int** guardamos la dirección de un puntero: seguimos dos señales para llegar al entero.
//
// Una referencia es otra etiqueta de la misma caja; un puntero puede cambiar de destino o guardar
// nullptr, que significa que no señala nada. Nos sirve, por ejemplo, para elegir un producto o unir
// nodos de listas, árboles y grafos. No necesitamos crear memoria nueva para señalar una variable
// existente. Antes de seguir un puntero comprobamos que tiene un destino y que ese dato aún existe:
// una dirección no mantiene viva la caja ni se vuelve nullptr automáticamente cuando desaparece.
//

// Práctica: Vamos a realizar un programa que permita seleccionar entre dos enteros mediante un puntero.
//
// - Crear dos variables y un puntero que señale una de ellas.
// - Cambiar el dato mediante * y mostrar la variable original.
// - Cambiar el destino del puntero y mostrar ambos enteros.
// - Asignar nullptr al terminar y comprobarlo antes de intentar leer.
// - Dibujar las cajas y las flechas después de cada cambio.

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
    // int*& es otra etiqueta de la tarjeta del llamador: podemos cambiar su destino.
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
