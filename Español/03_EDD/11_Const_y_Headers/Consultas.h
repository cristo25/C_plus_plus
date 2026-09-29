#ifndef CURSO_CONSULTAS_H
#define CURSO_CONSULTAS_H
#include <cstddef>
#include <vector>

namespace curso {
    using namespace std;

    inline constexpr int LIMITE_DE_EJEMPLO = 7;
    size_t contarMayores(const vector<int>& datos, int limite);
} // namespace curso
#endif
