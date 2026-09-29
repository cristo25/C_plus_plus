// Con estas tres instrucciones evitamos leer dos veces este header al compilar un archivo.
#ifndef CURSO_CALIFICACIONES_H
#define CURSO_CALIFICACIONES_H

namespace curso {
    using namespace std;

    // Constantes compartidas: cada archivo usa las mismas reglas de notas.
    const int NOTA_MINIMA = 0;
    const int NOTA_MAXIMA = 10;
    const int NOTA_APROBATORIA = 6;

    // Aquí se declara el servicio; Calificaciones.cpp contiene su definición.
    bool calcularPromedio(const int notas[], int cantidad, double& resultado);
    bool estaAprobado(double promedio);
} // namespace curso
#endif
