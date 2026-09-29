// Persistir un DAO en un archivo
//
// guardar serializa una instantánea y cargar la valida antes de reemplazar los datos en memoria.
// quoted conserva espacios y comillas. Cada instantánea comienza con su cantidad de libros. Este
// ejemplo agrega instantáneas al archivo y recupera la última completa.
//
// Analogía: El bibliotecario toma una fotografía del catálogo al cerrar. Al abrir consulta la
// fotografía más reciente para recuperar el estado.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Guarda un título con comillas. Modifica una copia del archivo para duplicar un ID y
// comprueba el rechazo.
// La creación y la carga respetan el mismo límite de 10 000 libros.

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
    // Guardamos una instantánea por anexado; al leer, recuperamos las instantáneas completas en
    // orden.
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
