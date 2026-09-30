#include "datos/AlmacenCatalogo.h"
// Leemos y guardamos archivos con ifstream y ofstream.
#include <fstream>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Consultamos si una operación de archivos falló mediante error_code.
#include <system_error>

namespace proyecto {
    using namespace std;
    namespace fs = filesystem;

    AlmacenMemoria::AlmacenMemoria(const LibroDAO& inicial) : guardado(inicial) {
    }

    LibroDAO AlmacenMemoria::cargar() const {
        return guardado;
    }

    void AlmacenMemoria::guardar(const LibroDAO& dao) {
        guardado = dao;
    }

    AlmacenArchivo::AlmacenArchivo(const fs::path& archivo) : archivo(archivo) {
        if (this->archivo.empty() || this->archivo.filename().empty()) {
            throw invalid_argument("Ruta de catalogo invalida");
        }
    }

    LibroDAO AlmacenArchivo::cargar() const {
        fs::path origen = archivo;
        fs::path respaldo = archivo;
        respaldo += ".bak";
        // Si el reemplazo se interrumpió entre renombres, el respaldo conserva el catálogo anterior.
        if (!fs::exists(origen) && fs::exists(respaldo)) {
            origen = respaldo;
        }
        if (!fs::exists(origen)) {
            return {};
        }
        if (!fs::is_regular_file(origen)) {
            throw runtime_error("El catalogo debe ser un archivo normal");
        }
        ifstream entrada(origen);
        LibroDAO resultado;
        if (!entrada || !resultado.cargar(entrada)) {
            throw runtime_error("Catalogo invalido: se conserva el archivo para revisarlo");
        }
        // Si podemos leer otro carácter después de los libros, el archivo tiene datos de más.
        char sobrante;
        if (entrada >> sobrante || entrada.bad()) {
            throw runtime_error("El catalogo contiene datos adicionales o un error de lectura");
        }
        return resultado;
    }

    void AlmacenArchivo::guardar(const LibroDAO& dao) {
        if (!archivo.parent_path().empty()) {
            fs::create_directories(archivo.parent_path());
        }
        if (fs::exists(archivo) && !fs::is_regular_file(archivo)) {
            throw runtime_error("El catalogo debe ser un archivo normal");
        }
        fs::path temporal = archivo;
        temporal += ".tmp";
        fs::path respaldo = archivo;
        respaldo += ".bak";
        // Escribimos y cerramos una copia completa completa antes de tocar el catálogo anterior.
        ofstream salida(temporal, ios::trunc);
        if (!salida || !dao.guardar(salida)) {
            throw runtime_error("No se pudo escribir el catalogo temporal");
        }
        salida.close();
        if (!salida) {
            throw runtime_error("No se pudo cerrar el catalogo temporal");
        }

        const bool habiaAnterior = fs::exists(archivo);
        if (habiaAnterior) {
            fs::remove(respaldo);
            fs::rename(archivo, respaldo);
        }
        try {
            fs::rename(temporal, archivo);
        } catch (...) {
            if (habiaAnterior) {
                error_code error;
                fs::rename(respaldo, archivo, error);
                if (error) {
                    throw runtime_error("Fallo el reemplazo; el catalogo anterior sigue en el archivo .bak");
                }
            }
            throw;
        }
        // El catálogo nuevo ya está instalado; un respaldo que no se pueda borrar no invalida el guardado.
        error_code error;
        fs::remove(respaldo, error);
    }
}
