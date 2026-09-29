#include "Producto.h"
#include <stdexcept>

using namespace std;
using namespace curso;

Producto::Producto(const string& nombreInicial, int precioInicial)
    : nombre(nombreInicial), precioCentavos(precioInicial) {
    // El constructor valida el estado inicial para evitar crear productos inválidos.
    if (nombre.empty() || precioCentavos < 0) {
        throw invalid_argument("Producto invalido");
    }
}

const string& Producto::consultarNombre() const {
    return nombre;
}
int Producto::consultarPrecio() const {
    return precioCentavos;
}
