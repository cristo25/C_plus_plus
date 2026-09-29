#include "Producto.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const Producto cuaderno("Cuaderno", 1250);

    cout << cuaderno.consultarNombre() << ": " << cuaderno.consultarPrecio() << " centavos\n";
}
