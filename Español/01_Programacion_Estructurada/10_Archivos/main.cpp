#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";
    {
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo.\n";
            return 1;
        }
        salida << "Estudiar C++\n";
        salida.close();
        if (!salida) {
            cerr << "Error al guardar.\n";
            return 1;
        }
    }
    ifstream entrada(ruta);
    if (!entrada) {
        cerr << "No se pudo leer.\n";
        return 1;
    }
    string linea;
    while (getline(entrada, linea)) {
        cout << linea << "\n";
    }
    if (!entrada.eof()) {
        cerr << "Error de lectura.\n";
        return 1;
    }
}
