// Cadenas con string
//
// Vamos a trabajar con texto usando string. Podemos imaginar un collar en el que cada cuenta es una
// letra o un signo. Con + unimos textos, con size contamos sus posiciones y con find buscamos una
// parte. Si la búsqueda devuelve string::npos, esa parte no existe. Solo después de comprobarlo
// usamos substr para tomar un fragmento. Aquí trabajamos con texto sencillo; una letra con acento
// puede ocupar más de una posición según cómo se guarde.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    string nombre = "Ana";
    string saludo = "Hola, " + nombre;
    // find devuelve el índice del texto encontrado, o string::npos cuando no existe.
    auto posicion = saludo.find(nombre);

    cout << saludo << "\n";
    if (posicion != string::npos) {
        // Solo extraemos la subcadena después de comprobar que hubo una coincidencia.
        cout << saludo.substr(posicion) << "\n";
    }
}
