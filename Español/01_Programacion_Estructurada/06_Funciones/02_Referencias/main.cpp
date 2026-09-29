// Valor, referencia y referencia const
//
// Vamos a comparar una copia con una referencia. Si una variable es una caja, pasarla por valor
// entrega otra caja con el mismo contenido. Con int& ponemos otra etiqueta a la caja original: si
// cambiamos el dato mediante esa etiqueta, cambiamos el original. Una referencia queda ligada a la
// misma caja desde que nace; asignarle otro valor cambia el contenido, no la caja a la que se
// refiere. Con const int& podemos leer mediante la etiqueta, pero no escribir. En todos los casos
// necesitamos que la caja siga existiendo mientras la usamos.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

// Por valor: la función recibe otra caja con una copia del número.
void cambiarCopia(int copia) {
    copia = 99;
    cout << "Dentro de la copia: " << copia << "\n";
}

// Por referencia: este nombre es otra etiqueta para la caja original.
void cambiarOriginal(int& caja) {
    ++caja;
}

// const impide modificar la cadena a través de este parámetro; no se copia.
size_t longitud(const string& texto) {
    return texto.size();
}

int main() {
    int caja = 4;
    cambiarCopia(caja);
    cout << "Original tras paso por valor: " << caja << "\n";

    // En la llamada no escribimos &: la declaración del parámetro decide el paso.
    cambiarOriginal(caja);
    cout << "Original tras referencia: " << caja << "\n";

    int& alias = caja;
    int otro = 8;
    // Asignar al alias cambia caja. No lo vuelve a enlazar con otro.
    alias = otro;
    ++alias;
    cout << "Caja mediante alias: " << caja << "; otro: " << otro << "\n";

    const int& soloLectura = caja;
    // La vista const no congela caja: el nombre original todavía puede modificarla.
    caja = 12;
    cout << "Consulta const observa: " << soloLectura << "\n";

    const string texto = "C++";
    cout << "Longitud sin copiar: " << longitud(texto) << "\n";
}
