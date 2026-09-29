#include "Consultas.h"

using namespace std;

namespace curso {
    size_t contarMayores(const vector<int>& datos, int limite) {
        size_t cantidad = 0;
        for (int dato : datos) {
            if (dato > limite) {
                ++cantidad;
            }
        }
        return cantidad;
    }
} // namespace curso
