// DAO: separar el acceso a datos
//
// Vamos a recorrer todo el trabajo del catálogo: crear libros, cambiar un título, eliminar un libro
// y recuperar lo guardado. Aquí usamos stringstream, de <sstream>, como un cuaderno temporal en
// memoria: podemos escribir en él y volver a leer sin crear un archivo en disco. Después probamos
// una lectura con ids repetidos. La regla es sencilla: si no podemos recuperar todos los datos
// correctamente, conservamos el catálogo que ya teníamos.
//

#include "LibroDAO.h"
#include <iostream>
// Leemos o escribimos texto en memoria como si fuera un archivo.
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
    if (!(copia.todos().size() == 1)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(copia.buscar(2)->titulo == "Objetos y \"clases\"")) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    istringstream duplicados("2\n2 \"Uno\"\n2 \"Dos\"\n");
    if (copia.cargar(duplicados)) {
        return 1;
    }
    if (!(copia.todos().size() == 1)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << copia.buscar(2)->titulo << "\n";
}
