// Ciclos
//
// Vamos a usar los tres ciclos en una misma tarea. Con for reunimos cantidades de varios días; con
// while retiramos grupos de diez hasta terminar; con do while mostramos al menos un aviso. Podemos
// pensar en un negocio: primero recibimos pedidos, después los entregamos y al final avisamos.
// Elegimos cada ciclo según cuándo necesitamos revisar su condición.
//
// Practica: Realiza un programa integrador que organice entregas.
//
// - Sumar pedidos de tres días con for.
// - Atender pedidos de uno en uno con while.
// - Mostrar al menos un aviso final con do while.
// - Contar y mostrar cuántos pedidos se atendieron.

#include <iostream>

using namespace std;

int main() {
    int total = 0;
    // for reúne inicio, condición y avance. Este ciclo acumula el trabajo de tres días.
    for (int dia = 1; dia <= 3; ++dia) {
        total += dia * 10;
    }
    int entregas = 0;
    // while comprueba la condición antes de cada entrega.
    while (total > 0) {
        total -= 10;
        ++entregas;
    }
    int avisos = 0;
    // do ejecuta el bloque al menos una vez y comprueba la condición al final.
    do {
        ++avisos;
    } while (avisos < 1);
    cout << "Entregas: " << entregas << ", avisos: " << avisos << "\n";
}
