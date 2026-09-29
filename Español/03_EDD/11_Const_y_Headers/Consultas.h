// Con inline permitimos compartir estas definiciones desde el header entre varios archivos.

#ifndef CURSO_CONSULTAS_H
#define CURSO_CONSULTAS_H
// Usamos size_t para contar elementos y representar posiciones no negativas.
#include <cstddef>
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    inline constexpr int LIMITE_DE_EJEMPLO = 7;
    // Una consulta lee const vector<int>&; un ordenamiento necesita vector<int>& para
    // modificarlo.
    size_t contarMayores(const vector<int>& datos, int limite);
} // namespace curso
#endif
