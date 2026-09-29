#ifndef PROYECTO_CONSOLA_H
#define PROYECTO_CONSOLA_H

// Recibimos una fuente de lectura: puede ser teclado, archivo o texto en memoria.
#include <istream>
// Recibimos un destino de escritura: pantalla, archivo o texto en memoria.
#include <ostream>
#include "servicios/Biblioteca.h"

namespace proyecto {
    using namespace std;

    // La interfaz pide datos y presenta resultados; Biblioteca aplica las reglas.
    class Consola {
        Biblioteca& biblioteca;
        istream& entrada;
        ostream& salida;
    public:
        Consola(Biblioteca& biblioteca, istream& entrada, ostream& salida);
        void ejecutar();
    };
}

#endif
