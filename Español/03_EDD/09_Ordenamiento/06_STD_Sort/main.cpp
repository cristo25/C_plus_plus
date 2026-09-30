// Ordenar con la biblioteca estándar
//
// Vamos a comparar lo aprendido con herramientas que C++ ya trae en <algorithm>. sort ordena un
// grupo entre begin() y end(); end() marca el lugar después del último dato. Para fichas de alumnos
// damos una función que decide cuál va primero. La función pequeña escrita con [] se llama lambda:
// aquí recibe dos alumnos y compara sus notas con <. stable_sort conserva el orden previo de
// quienes empatan. Primero entendemos los movimientos manuales y ahora podemos usar esta
// herramienta para resolver una tarea completa.
//
// Práctica: Vamos a ordenar fichas de alumnos por nota.
// - Creemos fichas con nombres y notas, incluidas notas iguales.
// - Ordenémoslas con sort y observemos qué ocurre con los empates.

// Usamos sort, stable_sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    vector<int> numeros{3, 1, 2};
    sort(numeros.begin(), numeros.end());

    vector<Alumno> grupo{{"Ana", 8}, {"Eva", 9}, {"Luis", 8}};
    // stable_sort conserva el orden original de los empates: Ana permanece antes que Luis.
    stable_sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.nota < b.nota;
    });

    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
