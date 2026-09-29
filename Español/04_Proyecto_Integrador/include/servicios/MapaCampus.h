#ifndef PROYECTO_MAPA_CAMPUS_H
#define PROYECTO_MAPA_CAMPUS_H

// Guardamos un resultado que puede faltar: optional tiene un valor o está vacío.
#include <optional>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "modelos/Entrega.h"
#include "../../../03_EDD/08_Grafos/Grafo.h"

namespace proyecto {
    using namespace std;
    using namespace curso;

    class MapaCampus {
        // Seis edificios fijos; las aristas guardan minutos, no distancia física.
        const vector<string> etiquetas;
        Grafo red;
    public:
        MapaCampus();
        const vector<string>& nombres() const;
        const Grafo& mapa() const;
        vector<size_t> alcanzables(size_t origen) const;
        optional<Ruta> rutaMinima(size_t origen, size_t destino) const;
    };
}

#endif
