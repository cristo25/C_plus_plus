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
    const double* consulta = &resultado;

    string estado;
    if (*consulta >= 6) {
        estado = "Aprobado";
    } else {
        estado = "Reprobado";
    }
    const string reporte = "Ana: " + to_string(*consulta) + " - " + estado;
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
