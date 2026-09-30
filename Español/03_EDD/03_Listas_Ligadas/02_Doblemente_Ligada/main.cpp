// Lista doblemente ligada
//
// Vamos a añadir una segunda flecha a cada nodo: una hacia el siguiente y otra hacia el anterior.
// Así podemos recorrer la cadena en ambos sentidos. Conservamos también el principio y el final
// para agregar al final ajustando unas pocas flechas, sin recorrer toda la lista. Al borrar
// cuidamos ambas conexiones, como al retirar un vagón de un tren unido por delante y por detrás.
// Podemos seguir el ajuste de los punteros en ListaDoble.h.
//
// Práctica: Vamos a crear una lista que se recorra en ambos sentidos.
// - Agreguemos tres valores y mostremos el orden normal e inverso.
// - Quitemos el primero o el último sin romper los enlaces restantes.

#include "ListaDoble.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaDoble lista;
    // El enlace al anterior permite recorrer desde el final: 30, 20, 10.
    if (!(lista.inversos().empty() && !lista.eliminar(5))) {
        return 1;
    }
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);

    for (int dato : lista.inversos()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(20))) {
        return 1;
    }

    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }

    lista.agregar(40);
}
