// DAO en memoria y CRUD
//
// Vamos a reunir en LibroDAO las tareas de guardar, buscar, cambiar y eliminar libros. Podemos
// imaginar un encargado del catálogo: le pedimos un libro por su id, que es un número que lo
// identifica. DAO es el nombre habitual de una clase dedicada al acceso a datos. Aquí guardamos los
// libros en un vector, por lo que desaparecen al terminar el programa. buscar presta un puntero al
// libro, o devuelve nullptr si no existe. Antes de leerlo comprobamos el resultado; después de
// cambiar el catálogo volvemos a buscarlo, porque el vector puede mover sus libros.
//

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
    // Recibimos una dirección prestada del catálogo. Después de cambiar sus libros volvemos a
    // buscar antes de usar una dirección.
    const Libro* libro = dao.buscar(1);

    cout << libro->titulo << "\n";
    if (!(dao.eliminar(1))) {
        return 1;
    }
    if (!(!dao.buscar(1) && !dao.eliminar(1))) {
        return 1;
    }
}
