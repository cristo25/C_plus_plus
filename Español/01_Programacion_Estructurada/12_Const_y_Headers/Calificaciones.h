#ifndef CURSO_CALIFICACIONES_H
#define CURSO_CALIFICACIONES_H
#include <array>

namespace curso {
    using namespace std;

    inline constexpr int NOTA_MINIMA = 0;
    inline constexpr int NOTA_MAXIMA = 10;
    inline constexpr int NOTA_APROBATORIA = 6;

    double calcularPromedio(const array<int, 3>& notas);
    bool estaAprobado(double promedio);
} // namespace curso
#endif
