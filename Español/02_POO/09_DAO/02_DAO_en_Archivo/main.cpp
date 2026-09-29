// Persistir un DAO en un archivo
//
// Vamos a guardar el catálogo en un archivo para recuperarlo después. Primero pedimos al DAO que
// escriba sus libros y luego que los lea en otro catálogo. Agregamos una copia completa al final
// del archivo en cada ejecución; al leer conservamos la última copia completa. Si encontramos datos
// incorrectos, avisamos sin sustituir el catálogo por una lectura incompleta. Para probar ese caso
// usamos istringstream: una herramienta de <sstream> que permite leer un texto ya guardado en
// memoria como si llegara de un archivo. Así podemos ensayar una entrada dañada sin dañar el
// archivo real.
//

#include "../LibroDAO.h"
// Leemos y guardamos archivos con ifstream y ofstream.
#include <fstream>
#include <iostream>
// Leemos o escribimos texto en memoria como si fuera un archivo.
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO dao;
    if (!(dao.crear({1, "C++ con ejemplos"}))) {
        return 1;
    }
    // ponytail: agregamos copias al final; si el archivo crece demasiado, guardamos solo la última
    // copia completa. Guardamos una copia completa por anexado; al leer, recuperamos las copias
    // completas completas en orden.
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

    // Una carga rechazada conserva el catálogo recuperado en lugar de dejarlo a medias.
    istringstream corrupto("1\n1 sin_comillas\n");
    if (recuperado.cargar(corrupto)) {
        return 1;
    }
    cout << recuperado.buscar(1)->titulo << "\n";
}
