// Persistir un DAO en un archivo
//
// Vamos a guardar el catálogo en un archivo para recuperarlo después. Primero pedimos al DAO que
// escriba sus libros y luego que los lea en otro catálogo. En cada ejecución volvemos a escribir
// el archivo con el catálogo actual. Si encontramos datos incorrectos, avisamos sin sustituir el
// catálogo por una lectura incompleta. Para probar ese caso
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
    if (!dao.crear({1, "C++ con ejemplos"})) {
        return 1;
    }
    ofstream salida("libros_demo.txt");
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
    if (!recuperado.cargar(entrada)) {
        cerr << "Catalogo incompleto o invalido.\n";
        return 1;
    }

    // Una carga rechazada conserva el catálogo recuperado en lugar de dejarlo a medias.
    istringstream corrupto("1\n1 sin_comillas\n");
    if (recuperado.cargar(corrupto)) {
        return 1;
    }
    const Libro* libro = recuperado.buscar(1);
    if (libro == nullptr) {
        cerr << "No se encontro el libro.\n";
        return 1;
    }
    cout << libro->titulo << "\n";
}

// Práctica: vamos a guardar dos libros en un archivo y recuperarlos.
// - Creamos los libros antes de llamar guardar.
// - Abrimos el archivo para cargarlos en un segundo catálogo.
// - Comprobamos ambos títulos antes de mostrarlos.
