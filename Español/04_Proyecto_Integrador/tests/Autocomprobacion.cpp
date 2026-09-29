#include "pruebas/Autocomprobacion.h"
#include "interfaz/Consola.h"
#include <algorithm>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace proyecto {
    using namespace std;

    namespace {
        // Doble de prueba para provocar un fallo de guardado sin escribir archivos.
        class AlmacenConFallo : public AlmacenCatalogo {
            AlmacenMemoria guardado;
        public:
            bool rechazar = false;
            LibroDAO cargar() const override {
                return guardado.cargar();
            }
            void guardar(const LibroDAO& dao) override {
                if (rechazar) {
                    throw runtime_error("Fallo de guardado simulado");
                }
                guardado.guardar(dao);
            }
        };

        void exigir(bool valor, const string& mensaje) {
            if (!valor) {
                throw logic_error(mensaje);
            }
        }
    }

    int autocomprobar(ostream& salida) {
        try {
            AlmacenConFallo almacen;
            Biblioteca biblioteca(almacen);
            exigir(biblioteca.buscar(10) == nullptr, "Busqueda vacia");
            biblioteca.agregarLibro({30, "C++"});
            biblioteca.agregarLibro({10, "Libro con \"comillas\""});
            biblioteca.agregarLibro({20, "POO"});
            {
                const auto vista = biblioteca.catalogoOrdenado();
                exigir(vista.at(0)->id == 10 && vista.at(2)->id == 30, "Vista ordenada");
            }
            exigir(biblioteca.buscar(20)->titulo == "POO" && biblioteca.buscar(21) == nullptr, "Busqueda binaria");
            // La ruta mínima mejora un camino directo; también comprobamos destino aislado y origen igual a destino.
            const auto ruta = biblioteca.mapa().rutaMinima(0, 4);
            exigir(ruta && ruta->minutos == 7 && ruta->paradas == vector<size_t>({0, 2, 1, 3, 4}), "Dijkstra");
            exigir(!biblioteca.mapa().rutaMinima(0, 5), "Destino aislado");
            const auto misma = biblioteca.mapa().rutaMinima(2, 2);
            exigir(misma && misma->minutos == 0 && misma->paradas.size() == 1, "Mismo edificio");
            exigir(biblioteca.mapa().alcanzables(0).size() == 5, "BFS");

            biblioteca.solicitarEntrega(10, 0, 4);
            biblioteca.solicitarEntrega(20, 2, 1);
            biblioteca.renombrarLibro(10, "Titulo nuevo");
            exigir(biblioteca.entregasPendientes().at(0).libro.titulo == "Libro con \"comillas\"", "Solicitud independiente del catalogo");
            const auto primera = biblioteca.procesarEntrega();
            const auto segunda = biblioteca.procesarEntrega();
            exigir(primera && segunda && primera->entrega.libro.id == 10 && segunda->entrega.libro.id == 20, "FIFO");
            exigir(!biblioteca.procesarEntrega(), "Cola vacia");

            biblioteca.eliminarLibro(20);
            exigir(biblioteca.buscar(20) == nullptr && biblioteca.deshacer() && biblioteca.buscar(20) != nullptr, "LIFO");
            auto anterior = biblioteca.historial();
            reverse(anterior.begin(), anterior.end());
            exigir(anterior == biblioteca.historial(true), "Lista doble en ambos sentidos");

            // El fallo no debe agregar el libro ni consumir la instantánea anterior de deshacer.
            const auto antes = biblioteca.catalogoOrdenado().size();
            almacen.rechazar = true;
            bool rechazado = false;
            try {
                biblioteca.agregarLibro({40, "Error"});
            } catch (const runtime_error&) {
                rechazado = true;
            }
            exigir(rechazado && biblioteca.buscar(40) == nullptr && biblioteca.catalogoOrdenado().size() == antes, "Catalogo intacto tras fallo");
            almacen.rechazar = false;
            exigir(biblioteca.deshacer() && biblioteca.buscar(10)->titulo == "Libro con \"comillas\"", "Pila intacta tras fallo");

            // La interfaz usa referencias a streams: podemos probar entrada inválida y EOF sin teclado real.
            istringstream entrada("abc\n2x\n99\n2\n20\n0\n");
            ostringstream transcripcion;
            Consola consola(biblioteca, entrada, transcripcion);
            consola.ejecutar();
            exigir(transcripcion.str().find("20 | POO") != string::npos, "Validacion de entrada");
            istringstream cerrada("");
            Consola consolaEOF(biblioteca, cerrada, transcripcion);
            consolaEOF.ejecutar();
            salida << "Comprobacion correcta: catalogo, busqueda, pila, cola, lista, BFS, Dijkstra y errores.\n";
            return 0;
        } catch (const exception& error) {
            salida << "Comprobacion fallida: " << error.what() << "\n";
            return 1;
        }
    }
}
