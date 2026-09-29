// Memoria dinámica manual
//
// Vamos a crear una caja mientras el programa está funcionando. Con new int(42) reservamos espacio
// para un entero y recibimos su dirección. Guardamos esa dirección en numero y con *numero
// consultamos el 42. Esa caja no desaparece por dejar de usar la variable puntero: aquí debemos
// liberarla una sola vez con delete. Después ponemos numero en nullptr para no reutilizar esa
// dirección. Nunca usamos delete sobre una variable normal ni seguimos un puntero después de
// liberar su dato.
//

#include <iostream>

using namespace std;

int main() {
    // new reserva un entero y devuelve su dirección; este ejemplo asume la liberación manual.
    int* numero = new int(42);

    cout << *numero << "\n";
    // Liberamos una sola vez la memoria reservada con new; el puntero deja de referir un objeto
    // vivo.
    delete numero;
    numero = nullptr; // Evita reutilizar esta direccion por accidente.
}
