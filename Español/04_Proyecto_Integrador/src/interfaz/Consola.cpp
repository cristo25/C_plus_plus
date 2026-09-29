#include "interfaz/Consola.h"
#include <exception>
#include <limits>
#include <optional>
#include <sstream>
#include <string>

namespace proyecto {
    using namespace std;

    namespace {
        // Leemos una línea completa: 12abc no se acepta como 12 y EOF termina la sesión.
        optional<int> leerEntero(istream& entrada, ostream& salida, const string& pregunta,
                                 int minimo, int maximo) {
            string linea;
            while (true) {
                salida << pregunta << flush;
                if (!getline(entrada, linea)) {
                    return nullopt;
                }
                istringstream fila(linea);
                int valor = 0;
                if (fila >> valor && (fila >> ws).eof() && valor >= minimo && valor <= maximo) {
                    return valor;
                }
                salida << "Introduce un entero completo dentro del rango indicado.\n";
            }
        }

        optional<string> leerTitulo(istream& entrada, ostream& salida) {
            string linea;
            salida << "Titulo (maximo 200 bytes): " << flush;
            if (!getline(entrada, linea)) {
                return nullopt;
            }
            return linea;
        }

        void mostrarLibros(const Biblioteca& biblioteca, ostream& salida) {
            const auto vista = biblioteca.catalogoOrdenado();
            if (vista.empty()) {
                salida << "Catalogo vacio. Usa agregar libro.\n";
            }
            for (const Libro* libro : vista) {
                salida << libro->id << " | " << libro->titulo << "\n";
            }
        }

        void mostrarRuta(const Ruta& ruta, const MapaCampus& mapa, ostream& salida) {
            for (size_t indice = 0; indice < ruta.paradas.size(); ++indice) {
                if (indice != 0) {
                    salida << " -> ";
                }
                salida << mapa.nombres().at(ruta.paradas.at(indice));
            }
            salida << " | " << ruta.minutos << " minutos\n";
        }
    }

    Consola::Consola(Biblioteca& biblioteca, istream& entrada, ostream& salida)
        : biblioteca(biblioteca), entrada(entrada), salida(salida) {
    }

    void Consola::ejecutar() {
        salida << "BIBLIOTECA Y RUTAS DEL CAMPUS\nLos cambios del catalogo se guardan al confirmarse. Entregas e historial duran esta sesion.\n";
        while (true) {
            salida << "\n1 Catalogo | 2 Buscar ID | 3 Agregar libro\n"
                   << "4 Cambiar titulo | 5 Eliminar libro | 6 Deshacer cambio\n"
                   << "7 Solicitar entrega | 8 Atender siguiente | 9 Ver pendientes\n"
                   << "10 Historial | 11 Mapa y BFS | 0 Salir\n";
            const auto opcion = leerEntero(entrada, salida, "Opcion: ", 0, 11);
            if (!opcion || *opcion == 0) {
                salida << "Sesion finalizada.\n";
                return;
            }
            try {
                switch (*opcion) {
                case 1:
                    mostrarLibros(biblioteca, salida);
                    break;
                case 2: {
                    const auto id = leerEntero(entrada, salida, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    const Libro* libro = biblioteca.buscar(*id);
                    if (libro != nullptr) {
                        salida << libro->id << " | " << libro->titulo << "\n";
                    } else {
                        salida << "Libro no encontrado.\n";
                    }
                    break;
                }
                case 3:
                case 4: {
                    const auto id = leerEntero(entrada, salida, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    const auto titulo = leerTitulo(entrada, salida);
                    if (!titulo) {
                        return;
                    }
                    if (*opcion == 3) {
                        biblioteca.agregarLibro(Libro{*id, *titulo});
                    } else {
                        biblioteca.renombrarLibro(*id, *titulo);
                    }
                    salida << "Cambio confirmado.\n";
                    break;
                }
                case 5: {
                    const auto id = leerEntero(entrada, salida, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    biblioteca.eliminarLibro(*id);
                    salida << "Cambio confirmado.\n";
                    break;
                }
                case 6:
                    if (biblioteca.deshacer()) {
                        salida << "Cambio confirmado.\n";
                    } else {
                        salida << "No hay cambios para deshacer.\n";
                    }
                    break;
                case 7: {
                    const auto id = leerEntero(entrada, salida, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    for (size_t indice = 0; indice < biblioteca.mapa().nombres().size(); ++indice) {
                        salida << indice << " | " << biblioteca.mapa().nombres().at(indice) << "\n";
                    }
                    const int maximo = static_cast<int>(biblioteca.mapa().nombres().size()) - 1;
                    const auto origen = leerEntero(entrada, salida, "Edificio de origen: ", 0, maximo);
                    if (!origen) {
                        return;
                    }
                    const auto destino = leerEntero(entrada, salida, "Edificio de destino: ", 0, maximo);
                    if (!destino) {
                        return;
                    }
                    biblioteca.solicitarEntrega(*id, static_cast<size_t>(*origen), static_cast<size_t>(*destino));
                    salida << "Solicitud agregada a la cola.\n";
                    break;
                }
                case 8: {
                    const auto resultado = biblioteca.procesarEntrega();
                    if (!resultado) {
                        salida << "No hay entregas pendientes.\n";
                        break;
                    }
                    salida << resultado->entrega.libro.titulo << "\n";
                    mostrarRuta(resultado->ruta, biblioteca.mapa(), salida);
                    break;
                }
                case 9: {
                    const auto pendientes = biblioteca.entregasPendientes();
                    if (pendientes.empty()) {
                        salida << "No hay entregas pendientes.\n";
                    }
                    for (const Entrega& entrega : pendientes) {
                        salida << entrega.libro.id << " | " << entrega.libro.titulo << " | "
                               << biblioteca.mapa().nombres().at(entrega.origen) << " -> "
                               << biblioteca.mapa().nombres().at(entrega.destino) << "\n";
                    }
                    break;
                }
                case 10: {
                    const auto ordenInverso = leerEntero(entrada, salida, "Orden: 0 cronologico, 1 inverso: ", 0, 1);
                    if (!ordenInverso) {
                        return;
                    }
                    const auto eventos = biblioteca.historial(*ordenInverso == 1);
                    if (eventos.empty()) {
                        salida << "Historial vacio.\n";
                    }
                    for (const string& mensaje : eventos) {
                        salida << mensaje << "\n";
                    }
                    break;
                }
                case 11: {
                    const auto& mapa = biblioteca.mapa();
                    for (size_t origen = 0; origen < mapa.nombres().size(); ++origen) {
                        salida << origen << " | " << mapa.nombres().at(origen) << ": ";
                        for (const auto& edge : mapa.mapa().vecinos(origen)) {
                            salida << edge.destino << " (" << edge.peso << " minutos) ";
                        }
                        salida << "\n";
                    }
                    salida << "BFS desde Biblioteca: ";
                    for (size_t indice : mapa.alcanzables(0)) {
                        salida << indice << ' ';
                    }
                    salida << "\n";
                    break;
                }
                }
            } catch (const exception& error) {
                // La sesión continúa tras un dato inválido o un fallo de guardado; la capa de servicio protege el catálogo.
                salida << "Error: " << error.what() << "\n";
            }
        }
    }
}
