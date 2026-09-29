// Const y headers en programación estructurada
//
// Vamos a repartir un programa en archivos. En Calificaciones.h escribimos qué funciones podemos
// usar; en Calificaciones.cpp escribimos sus pasos; desde main.cpp las llamamos. Podemos imaginar
// el .h como el menú y el .cpp como la cocina. Con const protegemos las notas para no cambiarlas
// por accidente. Pasamos también cuántas notas hay: al recibir un arreglo como parámetro, la
// función necesita esa cantidad para saber dónde detenerse. Con #ifndef, #define y #endif evitamos
// leer dos veces el mismo header dentro de un archivo que compilamos.
//

#include "Calificaciones.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const int notas[3]{8, 9, 10};
    double promedio = 0;
    // Recibimos true si las notas son válidas; el promedio se escribe mediante una referencia.
    if (!calcularPromedio(notas, 3, promedio)) {
        cerr << "Las notas deben estar entre 0 y 10.\n";
        return 1;
    }
    cout << "Promedio: " << promedio << "\n";
    if (estaAprobado(promedio)) {
        cout << "Aprobado\n";
    } else {
        cout << "Reprobado\n";
    }
}
