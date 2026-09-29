#include "ListaDoble.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaDoble lista;
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
