// Valor, referencia y referencia const
//
// Una variable es una caja. Pasar por valor entrega una segunda caja; pasar por
// referencia entrega otra etiqueta de la misma caja. Una referencia se inicializa
// y permanece ligada al mismo objeto: asignarle un valor cambia ese objeto.
// const T& es una etiqueta que permite leer, pero no escribir por ese acceso.
// El objeto debe seguir vivo durante el uso de la referencia.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Predice cada salida. Cambia int& por int y observa qué deja de cambiar.

#include <iostream>
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
