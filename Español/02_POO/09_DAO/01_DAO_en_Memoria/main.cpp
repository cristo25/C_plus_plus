// DAO en memoria y CRUD
//
// DAO significa Data Access Object: es un patrón de acceso a datos, no un paradigma. LibroDAO
// concentra crear, consultar, actualizar y eliminar (CRUD). La aplicación usa esas operaciones
// sin manipular el contenedor. Por ahora vector es una colección que crece; lo estudiaremos en
// EDD.
//
// Analogía: El bibliotecario (DAO) conoce dónde están los libros; tú le pides uno por su ficha
// sin revisar cada estante.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega dos libros y lista dao.todos(). Comprueba que actualizar un ID inexistente
// devuelve false.
// La creación y la carga respetan el mismo límite de 10 000 libros.

#include "../LibroDAO.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO dao;
    if (!(dao.crear({1, "C++ inicial"}))) {
        return 1;
    }
    if (dao.crear({1, "Duplicado"})) {
        return 1;
    }
    if (dao.crear({0, "Invalido"})) {
        return 1;
    }
    if (!(dao.actualizar(1, "C++ paso a paso"))) {
        return 1;
    }
    // La consulta devuelve un observador del catálogo. Modificar el vector puede invalidarlo.
    const Libro* libro = dao.buscar(1);

    cout << libro->titulo << "\n";
    if (!(dao.eliminar(1))) {
        return 1;
    }
    if (!(!dao.buscar(1) && !dao.eliminar(1))) {
        return 1;
    }
}
