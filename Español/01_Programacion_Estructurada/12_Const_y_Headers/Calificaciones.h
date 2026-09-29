// Estas guardas evitan declarar dos veces el header en una misma unidad de compilación.
#ifndef CURSO_CALIFICACIONES_H
#define CURSO_CALIFICACIONES_H
#include <array>

namespace curso {
    using namespace std;

    // Constantes compartidas: cada archivo usa las mismas reglas de notas.
    inline constexpr int NOTA_MINIMA = 0;
    inline constexpr int NOTA_MAXIMA = 10;
    inline constexpr int NOTA_APROBATORIA = 6;

    // Aquí se declara el servicio; Calificaciones.cpp contiene su definición.
    double calcularPromedio(const array<int, 3>& notas);
    bool estaAprobado(double promedio);
} // namespace curso
#endif
