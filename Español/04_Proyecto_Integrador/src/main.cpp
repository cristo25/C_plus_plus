// Punto de entrada: configura el almacén y conecta servicio e interfaz.
// Compila desde la raíz del proyecto con el comando de README.md. --self-test ejecuta la comprobación.
#include "interfaz/Consola.h"
#include "pruebas/Autocomprobacion.h"
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <shellapi.h>
#endif

using namespace std;
using namespace proyecto;

namespace {
    vector<filesystem::path> leerArgumentos(int argc, char* argv[]) {
        vector<filesystem::path> resultado;
#ifdef _WIN32
        // Los argumentos nativos amplios conservan rutas Unicode que argv puede perder.
        (void)argc;
        (void)argv;
        int cantidad = 0;
        unique_ptr<wchar_t*, decltype(&LocalFree)> argumentos(
            CommandLineToArgvW(GetCommandLineW(), &cantidad), &LocalFree);
        if (!argumentos) {
            throw runtime_error("No se pudieron leer los argumentos de consola");
        }
        for (int indice = 0; indice < cantidad; ++indice) {
            resultado.emplace_back(argumentos.get()[indice]);
        }
#else
        for (int indice = 0; indice < argc; ++indice) {
            resultado.emplace_back(argv[indice]);
        }
#endif
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

        // El puntero base posee una de dos implementaciones; virtual selecciona cargar/guardar en ejecución.
        unique_ptr<AlmacenCatalogo> almacen;
        if (demostracion) {
            LibroDAO inicial;
            if (!inicial.crear({10, "Fundamentos de C++"}) || !inicial.crear({30, "Estructuras de datos"}) ||
                !inicial.crear({20, "Programacion orientada a objetos"})) {
                throw logic_error("No se pudo preparar el catalogo de demostracion");
            }
            almacen = make_unique<AlmacenMemoria>(move(inicial));
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
