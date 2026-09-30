// Constructores, destructores
//
// Vamos a observar cuándo empieza y termina un objeto. El constructor tiene el nombre de la clase y
// prepara sus datos; en Sesion guarda el usuario y anuncia su entrada. El destructor lleva ~
// delante del nombre y se ejecuta cuando termina la vida del objeto. Podemos imaginar que abrimos
// una tienda y la cerramos al salir. En este ejemplo las llaves delimitan esa estancia: al llegar a
// su cierre aparece el mensaje de salida. Más adelante usaremos la misma idea para liberar memoria
// y cerrar archivos automáticamente.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

class Sesion {
    string usuario;

public:
    // Preparamos la sesión con el nombre que recibimos.
    Sesion(const string& nombre) : usuario(nombre) {
        cout << "Entra " << usuario << "\n";
    }
    // El destructor se ejecuta automáticamente cuando termina la vida del objeto.
    ~Sesion() {
        cout << "Sale " << usuario << "\n";
    }
};

int main() {
    {
        Sesion sesion("Ana");
    } // Aqui termina la vida de sesion.
    cout << "Sesion terminada\n";
}

// Práctica: vamos a crear una clase Partida que anuncie su inicio y su final.
// - Recibimos el nombre de la partida en el constructor.
// - Mostramos un mensaje en el destructor.
// - Creamos la partida dentro de un bloque de llaves y observamos el orden de los mensajes.
