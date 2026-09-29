// DAO: separar el acceso a datos
//
// Estudia CRUD en memoria y después persistencia. El integrador combina ambas operaciones usando
// un flujo en memoria para comprobar el formato sin crear archivos. Los headers de este bloque
// contienen definiciones dentro de la clase, implícitamente inline. El DAO permite consultas
// lineales y limita la carga a 10 000 registros; una base de datos será otro paso si hace falta.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include "LibroDAO.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO original;
    if (!(original.crear({1, "Estructuras"}))) {
        return 1;
    }
    if (!(original.crear({2, "Objetos"}))) {
        return 1;
    }
    if (!(original.actualizar(2, "Objetos y \"clases\""))) {
        return 1;
    }
    if (!(original.eliminar(1))) {
        return 1;
    }
    // Simulamos un archivo en memoria para guardar y recuperar sin crear datos en disco.
    stringstream archivo;
    if (!(original.guardar(archivo))) {
        return 1;
    }
    LibroDAO copia;
    if (!(copia.cargar(archivo))) {
        return 1;
    }
    // assert comprueba un resultado del integrador; no realiza operaciones del programa.
    assert(copia.todos().size() == 1);
    assert(copia.buscar(2)->titulo == "Objetos y \"clases\"");
    istringstream duplicados("2\n2 \"Uno\"\n2 \"Dos\"\n");
    if (copia.cargar(duplicados)) {
        return 1;
    }
    assert(copia.todos().size() == 1);
    cout << copia.buscar(2)->titulo << "\n";
}
