// El header es el menú: declara lo que se puede pedir; el .cpp implementa los servicios.
#ifndef CURSO_PRODUCTO_H
#define CURSO_PRODUCTO_H

// Guardamos y trabajamos con texto mediante string.
#include <string>

namespace curso {
    using namespace std;

    class Producto {
        string nombre;
        int precioCentavos;

    public:
        // La referencia const evita una copia; el const final permite consultar objetos
        // constantes.
        Producto(const string& nombreInicial, int precioInicial);
        const string& consultarNombre() const;
        int consultarPrecio() const;
    };

} // namespace curso

#endif
