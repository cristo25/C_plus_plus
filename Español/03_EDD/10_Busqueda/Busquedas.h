// Con inline permitimos compartir estas definiciones desde el header entre varios archivos.

#ifndef CURSO_BUSQUEDAS_H
#define CURSO_BUSQUEDAS_H
// Usamos size_t para contar elementos y representar posiciones no negativas.
#include <cstddef>
// Guardamos un resultado que puede faltar: optional tiene un valor o está vacío.
#include <optional>
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    inline optional<size_t> lineal(const vector<int>& datos, int buscado) {
        for (size_t i = 0; i < datos.size(); ++i) {
            if (datos[i] == buscado) {
                return i;
            }
        }
        // No encontrado no es índice cero: optional representa la ausencia explícitamente.
        return nullopt;
    }

    // Antes de buscar necesitamos los datos ordenados de menor a mayor. Devolvemos la primera
    // coincidencia.
    inline optional<size_t> binaria(const vector<int>& datos, int buscado) {
        size_t inicio = 0, fin = datos.size(); // Revisamos desde inicio hasta antes de fin.
        while (inicio < fin) {
            size_t mitad = inicio + (fin - inicio) / 2;
            // Si la mitad es menor, descartamos su lado izquierdo; de lo contrario conservamos
            // el candidato.
            if (datos[mitad] < buscado) {
                inicio = mitad + 1;
            } else {
                fin = mitad;
            }
        }
        // Al terminar, verificamos la coincidencia: el límite también puede caer al final del
        // vector.
        if (inicio < datos.size() && datos[inicio] == buscado) {
            return inicio;
        }
        return nullopt;
    }
} // namespace curso

#endif
