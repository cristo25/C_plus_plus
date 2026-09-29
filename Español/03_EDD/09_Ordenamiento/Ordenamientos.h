#ifndef CURSO_ORDENAMIENTOS_H
#define CURSO_ORDENAMIENTOS_H
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

namespace curso {
    using namespace std;

    // Burbuja: mueve el mayor restante hacia el final en cada pasada.
    inline void burbuja(vector<int>& datos) {
        for (size_t limite = datos.size(); limite > 1; --limite) {
            bool cambio = false;
            for (size_t i = 1; i < limite; ++i) {
                if (datos[i - 1] > datos[i]) {
                    swap(datos[i - 1], datos[i]);
                    cambio = true;
                }
            }
            // Una pasada sin intercambios confirma que ya está ordenado: terminamos antes.
            if (!cambio) {
                break;
            }
        }
    }
    // Seleccion: coloca el menor restante en la siguiente posicion.
    inline void seleccion(vector<int>& datos) {
        for (size_t i = 0; i < datos.size(); ++i) {
            size_t menor = i;
            for (size_t j = i + 1; j < datos.size(); ++j) {
                if (datos[j] < datos[menor]) {
                    menor = j;
                }
            }
            swap(datos[i], datos[menor]);
        }
    }
    // Insercion: desplaza mayores para abrir sitio a la carta actual.
    inline void insercion(vector<int>& datos) {
        for (size_t i = 1; i < datos.size(); ++i) {
            int actual = datos[i];
            size_t j = i;
            while (j > 0 && datos[j - 1] > actual) {
                datos[j] = datos[j - 1];
                --j;
            }
            // Tras desplazar los mayores, la carta actual entra en el hueco correcto.
            datos[j] = actual;
        }
    }

    // Merge sort: todos los rangos son [inicio, fin), con fin excluido.
    inline void mezclarRango(vector<int>& datos, vector<int>& auxiliar, size_t inicio, size_t fin) {
        if (fin - inicio < 2) {
            return;
        }
        size_t mitad = inicio + (fin - inicio) / 2;
        mezclarRango(datos, auxiliar, inicio, mitad);
        mezclarRango(datos, auxiliar, mitad, fin);
        size_t izquierda = inicio, derecha = mitad, destino = inicio;
        while (izquierda < mitad && derecha < fin) {
            // Ante empates tomamos la izquierda primero: merge sort mantiene el orden original.
            if (datos[izquierda] <= datos[derecha]) {
                auxiliar[destino++] = datos[izquierda++];
            } else {
                auxiliar[destino++] = datos[derecha++];
            }
        }
        while (izquierda < mitad) {
            auxiliar[destino++] = datos[izquierda++];
        }
        while (derecha < fin) {
            auxiliar[destino++] = datos[derecha++];
        }
        for (size_t i = inicio; i < fin; ++i) {
            datos[i] = auxiliar[i];
        }
    }
    inline void mergeSort(vector<int>& datos) {
        vector<int> auxiliar(datos.size());
        mezclarRango(datos, auxiliar, 0, datos.size());
    }

    // Quick sort: separa menores que el pivote del resto.
    inline void partirRango(vector<int>& datos, size_t inicio, size_t fin) {
        if (fin - inicio < 2) {
            return;
        }
        int pivote = datos[fin - 1];
        size_t corte = inicio;
        for (size_t i = inicio; i < fin - 1; ++i) {
            if (datos[i] < pivote) {
                swap(datos[i], datos[corte]);
                ++corte;
            }
        }
        // El pivote llega a su sitio definitivo; las llamadas recursivas lo excluyen.
        swap(datos[corte], datos[fin - 1]);
        partirRango(datos, inicio, corte);
        partirRango(datos, corte + 1, fin);
    }
    inline void quickSort(vector<int>& datos) {
        // ponytail: ultimo elemento como pivote, peor caso O(n^2); sort para uso real.
        partirRango(datos, 0, datos.size());
    }
} // namespace curso

#endif
