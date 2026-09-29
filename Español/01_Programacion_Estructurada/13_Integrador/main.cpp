// Integrador: reporte de calificaciones
//
// Combina funciones, referencias, cadenas, arreglos, ciclos, condiciones, un puntero no
// propietario y un archivo. Lee el código en orden: calcular, clasificar, construir el reporte y
// guardarlo.
//
// Analogía: Un maestro revisa un cajón de notas, calcula un promedio y lo anota en su cuaderno.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega otro alumno y una función que devuelva la nota más alta. Mantén las notas
// dentro de 0 a 10.

#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double promedio(const array<int, 3>& notas) {
    int suma = 0;
    for (int nota : notas) {
        suma += nota;
    }
    return static_cast<double>(suma) / notas.size();
}

int main() {
    const array<int, 3> notas{8, 9, 10};
    const double resultado = promedio(notas);
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
