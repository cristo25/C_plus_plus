#include "servicios/MapaCampus.h"
// Usamos reverse para ordenar o cambiar el orden de los datos.
#include <algorithm>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>

namespace proyecto {
    using namespace std;

    MapaCampus::MapaCampus()
        : etiquetas{"Biblioteca", "Laboratorio", "Ingenieria", "Administracion", "Residencias", "Anexo sin conexion"},
          red(etiquetas.size()) {
        struct Conexion {
            size_t origen;
            size_t destino;
            int minutos;
        };
        const Conexion conexiones[6]{
            Conexion{0, 1, 4},
            Conexion{0, 2, 1},
            Conexion{2, 1, 1},
            Conexion{1, 3, 3},
            Conexion{2, 3, 6},
            Conexion{3, 4, 2}
        };
        // Cada camino funciona en ambos sentidos; el anexo 5 queda aislado para practicar ese caso.
        for (const auto& [origen, destino, minutos] : conexiones) {
            red.conectar(origen, destino, minutos);
            red.conectar(destino, origen, minutos);
        }
    }

    const vector<string>& MapaCampus::nombres() const {
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
