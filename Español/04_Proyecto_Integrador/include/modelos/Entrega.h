#ifndef PROYECTO_ENTREGA_H
#define PROYECTO_ENTREGA_H

// Usamos size_t para contar elementos y representar posiciones no negativas.
#include <cstddef>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "../../../02_POO/09_DAO/LibroDAO.h"

namespace proyecto {
    using namespace std;
    using namespace curso;

    // Una solicitud guarda una copia del libro: no conserva punteros al vector del DAO.
    struct Entrega {
        Libro libro;
        size_t origen;
        size_t destino;
    };

    struct Ruta {
        long long minutos;
        vector<size_t> paradas;
    };

    struct EntregaResuelta {
        Entrega entrega;
        Ruta ruta;
    };
}

#endif
