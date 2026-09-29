// Integrador: reporte de calificaciones
//
// Vamos a reunir lo aprendido en un reporte. Guardamos notas en un arreglo, calculamos el promedio
// con una función y usamos una condición para decidir si hay aprobación. Con consulta guardamos la
// dirección del resultado: *consulta permite leer ese mismo promedio. Después armamos una línea de
// texto y la agregamos a un archivo. Podemos seguir el camino completo del dato: notas, cálculo,
// decisión, mensaje y cuaderno guardado.
//

// Leemos y guardamos archivos con ifstream y ofstream.
#include <fstream>
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

bool promedio(const int notas[], int cantidad, double& salidaPromedio) {
    if (cantidad <= 0) {
        return false;
    }
    long long suma = 0;
    for (int indice = 0; indice < cantidad; ++indice) {
        const int nota = notas[indice];
        if (nota < 0 || nota > 10) {
            return false;
        }
        suma += nota;
    }
    salidaPromedio = static_cast<double>(suma) / cantidad;
    return true;
}

int main() {
    const int notas[3]{8, 9, 10};
    double resultado = 0;
    if (!promedio(notas, 3, resultado)) {
        cerr << "Las notas no son validas.\n";
        return 1;
    }
    // Este puntero permite consultar el promedio sin modificarlo ni hacerse dueño de su memoria.
    const double* consulta = &resultado;

    string estado;
    if (*consulta >= 6) {
        estado = "Aprobado";
    } else {
        estado = "Reprobado";
    }
    const string reporte = "Ana: " + to_string(*consulta) + " - " + estado;
    // El reporte reúne arreglo, función, decisión, cadena y archivo en un mismo recorrido.
    ofstream salida("reporte_demo.txt", ios::app);
    if (!salida) {
        cerr << "No se pudo abrir el reporte.\n";
        return 1;
    }
    salida << reporte << "\n";
    salida.close();
    if (!salida) {
        cerr << "No se pudo guardar.\n";
        return 1;
    }

    cout << reporte << "\n";
}
