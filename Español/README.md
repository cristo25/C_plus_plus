# Aprende C++ paso a paso

Esta es la guía general del curso: programación estructurada, programación orientada a objetos (POO) y estructuras de datos y algoritmos (EDD). Cada tema combina una explicación, una analogía cuando ayuda y un bloque de código. Hay **83 programas independientes**.

Las explicaciones particulares, instrucciones de compilación y ejercicios están como **comentarios dentro de los archivos `.cpp` y `.h`**. En POO y EDD se conservan guías para comparar conceptos y variantes; no necesitas un README para cada programa.

## Orden de estudio

1. [Programación estructurada](#programación-estructurada): datos, decisiones, ciclos y funciones.
2. [Programación orientada a objetos](#programación-orientada-a-objetos): estado, comportamiento y propiedad.
3. [Estructuras de datos y algoritmos](#estructuras-de-datos-y-algoritmos): organización de datos, recorridos y costos.

Sigue los números de las carpetas. Lee los comentarios de `main.cpp` y predice su salida. En los temas divididos, termina las subcarpetas antes del `main.cpp` que está junto a ellas. Si usa un header del curso, léelo también para ver la implementación. Ejecuta el ejemplo y prueba el ejercicio que aparece en sus comentarios.

## Compilar y ejecutar

Usa C++17 con GCC (`g++`) o Clang (`clang++`). Abre Git Bash o PowerShell **en la carpeta del ejemplo**, no en la raíz del curso:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada ejemplo tiene su propio `main`. Compila un programa a la vez. En Linux o macOS puedes usar `programa` en lugar de `programa.exe`. Los bloques de esta guía corresponden al archivo enlazado; ejecuta ese archivo desde su carpeta. Los programas que escriben archivos los crean en el directorio de ejecución.

Estos ejemplos compilan más de un archivo de implementación:

| Carpeta | Archivos que debes compilar juntos |
| --- | --- |
| `01_Programacion_Estructurada/12_Const_y_Headers` | `main.cpp Calificaciones.cpp` |
| `02_POO/08_Headers` | `main.cpp Producto.cpp` |
| `03_EDD/11_Const_y_Headers` | `main.cpp Consultas.cpp` |
| `03_EDD/13_Combinacion_de_Conceptos` | `main.cpp ../../02_POO/08_Headers/Producto.cpp` |

Los pasos de combinación que usan `Producto` también enlazan `Producto.cpp`. Desde una subcarpeta del tema, su ruta empieza con `../../../02_POO/`; el comando completo aparece al inicio de cada `main.cpp`.

Por ejemplo, dentro de `02_POO/08_Headers`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Producto.cpp -o programa.exe
./programa.exe
```

Incluye el `.h`, nunca el `.cpp`. Las declaraciones permiten llamar funciones de otros archivos; el compilador y el enlazador necesitan sus definiciones.

## Programación estructurada

Aprende a representar datos, decidir, repetir y dividir tareas antes de diseñar objetos.

### 1. Tu primer programa

`#include` incorpora declaraciones de la biblioteca estándar; `main` es el punto de entrada y `cout` escribe en la consola. El programa termina con código 0 cuando todo va bien.

Analogía: El programa es una receta. `main` indica dónde comienza el cocinero y cada instrucción es un paso.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/01_Hola_Mundo/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hola, C++!\n";
    return 0;
}
```

### 2. Variables, tipos y operadores

Declara `int`, `double`, `char`, `bool` y `string`. Usa `const` para datos que no cambian. La división entre enteros descarta la parte decimal; convierte un operando a `double` cuando necesites conservarla.

Analogía: Una variable es una caja etiquetada; su tipo determina qué puede guardar. `const` pone un sello que impide cambiar el contenido.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/02_Variables_y_Tipos/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string producto = "Cuaderno";
    int cantidad = 3;
    const double precio = 12.5;
    const char categoria = 'A';
    const bool disponible = cantidad > 0;
    const double total = cantidad * precio;

    cout << producto << ": " << total << "\n";
    cout << categoria << " disponible: " << boolalpha << disponible << "\n";
    cout << "Division entera: " << 5 / 2 << "\n";
    cout << "Division decimal: " << 5.0 / 2 << "\n";
}
```

### 3. Leer y mostrar datos

`getline` lee una línea completa. `getline(cin, ...)` captura la edad como texto y un `istringstream` la interpreta; comprueba el resultado antes de usarlos. Una entrada incorrecta debe producir un mensaje y terminar sin calcular con datos inválidos.

Analogía: La consola es una ventanilla: entra una solicitud, verificas que esté completa y entregas una respuesta.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/03_Entrada_y_Salida/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string nombre;
    int edad = 0;
    cout << "Nombre: ";
    if (!getline(cin, nombre) || nombre.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Nombre invalido.\n";
        return 1;
    }
    cout << "Edad: ";
    string linea;
    if (!getline(cin, linea)) {
        return 1;
    }
    istringstream lectura(linea);
    if (!(lectura >> edad) || edad < 0 || edad > 130 || !(lectura >> ws).eof()) {
        cerr << "Edad invalida.\n";
        return 1;
    }
    cout << "Hola, " << nombre << ". Tienes " << edad << " anios.\n";
}
```

### 4. Condicionales

Aprende a elegir caminos y luego calcula un precio combinando `switch` e `if`. Resultado del integrador: `25`.

**Decidir con if y else.** Una condición produce `true` o `false`. `if`, `else if` y `else` eligen una rama. Combina condiciones con `&&`, `||` y `!`.

Analogía: Es una bifurcación: tomas un camino distinto según la señal que encuentras.

**Elegir con switch.** `switch` elige entre valores concretos de un entero, carácter o enumeración. `break` termina un caso; `default` atiende valores desconocidos.

Analogía: Un menú de restaurante tiene opciones numeradas. Cada número lleva a una preparación.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/04_Condicionales/main.cpp).

```cpp
#include <iostream>

using namespace std;

int precio(int opcion, bool estudiante) {
    int base = 0;
    switch (opcion) {
        case 1:
            base = 20;
            break;
        case 2:
            base = 30;
            break;
        default:
            return -1;
    }
    if (estudiante) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Bebida 2 con descuento: " << precio(2, true) << "\n";
}
```

### 5. Ciclos

Compara cuándo se evalúa la condición. El integrador acumula pedidos, los entrega y emite un aviso; produce `6` entregas y `1` aviso.

**Repetir con for.** `for` reúne inicio, condición y avance. Es apropiado cuando conoces cuántas repeticiones necesitas.

Analogía: Recorres cinco casilleros, uno por uno, sin saltarte ninguno.

**Repetir con while.** `while` comprueba la condición antes de cada vuelta. Puede ejecutarse cero veces; modifica algo que permita terminar.

Analogía: Llenas una alcancía mientras no alcanzas la meta.

**Repetir con do while.** `do while` evalúa la condición después del cuerpo, por lo que siempre ejecuta al menos una vuelta.

Analogía: Pruebas una llave al menos una vez antes de decidir si necesitas seguir intentando.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/05_Ciclos/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    int total = 0;
    for (int dia = 1; dia <= 3; ++dia) {
        total += dia * 10;
    }
    int entregas = 0;
    while (total > 0) {
        total -= 10;
        ++entregas;
    }
    int avisos = 0;
    do {
        ++avisos;
    } while (avisos < 1);
    cout << "Entregas: " << entregas << ", avisos: " << avisos << "\n";
}
```

### 6. Funciones

Divide un problema en tareas pequeñas. El integrador calcula un subtotal por valor y aplica un cupón por referencia; el total es `50`.

**Funciones: parámetros y retorno.** Una función recibe datos, realiza una tarea y puede devolver un resultado. Los parámetros por valor son copias: cambiarlos no modifica el original.

Analogía: Una máquina recibe ingredientes por una entrada y entrega un producto por la salida.

**Valor, referencia y referencia const.** Imagina una caja con el número 4. Un parámetro `int` recibe otra caja con una copia: modificarla no cambia la original. Un parámetro `int&` pone otra etiqueta sobre la caja original: modificarlo cambia el dato del llamador. `const string&` presta una etiqueta de lectura y evita copiar la cadena.

El `&` en `int& alias = caja;` declara una referencia; en `&caja` obtiene una dirección. En una llamada como `cambiarOriginal(caja)` no se escribe `&`: el tipo del parámetro decide si se copia o se usa la referencia. La referencia necesita un objeto válido y no se puede volver a enlazar; `alias = otro` asigna el valor de `otro` a la caja original. Una referencia `const` limita ese acceso, pero otro acceso no constante todavía puede cambiar el objeto.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/06_Funciones/02_Referencias/main.cpp).

```cpp
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
```

Después compara estas llamadas con las funciones del integrador del tema.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/06_Funciones/main.cpp).

```cpp
#include <iostream>

using namespace std;

int subtotal(int cantidad, int precio) {
    return cantidad * precio;
}
void aplicarCupon(int& total) {
    if (total >= 50) {
        total -= 10;
    }
}

int main() {
    int total = subtotal(3, 20);
    aplicarCupon(total);

    int pequeno = 20;
    aplicarCupon(pequeno);

    cout << "Total: " << total << "\n";
}
```

### 7. Arreglos

Empieza con un cajón y después con un mueble. El integrador guarda notas en una matriz y sus promedios en un arreglo: `9` y `8`.

**Arreglos unidimensionales.** `array<int, 4>` guarda cuatro enteros contiguos. El tamaño es fijo y los índices van de 0 a 3. `at()` comprueba el índice; `[]` requiere que tú garantices que sea válido. Un arreglo tradicional se escribe `int datos[4]`, pero no ofrece `at()`.

Analogía: Un arreglo es un cajón para un solo tipo de cosas, dividido en secciones numeradas desde cero. No cabe una quinta cosa en un cajón de cuatro secciones.

**Matrices.** Una matriz tiene filas y columnas. Aquí usamos un `array` de arreglos; ambos índices comienzan en cero.

Analogía: Un mueble tiene varios cajones (filas) y cada cajón tiene compartimentos (columnas).

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/07_Arreglos/main.cpp).

```cpp
#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> notas{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> promedios{};
    for (size_t fila = 0; fila < notas.size(); ++fila) {
        int suma = 0;
        for (int nota : notas.at(fila)) {
            suma += nota;
        }
        promedios.at(fila) = static_cast<double>(suma) / notas.at(fila).size();
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}
```

### 8. Cadenas con string

`string` administra una secuencia de caracteres. Puedes concatenar, consultar el tamaño, buscar y extraer fragmentos. Comprueba `string::npos` antes de usar un resultado de búsqueda.

Analogía: Una cadena es un collar: cada carácter es una cuenta; puedes unir collares o tomar un tramo.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/08_Cadenas/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre = "Ana";
    string saludo = "Hola, " + nombre;
    auto posicion = saludo.find(nombre);

    cout << saludo << "\n";
    if (posicion != string::npos) {
        cout << saludo.substr(posicion) << "\n";
    }
}
```

### 9. Punteros: dirección y contenido

Piensa en un cuarto con cajas. Cada variable es una caja de un tipo de dato; su dirección indica dónde localizarla. Un puntero es otra variable, como una tarjeta que guarda esa dirección. La tarjeta y la caja son objetos distintos. Una referencia es otra etiqueta de la caja; un puntero es una tarjeta independiente que puede cambiar de destino.

```cpp
int caja = 10;
int* direccion = &caja;
int** tarjetaDeTarjeta = &direccion;
```

```text
tarjetaDeTarjeta: [dirección de direccion]
                           |
                           v
direccion:       [dirección de caja]
                           |
                           v
caja:            [10]
```

`&caja` pregunta dónde está la caja. `direccion` lee la dirección guardada en la tarjeta. `*direccion` sigue una dirección y llega al entero. `&direccion` obtiene la dirección de la propia tarjeta. `*tarjetaDeTarjeta` llega al puntero `direccion`; `**tarjetaDeTarjeta` llega al entero `caja`. No son dos cajas de enteros: hay dos variables que guardan direcciones y un entero.

**Copiar, escribir y redirigir.** `int* otra = direccion` copia una tarjeta, no el entero. Las dos tarjetas apuntan a la misma caja. `*otra = 25` modifica esa caja y ambos punteros observan el cambio. `otra = &otraCaja` redirige solo `otra`; no mueve la caja ni redirige `direccion`. `otra = nullptr` deja esa tarjeta sin destino; no destruye ninguna caja.

**Pasar datos a funciones.** Decide primero qué necesita cambiar la función:

| Parámetro | Qué recibe | Qué puede cambiar | Llamada típica |
| --- | --- | --- | --- |
| `int dato` | Otra caja con una copia | Su copia local | `funcion(caja)` |
| `int& dato` | Otra etiqueta de la caja | El entero original | `funcion(caja)` |
| `const int& dato` | Una etiqueta de lectura | No cambia el entero por ese acceso | `funcion(caja)` |
| `int* dato` | Una copia de la tarjeta | El entero de destino; redirigir la copia no cambia la tarjeta del llamador | `funcion(direccion)` o `funcion(&caja)` |
| `int*& dato` | Una etiqueta de la tarjeta del llamador | La tarjeta original y, si tiene destino válido, su entero | `funcion(direccion)` |
| `int** dato` | Una tarjeta que apunta a otra tarjeta | El puntero original con `*dato`; su entero con `**dato`, si ambos destinos son válidos | `funcion(&direccion)` |

El ejemplo imprime si cada llamada conserva o cambia la dirección original. Primero modifica el entero mediante `int*`; después redirige una copia local; luego cambia la tarjeta original mediante `int*&` y mediante `int**`. La referencia al nuevo destino necesita que ese entero siga vivo después de la llamada.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/09_Punteros_Basicos/main.cpp).

```cpp
#include <iostream>

using namespace std;

// Se copia la tarjeta con la dirección; el entero al que apunta sigue siendo el original.
void sumarDesdeDireccion(int* direccion) {
    if (direccion != nullptr) {
        ++*direccion;
    }
}

void redirigirCopia(int* direccion, int& otro) {
    // Solo redirigimos la copia local de la tarjeta. El puntero del llamador no cambia.
    direccion = &otro;
    cout << "Destino de la copia local: " << *direccion << "\n";
}

void redirigirReferencia(int*& direccion, int& otro) {
    // int*& es un alias de la tarjeta del llamador: podemos cambiar su destino.
    direccion = &otro;
}

void redirigirDoble(int** direccion, int& otro) {
    // int** guarda la dirección de una tarjeta. *direccion es esa tarjeta, no el entero.
    if (direccion != nullptr) {
        *direccion = &otro;
    }
}

int main() {
    cout << boolalpha;
    int caja = 10;
    int otraCaja = 20;

    // &caja obtiene su dirección; int* declara una tarjeta para un entero.
    int* direccion = &caja;
    int* alias = direccion;
    *direccion = 25;
    cout << "Dos tarjetas, una caja: " << *alias << "\n";

    sumarDesdeDireccion(direccion);
    sumarDesdeDireccion(nullptr);
    cout << "Caja tras int*: " << caja << "\n";

    redirigirCopia(direccion, otraCaja);
    cout << "La tarjeta original sigue en caja: " << (direccion == &caja) << "\n";

    redirigirReferencia(direccion, otraCaja);
    cout << "Referencia redirigió la tarjeta: " << (direccion == &otraCaja) << "\n";

    // &direccion señala la variable puntero. ** de esa dirección alcanzaría el entero.
    redirigirDoble(&direccion, caja);
    cout << "Doble puntero la devolvió a caja: " << (direccion == &caja) << "\n";

    const int* soloLectura = &caja;
    // El dato no se puede cambiar por soloLectura; la tarjeta sí puede cambiar de destino.
    soloLectura = &otraCaja;
    cout << "Lectura por const int*: " << *soloLectura << "\n";

    int* const direccionFija = &caja;
    // La tarjeta no puede redirigirse; el contenido de su destino sí puede modificarse.
    *direccionFija = 30;
    cout << "Escritura por int* const: " << caja << "\n";

    // nullptr no libera caja ni anula otras tarjetas. Cada observador es independiente.
    direccion = nullptr;
    alias = nullptr;
}
```

**Dónde va `const`.** En `const int* p`, la tarjeta puede redirigirse, pero no permite escribir en el entero. En `int* const p`, la tarjeta tiene un destino fijo y permite escribir en el entero. En `const int* const p`, ambos accesos quedan limitados. Esto no congela un objeto modificable por otros accesos: limita lo que puede hacerse a través de ese nombre.

**Cuándo deja de servir una dirección.** Una tarjeta no mantiene viva su caja. Un puntero a una variable local deja de ser válido cuando termina el bloque de esa variable; no retornes esa dirección. Un puntero a un objeto destruido está colgando aunque no valga `nullptr`. Comparar con `nullptr` solo detecta la ausencia de destino, no comprueba que un objeto siga vivo. Tampoco limpiar una tarjeta limpia las demás copias de su dirección.

`new` crea un objeto de duración dinámica y `delete` destruye uno creado de esa forma; no uses `delete` con una variable local ni con un elemento de un arreglo propietario. Más adelante `unique_ptr` administrará esa destrucción automáticamente. `get()` presta una dirección, sin transferir la responsabilidad.

**Arreglos y direcciones.** Un arreglo guarda elementos contiguos del mismo tipo. Si `int* p = numeros.data();`, `p + 1` apunta al siguiente entero, no al siguiente byte. La aritmética solo es válida dentro del mismo arreglo y hasta la posición inmediatamente posterior a su último elemento; esa posición posterior no se desreferencia. Un `vector` puede realocar al crecer e invalidar referencias y punteros a sus elementos. Un arreglo de punteros contiene tarjetas: no debe confundirse con un puntero al primer elemento de un arreglo.

En POO, `puntero->metodo()` es equivalente a `(*puntero).metodo()` para estos punteros ordinarios. La [ruta de combinación de conceptos](03_EDD/13_Combinacion_de_Conceptos/README.md) lleva la misma analogía a arreglos y vectores de punteros, matrices, nodos y clases que administran listas.

### 10. Leer y escribir archivos

`ofstream` escribe y `ifstream` lee. Comprueba apertura, escritura y lectura. Los objetos cierran los archivos al salir de su bloque. `ios::app` agrega contenido al final.

Analogía: La memoria es un pizarrón que se borra al terminar; un archivo es un cuaderno que conserva tus anotaciones.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/10_Archivos/main.cpp).

```cpp
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";
    {
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo.\n";
            return 1;
        }
        salida << "Estudiar C++\n";
        salida.close();
        if (!salida) {
            cerr << "Error al guardar.\n";
            return 1;
        }
    }
    ifstream entrada(ruta);
    if (!entrada) {
        cerr << "No se pudo leer.\n";
        return 1;
    }
    string linea;
    while (getline(entrada, linea)) {
        cout << linea << "\n";
    }
    if (!entrada.eof()) {
        cerr << "Error de lectura.\n";
        return 1;
    }
}
```

### 11. Recursión

Una función recursiva se llama a sí misma con un problema menor. El caso base detiene las llamadas. Sin caso base o sin avance, la pila de llamadas puede agotarse.

Analogía: Abres una caja que contiene otra más pequeña, hasta llegar a una caja vacía.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/11_Recursion/main.cpp).

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Usa un numero entre 0 y 12");
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {

    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
```

### 12. Const y headers en programación estructurada

`const` impide cambiar un dato desde su declaración. Las notas y el promedio de este ejemplo no cambian, por eso son constantes. `const array<int, 3>&` permite consultar las notas sin copiarlas ni modificarlas. `constexpr` indica que un valor puede evaluarse en compilación; las constantes `inline constexpr` del header se pueden compartir entre archivos de implementación.

`Calificaciones.h` declara las funciones y sus constantes. `Calificaciones.cpp` define las operaciones. `main.cpp` organiza la ejecución. No hace falta una clase para dividir un programa en archivos.

Analogía: El header es una ficha de instrucciones: dice qué servicio puedes pedir. El `.cpp` realiza el trabajo. `const` pone una vitrina sobre el cajón: puedes ver sus notas sin moverlas.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/12_Const_y_Headers/main.cpp).

```cpp
#include "Calificaciones.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace curso;

int main() {
    const array<int, 3> notas{8, 9, 10};
    try {
        const double promedio = calcularPromedio(notas);
        cout << "Promedio: " << promedio << "\n";
        if (estaAprobado(promedio)) {
            cout << "Aprobado\n";
        } else {
            cout << "Reprobado\n";
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
```

### 13. Integrador: reporte de calificaciones

Combina funciones, referencias, cadenas, arreglos, ciclos, condiciones, un puntero no propietario y un archivo. Lee el código en orden: calcular, clasificar, construir el reporte y guardarlo.

Analogía: Un maestro revisa un cajón de notas, calcula un promedio y lo anota en su cuaderno.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/13_Integrador/main.cpp).

```cpp
#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double promedio(const array<int, 3>& notas) {
    int suma = 0;
    for (int nota : notas) {
        suma += nota;
    }
    return static_cast<double>(suma) / notas.size();
}

int main() {
    const array<int, 3> notas{8, 9, 10};
    const double resultado = promedio(notas);
    const double* consulta = &resultado;

    string estado;
    if (*consulta >= 6) {
        estado = "Aprobado";
    } else {
        estado = "Reprobado";
    }
    const string reporte = "Ana: " + to_string(*consulta) + " - " + estado;
    ofstream salida("reporte_demo.txt", ios::app);
    if (!salida) {
        cerr << "No se pudo abrir el reporte.\n";
        return 1;
    }
    salida << reporte << "\n";
    salida.close();
    if (!salida) {
        cerr << "No se pudo guardar.\n";
        return 1;
    }

    cout << reporte << "\n";
}
```

## Programación orientada a objetos

Usa los fundamentos anteriores para organizar estado, comportamiento, propiedad y acceso a datos.

[Guía del bloque](02_POO/README.md).

### 1. Clases y objetos

Una clase define datos y operaciones; un objeto es una instancia concreta. `public` permite usar esos miembros desde fuera. En el siguiente tema protegeremos los datos con `private`.

Analogía: La clase es el plano de una bicicleta; cada bicicleta construida es un objeto con su propio color.

Ejemplo completo: [main.cpp](02_POO/01_Clases_y_Objetos/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Bicicleta {
public:
    string color;
    int velocidad = 0;
    void pedalear() {
        velocidad += 5;
    }
};

int main() {
    Bicicleta roja;
    roja.color = "roja";
    Bicicleta azul;
    azul.color = "azul";
    roja.pedalear();

    cout << "Bicicleta " << roja.color << ": " << roja.velocidad << "\n";
    cout << "Bicicleta " << azul.color << ": " << azul.velocidad << "\n";
}
```

### 2. Encapsulamiento y const

`private` protege el estado. Los métodos públicos controlan cambios válidos; los métodos `const` consultan sin modificar el objeto. No necesitas un getter y un setter por cada atributo.

Analogía: Una alcancía no deja meter la mano directamente: sus operaciones controlan cómo entra y sale el dinero.

Ejemplo completo: [main.cpp](02_POO/02_Encapsulamiento/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Alcancia {
    int saldo = 0; // Centavos enteros para evitar errores de redondeo.
public:
    bool depositar(int centavos) {
        if (centavos <= 0 || centavos > 1000000 - saldo) {
            return false;
        }
        saldo += centavos;
        return true;
    }
    bool retirar(int centavos) {
        if (centavos <= 0 || centavos > saldo) {
            return false;
        }
        saldo -= centavos;
        return true;
    }
    int consultar() const {
        return saldo;
    }
};

int main() {
    Alcancia ahorro;
    if (ahorro.depositar(-5)) {
        return 1;
    }
    if (!(ahorro.depositar(500))) {
        return 1;
    }
    if (ahorro.retirar(600)) {
        return 1;
    }
    if (!(ahorro.retirar(200))) {
        return 1;
    }

    cout << ahorro.consultar() << " centavos\n";
}
```

### 3. Constructores, destructores y RAII

El constructor establece un estado inicial válido y el destructor corre al terminar la vida del objeto. RAII vincula la vida de un recurso a la de un objeto; `string`, archivos y punteros inteligentes ya lo hacen.

Analogía: Al abrir una tienda colocas el letrero; al cerrar recoges lo que administraba la tienda.

Ejemplo completo: [main.cpp](02_POO/03_Constructores_y_Destructores/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Sesion {
    string usuario;

public:
    explicit Sesion(const string& nombre) : usuario(nombre) {
        cout << "Entra " << usuario << "\n";
    }
    ~Sesion() {
        cout << "Sale " << usuario << "\n";
    }
    const string& nombre() const {
        return usuario;
    }
};

int main() {
    {
        Sesion sesion("Ana");

    } // Aqui termina la vida de sesion.
    cout << "Sesion terminada\n";
}
```

### 4. Composición

Un objeto puede contener otro: la relación es «tiene un». El miembro se construye antes del cuerpo del constructor del objeto que lo contiene.

Analogía: Un automóvil tiene un motor; no es un tipo de motor.

Ejemplo completo: [main.cpp](02_POO/04_Composicion/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Motor {
    bool encendido = false;

public:
    void encender() {
        encendido = true;
    }
    bool estaEncendido() const {
        return encendido;
    }
};

class Auto {
    Motor motor;

public:
    void arrancar() {
        motor.encender();
    }
    bool enMarcha() const {
        return motor.estaEncendido();
    }
};

int main() {
    Auto autoRojo;

    autoRojo.arrancar();

    cout << "Motor encendido\n";
}
```

### 5. Herencia

Una clase derivada reutiliza una base cuando existe una relación «es un». La herencia pública conserva esa relación para el usuario de la clase. Prefiere composición cuando la relación sea «tiene un».

Analogía: Una bicicleta eléctrica sigue siendo una bicicleta y añade una batería.

Ejemplo completo: [main.cpp](02_POO/05_Herencia/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Bicicleta {
    int velocidad = 0;

public:
    void pedalear() {
        velocidad += 5;
    }
    int consultarVelocidad() const {
        return velocidad;
    }
};

class BicicletaElectrica : public Bicicleta {
    int bateria = 100;

public:
    bool asistir() {
        if (bateria < 10) {
            return false;
        }
        bateria -= 10;
        pedalear();
        return true;
    }
    int carga() const {
        return bateria;
    }
};

int main() {
    BicicletaElectrica bici;
    if (!(bici.asistir())) {
        return 1;
    }

    cout << "Velocidad: " << bici.consultarVelocidad() << "\n";
}
```

### 6. Polimorfismo y clases abstractas

Un método `virtual` permite elegir la implementación según el objeto real. `= 0` define una operación abstracta y `override` verifica que la redefiniste correctamente. Una base polimórfica necesita destructor virtual si se destruyen derivados mediante ella.

Analogía: El botón «hacer sonido» funciona con varios instrumentos; cada instrumento decide qué sonido producir.

Ejemplo completo: [main.cpp](02_POO/06_Polimorfismo/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Instrumento {
public:
    virtual ~Instrumento() = default;
    virtual string sonar() const = 0;
};

class Guitarra : public Instrumento {
public:
    string sonar() const override {
        return "Cuerdas";
    }
};
class Tambor : public Instrumento {
public:
    string sonar() const override {
        return "Percusion";
    }
};

void tocar(const Instrumento& instrumento) {
    cout << instrumento.sonar() << "\n";
}

int main() {
    Guitarra guitarra;
    Tambor tambor;
    const Instrumento& instrumento = guitarra;

    tocar(instrumento);
    tocar(tambor);
}
```

### 7. Memoria y punteros en POO

Relaciona propiedad con vida del objeto. El integrador administra un alumno con `unique_ptr` y lo consulta mediante un puntero que no es propietario.

**Memoria dinámica manual.** `new` construye un objeto dinámico y `delete` lo destruye. Debe existir exactamente un propietario responsable de liberarlo. Para arreglos creados con `new[]` corresponde `delete[]`. En código habitual usa objetos por valor, `vector` o punteros inteligentes.

Analogía: Alquilas un casillero: conservas la dirección y debes devolverlo una vez. Devolverlo dos veces o visitarlo después es un error.

**Propiedad con unique_ptr.** `unique_ptr` tiene un propietario y libera el objeto automáticamente. `make_unique` lo construye. `move` transfiere la propiedad; no copies un `unique_ptr`. Usa punteros crudos cuando solo observes un objeto y su vida esté garantizada.

Analogía: Una llave única administra el casillero. Cuando entregas la llave, el dueño anterior deja de tenerla.

Ejemplo completo: [main.cpp](02_POO/07_Memoria_y_Punteros/main.cpp).

```cpp
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Alumno {
    string nombre;

public:
    explicit Alumno(const string& nombreInicial) : nombre(nombreInicial) {
    }
    const string& consultarNombre() const {
        return nombre;
    }
};

int main() {
    auto propietario = make_unique<Alumno>("Ana");
    const Alumno* consulta = propietario.get();

    cout << consulta->consultarNombre() << "\n";
    propietario.reset();
    consulta = nullptr;
}
```

[Guía del tema y sus variantes](02_POO/07_Memoria_y_Punteros/README.md).

### 8. Const, headers y compilación de varios archivos

`Producto.h` declara la clase; `Producto.cpp` define sus métodos; `main.cpp` la utiliza. Las guardas `#ifndef` evitan incluir la misma declaración dos veces. Cada `.cpp` se compila y el enlazador reúne el resultado. Incluye el `.h`, nunca el `.cpp`.

Analogía: El header es la carta del restaurante: explica qué puedes pedir. El `.cpp` es la cocina y `main` hace el pedido.

`main.cpp` crea un `const Producto`: puedes consultar su nombre y precio, pero no modificarlo. Las consultas se declaran con `const` después de los paréntesis tanto en el `.h` como en el `.cpp`. Eso permite llamarlas desde un objeto constante. La consulta del nombre devuelve `const string&` para evitar una copia y proteger el texto original.

Así se distinguen tres usos: `const` en datos que no cambian, `const T&` en parámetros o resultados de solo lectura, y métodos `const` que consultan el estado del objeto. Un método que cambia el precio no debería ser const.

Ejemplo completo: [main.cpp](02_POO/08_Headers/main.cpp).

```cpp
#include "Producto.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const Producto cuaderno("Cuaderno", 1250);

    cout << cuaderno.consultarNombre() << ": " << cuaderno.consultarPrecio() << " centavos\n";
}
```

[Guía del tema y sus variantes](02_POO/08_Headers/README.md).

### 9. DAO: separar el acceso a datos

Estudia CRUD en memoria y después persistencia. El integrador combina ambas operaciones usando un flujo en memoria para comprobar el formato sin crear archivos. Los headers de este bloque contienen definiciones dentro de la clase, implícitamente `inline`. El DAO permite consultas lineales y limita la carga a 10 000 registros; una base de datos será otro paso si hace falta.

**DAO en memoria y CRUD.** DAO significa Data Access Object: es un patrón de acceso a datos, no un paradigma. `LibroDAO` concentra crear, consultar, actualizar y eliminar (CRUD). La aplicación usa esas operaciones sin manipular el contenedor. Por ahora `vector` es una colección que crece; lo estudiaremos en EDD.

Analogía: El bibliotecario (DAO) conoce dónde están los libros; tú le pides uno por su ficha sin revisar cada estante.

**Persistir un DAO en un archivo.** `guardar` serializa una instantánea y `cargar` la valida antes de reemplazar los datos en memoria. `quoted` conserva espacios y comillas. Cada instantánea comienza con su cantidad de libros. Este ejemplo agrega instantáneas al archivo y recupera la última completa.

Analogía: El bibliotecario toma una fotografía del catálogo al cerrar. Al abrir consulta la fotografía más reciente para recuperar el estado.

Ejemplo completo: [main.cpp](02_POO/09_DAO/main.cpp).

```cpp
#include "LibroDAO.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO original;
    if (!(original.crear({1, "Estructuras"}))) {
        return 1;
    }
    if (!(original.crear({2, "Objetos"}))) {
        return 1;
    }
    if (!(original.actualizar(2, "Objetos y \"clases\""))) {
        return 1;
    }
    if (!(original.eliminar(1))) {
        return 1;
    }
    stringstream archivo;
    if (!(original.guardar(archivo))) {
        return 1;
    }
    LibroDAO copia;
    if (!(copia.cargar(archivo))) {
        return 1;
    }
    assert(copia.todos().size() == 1);
    assert(copia.buscar(2)->titulo == "Objetos y \"clases\"");
    istringstream duplicados("2\n2 \"Uno\"\n2 \"Dos\"\n");
    if (copia.cargar(duplicados)) {
        return 1;
    }
    assert(copia.todos().size() == 1);
    cout << copia.buscar(2)->titulo << "\n";
}
```

[Guía del tema y sus variantes](02_POO/09_DAO/README.md).

### 10. Integrador: una biblioteca con objetos

Usa composición para encapsular un DAO y herencia con dos vistas para practicar polimorfismo. Reutiliza el header del tema anterior. `unique_ptr` administra la vista y el destructor virtual permite liberar su tipo concreto.

Analogía: La biblioteca tiene un bibliotecario y puede mostrar el catálogo en dos ventanillas: una detallada y otra resumida.

Ejemplo completo: [main.cpp](02_POO/10_Integrador/main.cpp).

```cpp
#include "../09_DAO/LibroDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace curso;

class Biblioteca {
    LibroDAO dao;

public:
    bool registrar(const Libro& libro) {
        return dao.crear(libro);
    }
    const LibroDAO& catalogo() const {
        return dao;
    }
};

class Vista {
public:
    virtual ~Vista() = default;
    virtual string mostrar(const LibroDAO& dao) const = 0;
};
class VistaDetalle : public Vista {
public:
    string mostrar(const LibroDAO& dao) const override {
        string texto;
        for (const auto& libro : dao.todos()) {
            texto += to_string(libro.id) + ": " + libro.titulo + "\n";
        }
        return texto;
    }
};
class VistaResumen : public Vista {
public:
    string mostrar(const LibroDAO& dao) const override {
        return "Libros: " + to_string(dao.todos().size()) + "\n";
    }
};

int main() {
    Biblioteca biblioteca;
    if (!(biblioteca.registrar({1, "Aprender C++"}))) {
        return 1;
    }
    if (biblioteca.registrar({1, "Duplicado"})) {
        return 1;
    }
    unique_ptr<Vista> vista = make_unique<VistaDetalle>();

    cout << vista->mostrar(biblioteca.catalogo());
    vista = make_unique<VistaResumen>();

    cout << vista->mostrar(biblioteca.catalogo());
}
```

## Estructuras de datos y algoritmos

Elige estructuras según sus operaciones y costos. EDD es un área de estudio que puedes implementar con programación estructurada y POO.

[Guía del bloque](03_EDD/README.md).

### 1. Complejidad: tiempo y espacio

Big O describe cómo crece el trabajo con el tamaño de la entrada, no los segundos exactos. Acceder por índice es O(1); recorrer n elementos es O(n); reducir el problema a la mitad repetidamente requiere O(log n) pasos. También cuenta la memoria adicional.

Analogía: Buscar un cajón por número es directo; revisar todas las secciones tarda más cuando el mueble crece; partir una guía ordenada por la mitad descarta muchas páginas a la vez.

Ejemplo completo: [main.cpp](03_EDD/01_Complejidad/main.cpp).

```cpp
#include <iostream>

using namespace std;

int pasosMitad(int n) {
    int pasos = 0;
    while (n > 1) {
        n /= 2;
        ++pasos;
    }
    return pasos;
}

int main() {
    cout << "Recorrido de 1024 elementos: 1024 visitas\n";
    cout << "Dividir 1024 hasta 1: " << pasosMitad(1024) << " pasos\n";
}
```

### 2. Vectores

Estudia tamaño, recorrido, modificación y objetos. El integrador organiza tareas, marca una y la elimina; quedan `Compilar` y `Practicar`.

**Crear y recorrer un vector.** `vector` es un arreglo contiguo cuyo tamaño puede cambiar. `size()` es la cantidad de elementos; `capacity()` es el espacio reservado. `push_back` cuesta O(1) amortizado, aunque una realocación individual cuesta O(n).

Analogía: Es un cajón extensible: al llenarse, puede mudarse a un cajón mayor. Sus secciones siguen numeradas desde cero.

**Insertar y eliminar en vectores.** `insert` y `erase` reciben iteradores. `begin()` apunta al primer elemento y `end()` representa el límite posterior al último, que no se desreferencia. Insertar o borrar en medio desplaza elementos: O(n). Una realocación invalida todos los punteros, referencias e iteradores; un borrado invalida desde la posición eliminada.

Analogía: Para abrir un hueco en medio del cajón debes mover las cosas de las secciones siguientes.

**Vectores de objetos.** Un vector puede guardar objetos del mismo tipo. Un `struct` tiene miembros públicos por defecto; en una `class` son privados por defecto. `const auto&` permite recorrer sin copiar ni modificar.

Analogía: El cajón ahora guarda fichas completas: cada ficha tiene un nombre y una nota.

Ejemplo completo: [main.cpp](03_EDD/02_Vectores/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tarea {
    string nombre;
    bool terminada;
};

int main() {
    vector<Tarea> tareas{{"Leer", false}, {"Practicar", false}};
    tareas.insert(tareas.begin() + 1, {"Compilar", false});
    tareas.at(0).terminada = true;
    tareas.erase(tareas.begin());
    for (const auto& tarea : tareas) {
        cout << tarea.nombre << "\n";
    }
}
```

[Guía del tema y sus variantes](03_EDD/02_Vectores/README.md).

### 3. Listas ligadas

Las tres implementaciones guardan enteros para concentrarnos en los enlaces y la propiedad de los nodos. Usa `new/delete` aquí para estudiar el mecanismo; los contenedores estándar ya resuelven su gestión en aplicaciones comunes. El integrador usa los tres headers y elimina el dato 20 de cada lista. Cambia los datos y compara los recorridos. Después prueba eliminar el inicio, el final y el único nodo.

**Lista simplemente ligada.** Cada nodo guarda un dato y la dirección del siguiente. El último apunta a `nullptr`. No hay acceso directo por índice: recorrer y buscar cuestan O(n). El header implementa inserción al final, eliminación de la primera coincidencia y liberación de todos los nodos.

Analogía: Una búsqueda del tesoro: cada tarjeta contiene un dato y la pista hacia la siguiente. La última dice «fin».

**Lista doblemente ligada.** Cada nodo conoce al anterior y al siguiente. Guardar inicio y fin permite agregar al final en O(1) y recorrer en ambos sentidos. Buscar un valor sigue siendo O(n); borrar un nodo ya localizado requiere ajustar ambos enlaces.

Analogía: Los vagones de un tren están enganchados por delante y por detrás; puedes caminar en ambos sentidos.

**Lista circular.** El último nodo apunta al primero. Debes detenerte al volver al inicio; esperar `nullptr` causaría un ciclo infinito. La inserción al final cuesta O(1); buscar y eliminar por valor cuestan O(n). Esta variante es simplemente ligada y circular.

Analogía: Una rueda de turnos: después de la última persona regresas a la primera.

Ejemplo completo: [main.cpp](03_EDD/03_Listas_Ligadas/01_Simplemente_Ligada/main.cpp).

```cpp
#include "ListaSimple.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple lista;
    if (!(lista.valores().empty() && !lista.eliminar(99))) {
        return 1;
    }
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    if (!(lista.eliminar(20))) {
        return 1;
    }

    for (int dato : lista.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }
}
```

[Guía del tema y sus variantes](03_EDD/03_Listas_Ligadas/README.md).

### 4. Pilas

Compara el mecanismo con vector y la interfaz de `stack`. El integrador verifica que ambos producen `3 2 1`.

**Una pila con vector.** Una pila sigue LIFO: el último que entra es el primero que sale. `push_back`, `back` y `pop_back` permiten implementarla; comprueba `empty` antes de consultar o sacar.

Analogía: Una pila de platos: colocas uno arriba y retiras el de arriba.

**El adaptador stack.** `stack` ofrece solo las operaciones de pila: `push`, `top`, `pop`, `size`, `empty`. `pop` elimina pero no devuelve el valor; consúltalo antes con `top`. El adaptador restringe las operaciones del contenedor subyacente.

Analogía: Una caja de platos con una sola abertura arriba: no puedes tomar el plato de en medio.

Ejemplo completo: [main.cpp](03_EDD/04_Pilas/02_Con_Stack/main.cpp).

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> historial;
    historial.push("Escribir");
    historial.push("Borrar");
    if (!historial.empty()) {

        cout << "Deshacer: " << historial.top() << "\n";
        historial.pop();
    }
}
```

[Guía del tema y sus variantes](03_EDD/04_Pilas/README.md).

### 5. Colas

Compara orden de llegada y orden de prioridad. El integrador produce `2 9 4` con FIFO y `9 4 2` con prioridad.

**Cola FIFO.** `queue` atiende en orden de llegada: first in, first out. Agrega con `push`, consulta con `front` y elimina con `pop`. Comprueba `empty` antes de consultar.

Analogía: La fila de las tortillas: se atiende primero a quien llegó primero.

**Cola de prioridad y heap.** `priority_queue` utiliza un heap (montículo). Por defecto coloca el mayor arriba; con `greater<int>` coloca el menor. Consultar `top` cuesta O(1); insertar y retirar, O(log n). No conserva el orden de llegada entre prioridades iguales.

Analogía: En urgencias se atiende por prioridad; la gravedad decide el siguiente turno.

Ejemplo completo: [main.cpp](03_EDD/05_Colas/01_Con_Queue/main.cpp).

```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> fila;
    fila.push("Ana");
    fila.push("Luis");

    while (!fila.empty()) {
        cout << "Atender: " << fila.front() << "\n";
        fila.pop();
    }
}
```

[Guía del tema y sus variantes](03_EDD/05_Colas/README.md).

### 6. Árboles

Distingue árbol binario de ABB y después estudia sus recorridos. El integrador inserta, busca, recorre y elimina. Los ejemplos recursivos usan árboles pequeños; balanceo y recorridos iterativos son ampliaciones para grandes profundidades.

**Árbol binario: raíces, hijos y hojas.** Un árbol conecta nodos sin ciclos. La raíz no tiene padre; una hoja no tiene hijos. Un árbol binario admite como máximo dos hijos por nodo. No todo árbol binario ordena sus valores.

Analogía: Un organigrama empieza en un responsable y se divide en ramas. En este ejemplo cada responsable tiene como máximo dos subordinados.

**Árbol binario de búsqueda (ABB).** En este ABB los menores van a la izquierda y los mayores a la derecha; rechazamos duplicados. Inserción, consulta y eliminación cuestan O(h), donde h es la altura. Al borrar un nodo con dos hijos, lo sustituimos por el menor del subárbol derecho. Un ABB sin balancear puede degenerar en una cadena.

Analogía: Una guía de números: cada nodo indica si seguir hacia los menores o hacia los mayores.

**Recorridos de un árbol.** Preorden visita raíz, izquierda, derecha. Inorden visita izquierda, raíz, derecha. Postorden visita izquierda, derecha, raíz. En un ABB, inorden produce valores ordenados. Los recorridos visitan todos los nodos: O(n), con O(h) de pila recursiva más el vector de salida.

Analogía: Recorres una casa: puedes registrar el cuarto antes de visitar sus anexos, entre ambos anexos o al terminar de visitarlos.

Ejemplo completo: [main.cpp](03_EDD/06_Arboles/01_Arbol_Binario/main.cpp).

```cpp
#include <iostream>
#include <memory>

using namespace std;

struct Nodo {
    int dato;
    unique_ptr<Nodo> izquierdo;
    unique_ptr<Nodo> derecho;
    explicit Nodo(int valor) : dato(valor) {
    }
};

int contar(const Nodo* nodo) {
    if (!nodo) {
        return 0;
    }
    return 1 + contar(nodo->izquierdo.get()) + contar(nodo->derecho.get());
}

int main() {
    auto raiz = make_unique<Nodo>(10);
    raiz->izquierdo = make_unique<Nodo>(20); // Binario, sin regla de busqueda.
    raiz->derecho = make_unique<Nodo>(5);

    cout << "Nodos: " << contar(raiz.get()) << "\n";
}
```

[Guía del tema y sus variantes](03_EDD/06_Arboles/README.md).

### 7. Tablas hash con unordered_map

`unordered_map` asocia claves únicas con valores mediante una función hash. Buscar e insertar cuestan O(1) en promedio y O(n) en el peor caso. La biblioteca administra las colisiones; el orden de recorrido no está garantizado. `operator[]` puede insertar: usa `find` para solo consultar.

Analogía: Un recepcionista transforma una clave en el número de un casillero. Si varias claves coinciden, debe distinguir sus fichas.

Ejemplo completo: [main.cpp](03_EDD/07_Tablas_Hash/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> alumnos;
    alumnos.emplace(101, "Ana");
    alumnos.emplace(102, "Luis");
    auto encontrado = alumnos.find(101);
    cout << encontrado->second << "\n";
    if (!(alumnos.erase(102) == 1 && alumnos.size() == 1)) {
        return 1;
    }
}
```

### 8. Grafos

Estudia representación, recorridos y costos mínimos. BFS y DFS no usan los pesos; Dijkstra sí. El integrador compara ambos recorridos y calcula costo mínimo 4 del vértice 0 al 3. Los headers contienen funciones `inline` para poder reutilizarlas sin definiciones duplicadas al enlazar.

**Representar grafos.** Un grafo contiene vértices y aristas. La lista de adyacencia guarda los vecinos de cada vértice y ocupa O(V + E); una matriz de adyacencia ocupa O(V²). `Grafo` representa aristas dirigidas con pesos no negativos. Para una conexión no dirigida agrega ambas direcciones.

Analogía: Las ciudades son vértices; las carreteras son aristas; el costo de recorrer una carretera es su peso.

**BFS: búsqueda en anchura.** BFS usa una cola y visita por niveles. Marca cada vértice al encolarlo para no repetirlo cuando hay ciclos. Recorre solo los vértices alcanzables desde el inicio. En grafos sin pesos, los niveles describen distancias mínimas en número de aristas. Tiempo O(V + E), memoria auxiliar O(V).

Analogía: Exploras una ciudad por anillos: primero los vecinos cercanos, después sus vecinos.

**DFS: búsqueda en profundidad.** DFS sigue una rama hasta que no puede avanzar y luego regresa. Puede usar recursión o una pila explícita. Los visitados evitan ciclos. Tiempo O(V + E), memoria auxiliar O(V). El orden depende del orden de los vecinos.

Analogía: Exploras un laberinto siguiendo un pasillo hasta el fondo y retrocedes para probar los demás.

**Dijkstra: caminos de menor costo.** Dijkstra obtiene distancias mínimas con pesos no negativos. Usa una cola de prioridad de menor costo, mejora distancias y descarta entradas obsoletas. `INFINITO` indica un vértice inalcanzable. Esta versión permite entradas repetidas en la cola: tiempo O((V + E) log(E + 2)) y memoria O(V + E). No devuelve las rutas, solo sus costos.

Analogía: Un repartidor compara el costo total de las rutas y siempre considera primero la alternativa más barata disponible.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/01_Representacion/main.cpp).

```cpp
#include "../Grafo.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(3);
    mapa.conectar(0, 1, 5);
    mapa.conectar(1, 0, 5); // Carretera de ida y vuelta.
    mapa.conectar(1, 2, 2); // Solo ida.

    for (const auto& arista : mapa.vecinos(1)) {
        cout << "1 -> " << arista.destino << " costo " << arista.peso << "\n";
    }
}
```

[Guía del tema y sus variantes](03_EDD/08_Grafos/README.md).

### 9. Algoritmos de ordenamiento

Estudia cada algoritmo con la misma entrada y compara trabajo, memoria y estabilidad. Estable significa conservar el orden original de elementos con la misma clave. El integrador verifica cinco algoritmos contra `sort`, incluyendo vector vacío, repetidos, negativos y datos ya ordenados. Los punteros a funciones permiten repetir la misma comprobación.

**Burbuja.** Compara vecinos y los intercambia si están invertidos. Cada pasada coloca el mayor restante al final. Tiempo O(n²) en promedio y peor caso; O(n) si ya está ordenado gracias al indicador de cambios. Memoria adicional O(1). Es estable. Lee su función en `../Ordenamientos.h`.

Analogía: Las burbujas grandes suben al extremo; cada pasada lleva el mayor número al final.

**Selección.** Busca el menor de la zona pendiente y lo intercambia con su primera posición. Tiempo O(n²), incluso si ya estaba ordenado; memoria adicional O(1). No es estable en esta implementación. Lee su función en `../Ordenamientos.h`.

Analogía: De un montón de cartas tomas siempre la menor y la colocas en la siguiente posición libre.

**Inserción.** Mantiene una zona izquierda ordenada e inserta cada dato nuevo desplazando los mayores. Tiempo O(n²) en promedio y peor caso, O(n) en datos ya ordenados; memoria adicional O(1). Es estable. Lee su función en `../Ordenamientos.h`.

Analogía: Ordenas una mano de cartas colocando cada carta nueva en su lugar entre las anteriores.

**Merge sort.** Divide por mitades, ordena cada mitad y las mezcla. Tiempo O(n log n); usa O(n) de memoria auxiliar y O(log n) de llamadas. Es estable porque, ante empates, toma primero el elemento de la izquierda. Lee su función en `../Ordenamientos.h`.

Analogía: Divides hojas entre dos ayudantes y luego reúnes sus montones ordenados tomando la menor hoja disponible.

**Quick sort.** Elige un pivote, coloca los menores a un lado y ordena las particiones. Suele costar O(n log n), pero esta elección de pivote llega a O(n²) con entradas ordenadas o iguales. La pila recursiva puede crecer hasta O(n). No es estable. Lee su función en `../Ordenamientos.h`.

Analogía: Un pivote divide una fila: los menores pasan a la izquierda y los demás a la derecha; repites en cada grupo.

**Ordenar con la biblioteca estándar.** `sort` ofrece O(n log n) comparaciones en el peor caso y no garantiza estabilidad. `stable_sort` conserva el orden de elementos equivalentes. El comparador debe expresar un orden estricto: usa `<`, no `<=`. Aprende los algoritmos manuales y usa la biblioteca para tareas habituales.

Analogía: Encargas ordenar el cajón a una herramienta ya probada, indicándole cómo comparar sus objetos.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/06_STD_Sort/main.cpp).

```cpp
#include <algorithm>
#include <iostream>
#include <string>
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
    stable_sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.nota < b.nota;
    });

    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
```

[Guía del tema y sus variantes](03_EDD/09_Ordenamiento/README.md).

### 10. Búsqueda

Busca primero sin orden y después con orden. El integrador compara resultados de ambas búsquedas sobre datos ordenados y muestra cómo cambia el índice original: el 8 pasa de 0 a 4.

**Búsqueda lineal.** Revisa desde el inicio hasta encontrar el valor. No necesita orden previo. Tiempo O(n); espacio auxiliar O(1). `optional` contiene una posición o `nullopt` si no existe. Comprueba que tiene valor antes de usar `*resultado`. La posición 0 también es un resultado válido.

Analogía: Buscas una llave revisando cada compartimento del cajón.

**Búsqueda binaria.** Requiere un vector ordenado de menor a mayor. Cada comparación descarta la mitad del rango; tiempo O(log n), espacio auxiliar O(1). Ordenar primero tiene su propio costo: no es gratis. Esta versión devuelve la primera coincidencia.

Analogía: Abres una guía ordenada por la mitad y decides qué mitad conserva el número que buscas.

Ejemplo completo: [main.cpp](03_EDD/10_Busqueda/02_Binaria/main.cpp).

```cpp
#include "../Busquedas.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{1, 3, 3, 5, 8};
    auto posicion = binaria(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}
```

[Guía del tema y sus variantes](03_EDD/10_Busqueda/README.md).

### 11. Const y headers en EDD

Una consulta de una estructura puede recibir `const vector<int>&`: usa sus elementos sin copiar ni cambiar el vector. El vector y el resultado del ejemplo son `const`. El header declara la operación y una constante `inline constexpr`; el `.cpp` define el algoritmo con `count_if` y `main.cpp` lo usa. La consulta cuesta O(n) y requiere O(1) de memoria auxiliar.

Los ejemplos de listas, árboles y grafos ya tienen headers con clases y operaciones. Aquí se muestra la separación entre declaración e implementación para una consulta. Comparar esta firma con un ordenamiento que recibe `vector<int>&` ayuda a distinguir lectura y modificación.

Analogía: Una consulta es revisar el cajón a través de una vitrina: cuentas los objetos sin cambiar su posición. Ordenar el cajón sí exige abrirlo y moverlos.

Ejemplo completo: [main.cpp](03_EDD/11_Const_y_Headers/main.cpp).

```cpp
#include "Consultas.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{9, 4, 10, 6};
    const size_t cantidad = contarMayores(datos, LIMITE_DE_EJEMPLO);
    cout << "Valores mayores a " << LIMITE_DE_EJEMPLO << ": " << cantidad << "\n";
    for (const int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
```

[Guía del tema y sus variantes](03_EDD/11_Const_y_Headers/README.md).

### 12. Integrador: procesar tareas y consultar rutas

Combina vector, lista, pila, cola, cola de prioridad, ABB, tabla hash, grafo, ordenamiento y búsqueda. Reutiliza los headers de EDD. La cola define el orden de trabajo; la lista conserva el historial y la pila permite consultar qué se desharía primero.

Analogía: Un taller recibe órdenes, las atiende, conserva un historial, organiza prioridades y consulta un mapa para las entregas.

Ejemplo completo: [main.cpp](03_EDD/12_Integrador/main.cpp).

```cpp
#include "../03_Listas_Ligadas/01_Simplemente_Ligada/ListaSimple.h"
#include "../06_Arboles/Arbol.h"
#include "../08_Grafos/Grafo.h"
#include "../09_Ordenamiento/Ordenamientos.h"
#include "../10_Busqueda/Busquedas.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> nombres{{1, "Leer"}, {2, "Compilar"}, {3, "Practicar"}};
    queue<int> pendientes;
    priority_queue<int> urgencias;
    for (int id : ids) {
        pendientes.push(id);
        urgencias.push(id);
    }
    ListaSimple historial;
    stack<int> deshacer;
    Arbol indice;
    while (!pendientes.empty()) {
        int id = pendientes.front();
        pendientes.pop();
        historial.agregar(id);
        deshacer.push(id);
        indice.insertar(id);
        cout << "Procesar: " << nombres.at(id) << "\n";
    }
    assert(historial.valores() == ids && deshacer.top() == 2);
    assert(urgencias.top() == 3 && indice.contiene(2));
    mergeSort(ids);
    assert(ids == indice.valores());
    assert(binaria(ids, 2).value() == 1);

    Grafo rutas(3);
    rutas.conectar(0, 1, 4);
    rutas.conectar(0, 2, 1);
    rutas.conectar(2, 1, 1);
    assert(bfs(rutas, 0).size() == 3 && dfs(rutas, 0).size() == 3);
    assert(dijkstra(rutas, 0).at(1) == 2);
    cout << "Ultima tarea (deshacer): " << nombres.at(deshacer.top()) << "\n";
    cout << "Costo minimo de entrega 0 -> 1: " << dijkstra(rutas, 0).at(1) << "\n";
}
```

### 13. Combinar conceptos de forma gradual

Aprender cada herramienta por separado ayuda a reconocerla; combinarla exige decidir qué problema resuelve. Imagina un inventario: primero guardamos productos, después agrupamos existencias, luego prestamos direcciones para seleccionar productos y al final construimos clases que administran nodos. Cada paso incorpora una necesidad y conserva lo aprendido.

| Paso | Programa | Decisión que aprendemos |
| --- | --- | --- |
| 1 | [Arreglo de clases](03_EDD/13_Combinacion_de_Conceptos/01_Arreglo_de_Clases/main.cpp) | Guardar objetos completos |
| 2 | [Arreglo de structs con clases](03_EDD/13_Combinacion_de_Conceptos/02_Arreglo_de_Structs_con_Clases/main.cpp) | Reunir un objeto y sus existencias |
| 3 | [Arreglo de punteros](03_EDD/13_Combinacion_de_Conceptos/03_Arreglo_de_Punteros/main.cpp) | Separar una tarjeta de su destino |
| 4 | [Vector de punteros](03_EDD/13_Combinacion_de_Conceptos/04_Vector_de_Punteros/main.cpp) | Crear una vista que crece sin copiar productos |
| 5 | [Matriz de punteros](03_EDD/13_Combinacion_de_Conceptos/05_Matriz_de_Punteros/main.cpp) | Organizar vistas por filas y casillas |
| 6 | [Arreglo de nodos enlazados](03_EDD/13_Combinacion_de_Conceptos/06_Arreglo_de_Nodos/main.cpp) | Separar ubicación física y orden lógico |
| 7 | [Vector de unique_ptr](03_EDD/13_Combinacion_de_Conceptos/07_Vector_de_Unique_Ptr/main.cpp) | Dar un propietario a cada objeto dinámico |
| 8 | [Clase con nodos struct](03_EDD/13_Combinacion_de_Conceptos/08_Clase_con_Nodos/main.cpp) | Encapsular una cadena y sus operaciones |
| 9 | [Vector de clases con nodos](03_EDD/13_Combinacion_de_Conceptos/09_Vector_de_Clases_con_Nodos/main.cpp) | Reunir listas y distinguir qué se mueve |

La [guía del tema](03_EDD/13_Combinacion_de_Conceptos/README.md) explica por qué cambia la representación en cada paso. Cada programa tiene sus operaciones comentadas; [Estante.h](03_EDD/13_Combinacion_de_Conceptos/Estante.h) reúne la clase usada por los dos últimos pasos y el integrador. Reutilizamos `Producto.h` y `Producto.cpp` de POO.

Este integrador guarda un `vector<Estante>`; cada estante posee nodos `struct`, y cada nodo contiene un `Producto`. Un `vector<const Nodo*>` presta una vista que ordenamos por precio; un arreglo de arreglos de punteros muestra casillas que pueden repetir destinos. El total se calcula desde los propietarios para evitar contar esas repeticiones como productos extra.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/main.cpp).

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include "Estante.h"

using namespace std;
using namespace curso;

// Referencia a una tarjeta: cambiamos la selección del llamador. El destino es de lectura.
void seleccionar(const Estante::Nodo*& seleccion, const Estante::Nodo* nuevoDestino) {
    seleccion = nuevoDestino;
}

long long valorTotal(const vector<Estante>& estantes) {
    long long valorTotal = 0;
    for (const Estante& estante : estantes) {
        const long long subtotal = estante.valorTotal();
        if (valorTotal > numeric_limits<long long>::max() - subtotal) {
            throw overflow_error("El inventario supera el rango de long long");
        }
        valorTotal += subtotal;
    }
    return valorTotal;
}

int main() {
    // Primero construimos los propietarios: vector -> estantes -> nodos -> productos.
    vector<Estante> estantes;
    estantes.emplace_back("Papeleria");
    estantes.at(0).agregar(Producto("Cuaderno", 300));
    estantes.at(0).agregar(Producto("Lapiz", 100));
    estantes.emplace_back("Libros");
    estantes.at(1).agregar(Producto("Libro", 500));

    // Después prestamos direcciones. Las listas contienen objetos; la vista solo contiene tarjetas.
    vector<const Estante::Nodo*> vista;
    for (const Estante& estante : estantes) {
        const Estante::Nodo* actual = estante.primero();
        while (actual != nullptr) {
            vista.push_back(actual);
            actual = actual->siguienteNodo();
        }
    }

    // Ordenar la vista mueve tarjetas, sin cambiar los enlaces ni mover los productos.
    sort(vista.begin(), vista.end(), [](const Estante::Nodo* izquierdo, const Estante::Nodo* derecho) {
        return izquierdo->consultarProducto().consultarPrecio() < derecho->consultarProducto().consultarPrecio();
    });
    for (const Estante::Nodo* actual : vista) {
        cout << actual->consultarProducto().consultarNombre() << ": "
             << actual->consultarProducto().consultarPrecio() << "\n";
    }

    const Estante::Nodo* seleccion = nullptr;
    seleccionar(seleccion, vista.at(0));
    // La matriz muestra dos productos únicos en tres casillas: seleccion aparece dos veces.
    const array<array<const Estante::Nodo*, 2>, 2> casillas{
        array<const Estante::Nodo*, 2>{seleccion, nullptr},
        array<const Estante::Nodo*, 2>{vista.at(1), seleccion}
    };
    size_t ocupadas = 0;
    for (const auto& fila : casillas) {
        for (const Estante::Nodo* actual : fila) {
            if (actual != nullptr) {
                ++ocupadas;
            }
        }
    }

    // Comprobación del integrador: el inventario y sus enlaces conservaron sus datos y orden.
    const long long antes = valorTotal(estantes);
    if (vista.size() != 3 || antes != 900 || ocupadas != 3 ||
        seleccion->consultarProducto().consultarPrecio() != 100 ||
        estantes.at(0).primero()->consultarProducto().consultarPrecio() != 100 ||
        estantes.at(0).primero()->siguienteNodo()->consultarProducto().consultarPrecio() != 300) {
        cerr << "El integrador produjo un resultado inesperado\n";
        return 1;
    }
    cout << "Inventario en centavos: " << antes << "\n";
    cout << "Casillas ocupadas (pueden repetir producto): " << ocupadas << "\n";

    // Retiramos la selección y la vista. No borran nodos porque no son propietarios.
    seleccion = nullptr;
    vista.clear();
    // Al salir, la matriz se destruye antes que los estantes; ningún observador sobrevive a sus nodos.
}
```

Los productos suman 900 centavos. La vista se ordena como lápiz, cuaderno y libro; los enlaces del inventario conservan su orden. Antes de diseñar otra combinación, dibuja quién contiene el dato, quién es su propietario y quién solo tiene una dirección. Luego decide si cada función recibe una copia, una referencia, una vista de lectura o una referencia a un puntero.

## Cómo se conectan las tres áreas

Primero aprendes a leer datos, decidir y dividir el trabajo en funciones. POO agrupa datos y operaciones en objetos y controla quién puede modificarlos. EDD permite elegir cómo almacenar esos objetos y qué algoritmo usar para consultarlos. DAO separa el acceso a datos de las reglas de una aplicación; no es un paradigma.

Un arreglo es un cajón con secciones fijas; un vector puede crecer. Una clase puede representar cada ficha guardada en ese cajón. Un DAO puede administrar esas fichas y un grafo modelar las rutas que relacionan sus ubicaciones. Los integradores de cada bloque practican estas conexiones.

## Proyecto final

La [cuarta carpeta](04_Proyecto_Integrador/README.md) conserva la estructura para aplicar POO, EDD, DAO y headers en una aplicación. Su desarrollo queda para después.

La [versión inglesa](../English/README.md) sigue el mismo orden y contiene los mismos ejemplos traducidos.
