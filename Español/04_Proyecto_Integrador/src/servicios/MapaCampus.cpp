#include "servicios/MapaCampus.h"
#include <algorithm>
#include <stdexcept>
#include <tuple>

namespace proyecto {
    using namespace std;

    MapaCampus::MapaCampus()
        : etiquetas{"Biblioteca", "Laboratorio", "Ingenieria", "Administracion", "Residencias", "Anexo sin conexion"},
          red(etiquetas.size()) {
        const array<tuple<size_t, size_t, int>, 6> conexiones{
            tuple<size_t, size_t, int>{0, 1, 4},
            tuple<size_t, size_t, int>{0, 2, 1},
            tuple<size_t, size_t, int>{2, 1, 1},
            tuple<size_t, size_t, int>{1, 3, 3},
            tuple<size_t, size_t, int>{2, 3, 6},
            tuple<size_t, size_t, int>{3, 4, 2}
        };
        // Cada camino funciona en ambos sentidos; el anexo 5 queda aislado para practicar ese caso.
        for (const auto& [origen, destino, minutos] : conexiones) {
            red.conectar(origen, destino, minutos);
            red.conectar(destino, origen, minutos);
        }
    }

    const array<string, 6>& MapaCampus::nombres() const {
        return etiquetas;
    }

    const Grafo& MapaCampus::mapa() const {
        return red;
    }

    vector<size_t> MapaCampus::alcanzables(size_t origen) const {
        return bfs(red, origen);
    }

    optional<Ruta> MapaCampus::rutaMinima(size_t origen, size_t destino) const {
        (void)etiquetas.at(destino);
        const auto resultado = caminosMinimos(red, origen);
        if (resultado.distancias.at(destino) == INFINITO) {
            return nullopt;
        }
        Ruta ruta{resultado.distancias.at(destino), {}};
        size_t actual = destino;
        // Seguimos las tarjetas de anterior desde el destino y luego invertimos el recorrido.
        while (actual != origen) {
            ruta.paradas.push_back(actual);
            const auto anterior = resultado.anteriores.at(actual);
            if (!anterior) {
                throw logic_error("La ruta tiene un enlace anterior invalido");
            }
            actual = *anterior;
        }
        ruta.paradas.push_back(origen);
        reverse(ruta.paradas.begin(), ruta.paradas.end());
        return ruta;
    }
}
