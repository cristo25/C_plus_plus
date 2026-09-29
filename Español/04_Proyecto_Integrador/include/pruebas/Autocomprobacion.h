#ifndef PROYECTO_AUTOCOMPROBACION_H
#define PROYECTO_AUTOCOMPROBACION_H

#include <ostream>

namespace proyecto {
    using namespace std;
    // Una comprobación ejecutable con --self-test; funciona también con NDEBUG.
    int autocomprobar(ostream& salida);
}

#endif
