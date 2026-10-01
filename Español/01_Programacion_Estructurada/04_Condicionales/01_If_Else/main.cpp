// Decidir con if y else
//
// Vamos a decidir qué instrucciones ejecutar. Con if hacemos una pregunta, como si una persona
// tiene al menos 18 años. Si la respuesta es true, es decir, verdadera, entramos en sus llaves; con
// else atendemos el caso contrario. Podemos unir preguntas: && significa que ambas deben cumplirse,
// || que basta una y ! invierte una respuesta. Podemos imaginar dos puertas: la condición decide
// por cuál seguimos.
//
// Práctica: Vamos a realizar un programa que decida el acceso a un evento.
//
// - Guardar una edad y si hay un acompañante adulto.
// - Permitir el acceso a mayores de edad o menores acompañados.
// - Mostrar el motivo de la decisión.
// - Probar edades de 17 y 18 años.

#include <iostream>

using namespace std;

bool puedeEntrar(int edad, bool tieneBoleto) {
    // && exige que ambas condiciones sean verdaderas: edad suficiente y boleto.
    return edad >= 18 && tieneBoleto;
}

int main() {

    if (puedeEntrar(20, true)) {
        cout << "Entrada permitida\n";
    } else {
        cout << "Entrada rechazada\n";
    }
}
