#ifndef CURSO_LIBRO_DAO_H
#define CURSO_LIBRO_DAO_H

#include <algorithm>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
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
        const Libro* buscar(int id) const {
            for (const auto& libro : libros) {
                if (libro.id == id) {
                    return &libro;
                }
            }
            return nullptr;
        }
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
            auto it = find_if(libros.begin(), libros.end(), [id](const Libro& libro) {
                return libro.id == id;
            });
            if (it == libros.end()) {
                return false;
            }
            libros.erase(it);
            return true;
        }
        const vector<Libro>& todos() const {
            return libros;
        }

        bool guardar(ostream& salida) const {
            salida << libros.size() << '\n';
            for (const auto& libro : libros) {
                salida << libro.id << ' ' << quoted(libro.titulo) << '\n';
            }
            return static_cast<bool>(salida);
        }
        bool cargar(istream& entrada) {
            // Lee una instantanea completa; si falla, conserva el estado anterior.
            string linea;
            if (!getline(entrada, linea)) {
                return false;
            }
            istringstream cabecera(linea);
            int cantidad = 0;
            if (!(cabecera >> cantidad) || cantidad < 0 || cantidad > MAX_LIBROS) {
                return false;
            }
            if (!(cabecera >> ws).eof()) {
                return false;
            }
            LibroDAO nuevo;
            for (int i = 0; i < cantidad; ++i) {
                if (!getline(entrada, linea)) {
                    return false;
                }
                istringstream fila(linea);
                Libro libro{};
                if (!(fila >> libro.id >> ws) || fila.peek() != '"') {
                    return false;
                }
                if (!(fila >> quoted(libro.titulo)) || !(fila >> ws).eof()) {
                    return false;
                }
                if (!nuevo.crear(libro)) {
                    return false;
                }
            }
            libros = move(nuevo.libros);
            return true;
        }
    };

} // namespace curso

#endif
