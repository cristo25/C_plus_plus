#ifndef CURSO_LIBRO_DAO_H
#define CURSO_LIBRO_DAO_H

// Recibimos una fuente de lectura: puede ser teclado, archivo o texto en memoria.
#include <istream>
// Recibimos un destino de escritura: pantalla, archivo o texto en memoria.
#include <ostream>
// Leemos o escribimos texto en memoria como si fuera un archivo.
#include <sstream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    struct Libro {
        int id;
        string titulo;
    };

    // DAO: concentra el acceso a los datos; no decide reglas de prestamos.
    class LibroDAO {
        static constexpr int MAX_LIBROS = 10000;
        vector<Libro> libros;

        static bool tituloValido(const string& titulo) {
            return !titulo.empty() && titulo.find_first_of("\r\n") == string::npos;
        }

    public:
        // Buscamos libro por libro. Si el catálogo crece, podemos necesitar más comparaciones.
        // La dirección encontrada deja de servir si después cambiamos el vector.
        const Libro* buscar(int id) const {
            for (const auto& libro : libros) {
                if (libro.id == id) {
                    return &libro;
                }
            }
            return nullptr;
        }
        // Crear, consultar, actualizar y eliminar forman CRUD; el DAO concentra esas
        // operaciones.
        bool crear(const Libro& libro) {
            if (libros.size() >= static_cast<size_t>(MAX_LIBROS)) {
                return false;
            }
            if (libro.id <= 0 || !tituloValido(libro.titulo) || buscar(libro.id)) {
                return false;
            }
            libros.push_back(libro);
            return true;
        }
        bool actualizar(int id, const string& titulo) {
            if (!tituloValido(titulo)) {
                return false;
            }
            for (auto& libro : libros) {
                if (libro.id == id) {
                    libro.titulo = titulo;
                    return true;
                }
            }
            return false;
        }
        bool eliminar(int id) {
            for (auto it = libros.begin(); it != libros.end(); ++it) {
                if (it->id == id) {
                    libros.erase(it);
                    return true;
                }
            }
            return false;
        }
        const vector<Libro>& todos() const {
            return libros;
        }

        bool guardar(ostream& salida) const {
            salida << libros.size() << '\n';
            for (const auto& libro : libros) {
                // Dedicamos una línea al número y otra al título para conservar sus espacios.
                salida << libro.id << '\n' << libro.titulo << '\n';
            }
            return static_cast<bool>(salida);
        }
        bool cargar(istream& entrada) {
            // Leemos todos los libros en otro catálogo y solo al final reemplazamos el anterior.
            string linea;
            if (!getline(entrada, linea)) {
                return false;
            }
            istringstream cabecera(linea);
            int cantidad = 0;
            if (!(cabecera >> cantidad) || cantidad < 0 || cantidad > MAX_LIBROS) {
                return false;
            }
            char sobrante;
            if (cabecera >> sobrante) {
                return false;
            }
            LibroDAO nuevo;
            for (int i = 0; i < cantidad; ++i) {
                if (!getline(entrada, linea)) {
                    return false;
                }
                istringstream numero(linea);
                int id;
                if (!(numero >> id) || numero >> sobrante) {
                    return false;
                }
                string titulo;
                if (!getline(entrada, titulo)) {
                    return false;
                }
                if (!nuevo.crear({id, titulo})) {
                    return false;
                }
            }
            // Solo sustituimos el catálogo después de validar toda la copia.
            libros = nuevo.libros;
            return true;
        }
    };

} // namespace curso

#endif
