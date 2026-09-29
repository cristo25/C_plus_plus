#ifndef PROYECTO_ALMACEN_CATALOGO_H
#define PROYECTO_ALMACEN_CATALOGO_H

#include <filesystem>
#include "../../../02_POO/09_DAO/LibroDAO.h"

namespace proyecto {
    using namespace std;
    using namespace curso;

    // Dos variantes reales: sesión de demostración en memoria y catálogo persistente en archivo.
    class AlmacenCatalogo {
    public:
        virtual ~AlmacenCatalogo() = default;
        virtual LibroDAO cargar() const = 0;
        virtual void guardar(const LibroDAO& dao) = 0;
    };

    class AlmacenMemoria : public AlmacenCatalogo {
        LibroDAO guardado;
    public:
        explicit AlmacenMemoria(LibroDAO inicial = {});
        LibroDAO cargar() const override;
        void guardar(const LibroDAO& dao) override;
    };

    class AlmacenArchivo : public AlmacenCatalogo {
        filesystem::path archivo;
    public:
        explicit AlmacenArchivo(filesystem::path archivo);
        LibroDAO cargar() const override;
        void guardar(const LibroDAO& dao) override;
    };
}

#endif
