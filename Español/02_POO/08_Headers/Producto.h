#ifndef CURSO_PRODUCTO_H
#define CURSO_PRODUCTO_H

#include <string>

namespace curso {
    using namespace std;

    class Producto {
        string nombre;
        int precioCentavos;

    public:
        Producto(const string& nombreInicial, int precioInicial);
        const string& consultarNombre() const;
        int consultarPrecio() const;
    };

} // namespace curso

#endif
