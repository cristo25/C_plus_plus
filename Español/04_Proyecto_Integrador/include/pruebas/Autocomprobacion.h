#ifndef PROYECTO_AUTOCOMPROBACION_H
#define PROYECTO_AUTOCOMPROBACION_H

// Recibimos un destino de escritura: pantalla, archivo o texto en memoria.
#include <ostream>

namespace proyecto {
    using namespace std;
    // Las comprobaciones usan condiciones que permanecen activas al compilar la versión final.
    int autocomprobar(ostream& salida);
}

#endif
