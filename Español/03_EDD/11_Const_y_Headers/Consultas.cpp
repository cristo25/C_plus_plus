#include "Consultas.h"
#include <algorithm>

using namespace std;

namespace curso {
    size_t contarMayores(const vector<int>& datos, int limite) {
        return count_if(datos.begin(), datos.end(), [limite](int dato) {
            return dato > limite;
        });
    }
} // namespace curso
