#include "Consultas.h"
#include <algorithm>

using namespace std;

namespace curso {
    size_t contarMayores(const vector<int>& datos, int limite) {
        // La lambda captura el límite por valor y devuelve true por cada dato que se debe
        // contar.
        return count_if(datos.begin(), datos.end(), [limite](int dato) {
            return dato > limite;
        });
    }
} // namespace curso
