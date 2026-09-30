// Punto de entrada: configura el almacén y conecta servicio e interfaz.
//
// Vamos a construir una aplicación de biblioteca y rutas del campus. Desde un menú agregamos
// libros, buscamos por id, organizamos entregas y consultamos caminos. Dividimos el trabajo: la
// consola conversa con la persona, Biblioteca aplica las reglas, el DAO guarda los libros y
// MapaCampus calcula rutas. Reutilizamos los headers del curso para conectar clases, listas, pilas,
// colas, búsquedas y grafos. Podemos seguir un pedido desde que entra hasta que queda registrado;
// cada archivo se ocupa de una parte de ese recorrido. La guía del proyecto explica las piezas con
// fragmentos de código.
//

#include "interfaz/Consola.h"
#include "pruebas/Autocomprobacion.h"
// Recogemos errores mediante exception y leemos su mensaje con what().
#include <exception>
// Manejamos rutas, carpetas y cambios de nombre de archivos.
#include <filesystem>
#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace proyecto;

namespace {
    vector<filesystem::path> leerArgumentos(int argc, char* argv[]) {
        vector<filesystem::path> resultado;
        for (int indice = 0; indice < argc; ++indice) {
            resultado.emplace_back(filesystem::u8path(argv[indice]));
        }
        return resultado;
    }
}

int main(int argc, char* argv[]) {
    try {
        const auto argumentos = leerArgumentos(argc, argv);
        bool demostracion = false;
        bool comprobando = false;
        filesystem::path archivoDatos = "datos/catalogo.txt";
        bool rutaPersonalizada = false;
        for (size_t indice = 1; indice < argumentos.size(); ++indice) {
            const string opcion = argumentos.at(indice).u8string();
            if (opcion == "--self-test") {
                comprobando = true;
            } else if (opcion == "--demo") {
                demostracion = true;
            } else if (opcion == "--data" && indice + 1 < argumentos.size()) {
                ++indice;
                archivoDatos = argumentos.at(indice);
                rutaPersonalizada = true;
            } else if (opcion == "--help") {
                cout << "Uso: biblioteca.exe [--demo | --data RUTA | --self-test]\n";
                return 0;
            } else {
                throw invalid_argument("Opcion desconocida o falta la ruta despues de --data");
            }
        }
        if ((demostracion && rutaPersonalizada) || (comprobando && (demostracion || rutaPersonalizada))) {
            throw invalid_argument("Usa solo un modo: normal, --demo, --data o --self-test");
        }
        if (comprobando) {
            return autocomprobar(cout);
        }

        // Elegimos un almacén de memoria o de archivo. Mediante virtual llamamos a cargar y guardar
        // de la variante elegida.
        unique_ptr<AlmacenCatalogo> almacen;
        if (demostracion) {
            LibroDAO inicial;
            if (!inicial.crear({10, "Fundamentos de C++"}) || !inicial.crear({30, "Estructuras de datos"}) ||
                !inicial.crear({20, "Programacion orientada a objetos"})) {
                throw logic_error("No se pudo preparar el catalogo de demostracion");
            }
            almacen = make_unique<AlmacenMemoria>(inicial);
            cout << "Modo demostracion: el catalogo vive en memoria.\n";
        } else {
            almacen = make_unique<AlmacenArchivo>(archivoDatos);
            cout << "Archivo del catalogo: " << archivoDatos.u8string() << "\n";
        }
        // El almacén se declara primero y se destruye al final; las referencias prestadas siguen vivas.
        Biblioteca biblioteca(*almacen);
        Consola consola(biblioteca, cin, cout);
        consola.ejecutar();
        return 0;
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << "\n";
        return 1;
    }
}
