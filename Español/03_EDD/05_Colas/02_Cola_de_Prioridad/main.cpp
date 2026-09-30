// Cola de prioridad y heap
//
// Vamos a atender según importancia en lugar de llegada. priority_queue coloca arriba el valor con
// mayor prioridad: con enteros, normalmente es el mayor. Si queremos el menor, como un costo,
// usamos greater<int>, una regla de comparación de <functional>. Podemos imaginar urgencias de un
// hospital: llegar antes no siempre significa pasar antes. Con top consultamos el siguiente y con
// pop lo retiramos; siempre necesitamos que haya datos.
//
// Práctica: Vamos a atender tareas por prioridad.
// - Guardemos al menos tres niveles de prioridad distintos.
// - Mostremos el orden de salida y comparémoslo con el de llegada.

// Elegimos primero el menor valor de una cola de prioridad mediante greater.
#include <functional>
#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

int main() {
    priority_queue<int> gravedad;
    // greater cambia el criterio para poner el menor costo arriba, como una fila ordenada por
    // urgencia.
    priority_queue<int, vector<int>, greater<int>> costo;
    for (int dato : {2, 9, 4}) {
        gravedad.push(dato);
        costo.push(dato);
    }

    cout << "Mayor prioridad: " << gravedad.top() << "\n";
    cout << "Menor costo: " << costo.top() << "\n";
}
