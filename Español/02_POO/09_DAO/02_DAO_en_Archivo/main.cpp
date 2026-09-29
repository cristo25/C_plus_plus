#include "../LibroDAO.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO dao;
    if (!(dao.crear({1, "C++ con ejemplos"}))) {
        return 1;
    }
    // ponytail: diario por anexado; compactar si el archivo crece demasiado.
    ofstream salida("libros_demo.txt", ios::app);
    if (!salida || !dao.guardar(salida)) {
        cerr << "No se pudo guardar el catalogo.\n";
        return 1;
    }
    salida.close();
    if (!salida) {
        cerr << "Fallo al cerrar el archivo.\n";
        return 1;
    }

    ifstream entrada("libros_demo.txt");
    if (!entrada) {
        cerr << "No se pudo abrir el catalogo.\n";
        return 1;
    }
    LibroDAO recuperado;
    while (entrada >> ws && entrada.peek() != char_traits<char>::eof()) {
        if (!recuperado.cargar(entrada)) {
            cerr << "Instantanea incompleta o invalida.\n";
            return 1;
        }
    }
    if (entrada.bad()) {
        cerr << "Error de lectura.\n";
        return 1;
    }

    istringstream corrupto("1\n1 sin_comillas\n");
    if (recuperado.cargar(corrupto)) {
        return 1;
    }
    cout << recuperado.buscar(1)->titulo << "\n";
}
