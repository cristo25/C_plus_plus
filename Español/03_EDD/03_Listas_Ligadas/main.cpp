// Listas ligadas
//
// Vamos a comparar las tres listas usando los mismos números. En la simple seguimos una flecha, en
// la doble podemos regresar y en la circular volvemos al inicio. Insertamos 10, 20 y 30, quitamos
// 20 y revisamos qué queda. La diferencia principal está en cómo unimos los nodos y cuándo
// detenemos el recorrido. Podemos dibujar las mismas tres cajas y cambiar solo sus flechas para
// entenderlo.
//
// Práctica: Vamos a comparar tres cadenas de nodos.
// - Agreguemos los mismos valores en una lista simple, doble y circular.
// - Quitemos un valor y mostremos cómo se recorre cada lista.

#include "01_Simplemente_Ligada/ListaSimple.h"
#include "02_Doblemente_Ligada/ListaDoble.h"
#include "03_Circular/ListaCircular.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple simple;
    ListaDoble doble;
    ListaCircular circular;
    // Usamos los mismos datos para comparar los enlaces de las tres listas.
    for (int dato : {10, 20, 30}) {
        simple.agregar(dato);
        doble.agregar(dato);
        circular.agregar(dato);
    }
    if (!(simple.eliminar(20) && doble.eliminar(20) && circular.eliminar(20))) {
        return 1;
    }
    const vector<int> esperado{10, 30};
    if (!(simple.valores() == esperado && doble.valores() == esperado)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(circular.valores() == esperado)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!((doble.inversos() == vector<int>{30, 10}))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << "Simple: ";
    for (int dato : simple.valores()) {
        cout << dato << ' ';
    }
    cout << "\nDoble inversa: ";
    for (int dato : doble.inversos()) {
        cout << dato << ' ';
    }
    cout << "\nCircular (una vuelta): ";
    for (int dato : circular.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
}
