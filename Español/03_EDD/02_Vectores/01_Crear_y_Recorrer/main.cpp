// Crear y recorrer un vector
//
// Vamos a usar un cajón cuya cantidad de casillas puede crecer: vector<int>, de <vector>. Con
// push_back agregamos al final y con size consultamos cuántos datos hay. Recorremos los números
// para sumarlos. Cuando se llena el espacio reservado, el vector puede mudarse a otro bloque y
// llevarse sus datos; las direcciones anteriores ya no sirven. Normalmente agregar al final
// requiere poco trabajo; al repartir las mudanzas entre muchas inserciones, el trabajo medio por
// inserción permanece acotado (O(1) amortizado: repartimos el costo de crecer entre muchas
// operaciones).
//

#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 20};
    // Agregamos una casilla al cajón. Si falta espacio, el vector puede mudar todos sus datos a
    // otro lugar.
    numeros.push_back(30);
    int suma = 0;
    for (int numero : numeros) {
        suma += numero;
    }

    cout << "Suma: " << suma << "\n";
}
