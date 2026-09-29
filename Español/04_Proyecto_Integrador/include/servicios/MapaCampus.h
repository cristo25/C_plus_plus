#ifndef PROYECTO_MAPA_CAMPUS_H
#define PROYECTO_MAPA_CAMPUS_H

#include <array>
#include <optional>
#include <string>
#include <vector>
#include "modelos/Entrega.h"
#include "../../../03_EDD/08_Grafos/Grafo.h"

namespace proyecto {
    using namespace std;
    using namespace curso;

    class MapaCampus {
        // Seis edificios fijos; las aristas guardan minutos, no distancia física.
        const array<string, 6> etiquetas;
        Grafo red;
    public:
        MapaCampus();
        const array<string, 6>& nombres() const;
        const Grafo& mapa() const;
        vector<size_t> alcanzables(size_t origen) const;
        optional<Ruta> rutaMinima(size_t origen, size_t destino) const;
    };
}

#endif
