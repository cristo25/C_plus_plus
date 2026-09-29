#ifndef CURSO_BUSQUEDAS_H
#define CURSO_BUSQUEDAS_H
#include <cstddef>
#include <optional>
#include <vector>

namespace curso {
    using namespace std;

    inline optional<size_t> lineal(const vector<int>& datos, int buscado) {
        for (size_t i = 0; i < datos.size(); ++i) {
            if (datos[i] == buscado) {
                return i;
            }
        }
        return nullopt;
    }

    // Precondicion: datos ordenados de menor a mayor; devuelve la primera coincidencia.
    inline optional<size_t> binaria(const vector<int>& datos, int buscado) {
        size_t inicio = 0, fin = datos.size(); // Rango [inicio, fin).
        while (inicio < fin) {
            size_t mitad = inicio + (fin - inicio) / 2;
            if (datos[mitad] < buscado) {
                inicio = mitad + 1;
            } else {
                fin = mitad;
            }
        }
        if (inicio < datos.size() && datos[inicio] == buscado) {
            return inicio;
        }
        return nullopt;
    }
} // namespace curso

#endif
