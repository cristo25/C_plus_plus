# Aprende C++ paso a paso

Vamos a empezar con variables, decisiones y ciclos. Después construiremos objetos y aprenderemos a unir los datos con arreglos, listas, árboles y grafos. Terminaremos con una aplicación de biblioteca y rutas. En cada paso vamos a relacionar la explicación con nombres y operaciones del programa.

## Orden de estudio

1. [Programación estructurada](#programación-estructurada).
2. [Programación orientada a objetos](#programación-orientada-a-objetos).
3. [Estructuras de datos y algoritmos](#estructuras-de-datos-y-algoritmos).
4. [Proyecto integrador](04_Proyecto_Integrador/README.md).

Tenemos 84 programas, incluido el proyecto final. Dentro de un tema seguimos las subcarpetas numeradas y después el integrador que está junto a ellas. Primero leemos los comentarios, predecimos qué ocurrirá y ejecutamos el ejemplo. Luego resolvemos su práctica, que también aparece en el `main.cpp` de cada lección. La práctica del proyecto final está en su propia guía.

## Compilar y ejecutar

Para convertir el código en un programa usamos un compilador de C++17, como g++. Abrimos Git Bash o PowerShell en la carpeta del ejemplo y ejecutamos:

```bash
g++ -std=c++17 main.cpp -o programa.exe
./programa.exe
```

Con `-std=c++17` elegimos la versión de C++ y con `-o` ponemos nombre al programa creado. Compilamos un `main.cpp` a la vez, porque cada ejemplo empieza en su propio `main`.

Cuando repartimos el trabajo entre archivos, compilamos juntos sus `.cpp`. Por ejemplo, en el tema de headers de POO:

```bash
g++ -std=c++17 main.cpp Producto.cpp -o programa.exe
./programa.exe
```

Incluimos el `.h` para conocer las funciones disponibles; agregamos los `.cpp` al comando para incluir sus pasos. Aquí dejamos los comandos de compilación para no repetirlos en cada programa. En Linux o macOS podemos usar `programa` sin `.exe`.

## Bibliotecas y símbolos, al aparecer

Una biblioteca reúne herramientas ya disponibles en C++. Con `#include` indicamos cuáles necesitamos. Empezamos con `<iostream>` para la pantalla y el teclado; agregamos `<string>` al trabajar con texto, `<fstream>` para archivos y `<vector>` para colecciones que crecen. Los arreglos de tamaño fijo se escriben con corchetes y no necesitan otra biblioteca. Junto a cada include adicional explicamos para qué lo usamos.

Con `using namespace std;` podemos escribir `cout`, `string` y `vector` con esos nombres cortos. En algunos headers agrupamos nuestras funciones dentro de `namespace curso`, como una carpeta de nombres para no confundirlos con otros. Con `using namespace curso;` podemos usar esos nombres desde el ejemplo.

En la [guía de buenas prácticas](BUENAS_PRACTICAS.md) reunimos consejos de todo el curso. Podemos leer la parte de cada tema cuando lleguemos a él.

## Programación estructurada

### 01.01. Tu primer programa

Vamos a empezar mostrando un mensaje. Podemos imaginar el programa como una receta: dentro de main escribimos los pasos y con cout enviamos texto a la pantalla. Ponemos el texto entre comillas; \n indica que la siguiente salida empieza en otra línea. Con return 0 indicamos que el programa terminó sin problemas. Al compilar, convertimos este archivo de texto en un programa que la computadora puede ejecutar.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/01_Hola_Mundo/main.cpp).

```cpp
#include <iostream>

// Con esta línea podemos escribir cout directamente.
using namespace std;

// Aquí empiezan las instrucciones del programa.
int main() {
    cout << "Hola, C++!\n";
    return 0;
}
```

**Práctica.** Realiza un programa que muestre una tarjeta de presentación.

- Mostrar un nombre y una carrera en líneas separadas.
- Agregar un mensaje de bienvenida.
- Terminar sin solicitar datos todavía.

### 01.02. Variables, tipos y operadores

Vamos a guardar datos en variables. Podemos pensar en cada variable como una caja con nombre: int guarda enteros, double y float guardan números con decimales, char guarda un carácter, bool guarda verdadero o falso y string guarda texto. En cantidad guardamos cuántos cuadernos hay; multiplicamos ese número por precio para obtener total. Con const protegemos un dato que no debe cambiar. Al dividir dos enteros descartamos la parte decimal: 5 / 2 da 2, mientras que 5.0 / 2 da 2.5.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/02_Variables_y_Tipos/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    // const protege los datos que no cambian; cantidad sigue siendo una variable modificable.
    const string producto = "Cuaderno";
    int cantidad = 3;
    const double precio = 12.5;
    const char categoria = 'A';
    const bool disponible = cantidad > 0;
    const double total = cantidad * precio;

    cout << producto << ": " << total << "\n";
    cout << categoria << " disponible: " << boolalpha << disponible << "\n";
    // Dos enteros producen división entera: 5 / 2 da 2. Un operando double conserva la fracción.
    cout << "Division entera: " << 5 / 2 << "\n";
    cout << "Division decimal: " << 5.0 / 2 << "\n";
}
```

**Práctica.** Realiza un programa que calcule el importe de una compra.

- Guardar nombre, cantidad y precio de un producto.
- Calcular y mostrar el total con decimales.
- Usar const para un precio que no cambiará durante el programa.

### 01.03. Leer y mostrar datos

Vamos a pedir un nombre, una ciudad y una edad. Con `cout` mostramos cada pregunta y con `getline` guardamos todo lo escrito hasta Enter, incluidos los espacios. Con `cin >> edad` intentamos leer un número entero. Si el nombre o la ciudad están vacíos, o si la edad no está entre 0 y 130, mostramos un aviso. `cin.fail()` nos dice si no se pudo leer un número. `empty()` solo comprueba que no haya ningún carácter; un texto formado por espacios todavía cuenta como texto.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/03_Entrada_y_Salida/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    string nombreCompleto;
    string ciudad;
    int edad = 0;

    cout << "Ingresa tu nombre completo: ";
    getline(cin, nombreCompleto);
    cout << "Ingresa tu ciudad: ";
    getline(cin, ciudad);
    cout << "Ingresa tu edad: ";
    cin >> edad;

    if (nombreCompleto.empty() || ciudad.empty()) {
        cerr << "Error: El nombre y la ciudad no pueden estar vacios.\n";
        return 1;
    }
    if (cin.fail() || edad < 0 || edad > 130) {
        cerr << "Error: La edad no es valida.\n";
        return 1;
    }
    cout << "\n--- FICHA DE REGISTRO ---\n";
    cout << "Nombre : " << nombreCompleto << "\n";
    cout << "Ciudad : " << ciudad << "\n";
    cout << "Edad   : " << edad << " anios\n";
    return 0;
}
```

**Práctica.** Realiza un programa que registre a una persona.

- Pedir nombre completo, ciudad y edad.
- Aceptar espacios en el nombre y la ciudad.
- Mostrar un aviso si falta el nombre o la edad no es válida.
- Mostrar una ficha con los datos cuando sean correctos.

### 01.04.01. Decidir con if y else

Vamos a decidir qué instrucciones ejecutar. Con if hacemos una pregunta, como si una persona tiene al menos 18 años. Si la respuesta es true, es decir, verdadera, entramos en sus llaves; con else atendemos el caso contrario. Podemos unir preguntas: && significa que ambas deben cumplirse, || que basta una y ! invierte una respuesta. Podemos imaginar dos puertas: la condición decide por cuál seguimos.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/04_Condicionales/01_If_Else/main.cpp).

**Práctica.** Realiza un programa que decida el acceso a un evento.

- Guardar una edad y si hay un acompañante adulto.
- Permitir el acceso a mayores de edad o menores acompañados.
- Mostrar el motivo de la decisión.
- Probar edades de 17 y 18 años.

### 01.04.02. Elegir con switch

Vamos a elegir una bebida mediante un número. Con switch comparamos ese número con cada case, como al escoger una opción de un menú. Con break salimos del switch después de atender la opción; con default respondemos cuando el número no coincide con ninguna. Nos sirve cuando tenemos opciones concretas, por ejemplo 1, 2 y 3. En este ejemplo devolvemos directamente la bebida con return: salimos de la función y no necesitamos break en esos casos.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/04_Condicionales/02_Switch/main.cpp).

**Práctica.** Realiza un programa con un menú de tres bebidas.

- Asignar un número a cada bebida.
- Mostrar el nombre y precio de la opción elegida.
- Informar cuando la opción no exista.
- Usar break para terminar cada caso.

### 01.04. Condicionales

Vamos a combinar las dos formas de decidir. Primero elegimos un precio con switch; después usamos if para aplicar un descuento a estudiantes. En precio recibimos la opción y si hay descuento. Si la opción no existe, devolvemos -1 como señal acordada de error. La idea es separar dos preguntas: qué se compra y qué descuento corresponde.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/04_Condicionales/main.cpp).

```cpp
#include <iostream>

using namespace std;

int precio(int opcion, bool estudiante) {
    int base = 0;
    // switch elige un precio por opción; break impide pasar al siguiente caso.
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
    // Después de elegir el precio, aplicamos el descuento solo si se cumple la condición.
    if (estudiante) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Bebida 2 con descuento: " << precio(2, true) << "\n";
}
```

**Práctica.** Realiza un programa integrador para cobrar una entrada al cine.

- Elegir entre tres tipos de entrada con switch.
- Aplicar un descuento con if cuando corresponda.
- Rechazar opciones que no existan.
- Mostrar el precio inicial, descuento y total.

### 01.05.01. Repetir con for

Vamos a repetir una tarea con for. Entre sus paréntesis indicamos dónde empieza el contador, cuándo seguimos y cómo cambia después de cada vuelta. Podemos imaginar cinco casilleros numerados: revisamos uno, avanzamos y repetimos hasta el último. ++ aumenta el contador en uno; las instrucciones entre llaves se ejecutan en cada vuelta.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/05_Ciclos/01_For/main.cpp).

**Práctica.** Realiza un programa que muestre la tabla del 7.

- Usar un contador desde 1 hasta 10.
- Calcular cada multiplicación dentro del for.
- Mostrar cada operación y su resultado en una línea.

### 01.05.02. Repetir con while

Vamos a repetir mientras se cumpla una condición. Con while revisamos la condición antes de entrar: si ya es falsa, no hacemos ninguna vuelta. Podemos imaginar una alcancía a la que agregamos dinero mientras no alcanzamos la meta. Dentro del ciclo cambiamos el ahorro; si nunca cambiamos lo que revisamos, podríamos repetir para siempre.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/05_Ciclos/02_While/main.cpp).

**Práctica.** Realiza un programa que simule un ahorro semanal.

- Comenzar con un ahorro de 0.
- Agregar 25 por semana hasta alcanzar al menos 110.
- Contar las semanas y mostrar el ahorro después de cada una.
- Mostrar por qué el resultado final puede superar la meta.

### 01.05.03. Repetir con do while

Vamos a hacer al menos un intento antes de preguntar si seguimos. En do while primero ejecutamos lo que está entre llaves y después comprobamos la condición. Podemos imaginar que probamos una llave y solo entonces decidimos si hace falta otro intento. Aunque la condición resulte falsa desde la primera revisión, ya hicimos una vuelta.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/05_Ciclos/03_Do_While/main.cpp).

**Práctica.** Realiza un programa que simule hasta tres intentos.

- Mostrar el mensaje del intento dentro de do.
- Aumentar el contador en cada vuelta.
- Detenerse al completar tres intentos.
- Probar qué ocurre si el contador empieza en 3.

### 01.05. Ciclos

Vamos a usar los tres ciclos en una misma tarea. Con for reunimos cantidades de varios días; con while retiramos grupos de diez hasta terminar; con do while mostramos al menos un aviso. Podemos pensar en un negocio: primero recibimos pedidos, después los entregamos y al final avisamos. Elegimos cada ciclo según cuándo necesitamos revisar su condición.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/05_Ciclos/main.cpp).

```cpp
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
```

**Práctica.** Realiza un programa integrador que organice entregas.

- Sumar pedidos de tres días con for.
- Atender pedidos de uno en uno con while.
- Mostrar al menos un aviso final con do while.
- Contar y mostrar cuántos pedidos se atendieron.

### 01.06.01. Funciones: parámetros y retorno

Vamos a separar un cálculo en una función. Podemos imaginar una máquina pequeña: recibe ingredientes, trabaja y devuelve un resultado. A los datos de entrada los llamamos parámetros; con return entregamos el resultado. Cuando recibimos un int por valor, trabajamos con una copia: cambiarla dentro de la función no cambia la variable que enviamos.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/06_Funciones/01_Parametros_y_Retorno/main.cpp).

**Práctica.** Realiza un programa que convierta minutos a segundos.

- Crear una función que reciba los minutos.
- Devolver el resultado con return.
- Llamar a la función con tres valores diferentes.
- Mostrar los resultados desde main.

### 01.06.02. Valor, referencia y referencia const

Vamos a comparar una copia con una referencia. Si una variable es una caja, pasarla por valor entrega otra caja con el mismo contenido. Con int& ponemos otra etiqueta a la caja original: si cambiamos el dato mediante esa etiqueta, cambiamos el original. Una referencia queda ligada a la misma caja desde que nace; asignarle otro valor cambia el contenido, no la caja a la que se refiere. Con const int& podemos leer mediante la etiqueta, pero no escribir. En todos los casos necesitamos que la caja siga existiendo mientras la usamos.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/06_Funciones/02_Referencias/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
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

**Práctica.** Realiza un programa que compare tres formas de recibir un saldo.

- Crear una función que reciba int y modifique solo su copia.
- Crear otra que reciba int& y cambie el saldo original.
- Crear una consulta con const int&.
- Mostrar el saldo antes y después de cada llamada.

### 01.06. Funciones

Vamos a combinar funciones que calculan con funciones que modifican. Primero obtenemos un subtotal a partir del precio y la cantidad. Después pasamos el total por referencia para aplicar un cupón sobre esa misma variable. Podemos imaginar una caja registradora: una tarea calcula y otra actualiza el importe. Así podemos seguir cada paso sin mezclar todo dentro de main.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/06_Funciones/main.cpp).

```cpp
#include <iostream>

using namespace std;

// Los parámetros por valor son copias; el resultado regresa con return.
int subtotal(int cantidad, int precio) {
    return cantidad * precio;
}
// int& es un alias del total original: el descuento sí cambia la variable de main.
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

**Práctica.** Realiza un programa integrador de una compra con cupón.

- Calcular el subtotal en una función que devuelva un número.
- Aplicar el descuento mediante una referencia al total.
- Impedir que el descuento deje un total negativo.
- Mostrar subtotal y total final.

### 01.07.01. Arreglos unidimensionales

Vamos a guardar varios enteros en un mismo cajón. Con int cajon[4] reservamos cuatro compartimentos del mismo tipo. Los contamos desde cero: cajon[0] es el primero y cajon[3] el último. Los corchetes nos permiten elegir una casilla; no comprueban por nosotros que exista, así que nunca usamos cajon[4]. Recorremos las casillas para sumar sus datos y después cambiamos la segunda. Este arreglo tiene un tamaño fijo y no necesita una biblioteca adicional.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/07_Arreglos/01_Unidimensionales/main.cpp).

**Práctica.** Realiza un programa que trabaje con cinco calificaciones.

- Guardarlas en un arreglo int notas[5].
- Recorrer solo las posiciones de 0 a 4.
- Calcular la suma y el promedio con decimales.
- Mostrar la nota más alta.

### 01.07.02. Matrices

Vamos a pasar de un cajón a un mueble con varios cajones. En int mueble[2][3] tenemos dos filas y tres columnas. Primero elegimos la fila y después la casilla: mueble[1][2] es la tercera casilla de la segunda fila. Usamos un ciclo para las filas y otro para los datos de cada fila. Ambos recorridos empiezan en cero y se detienen antes de salir del mueble.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/07_Arreglos/02_Matrices/main.cpp).

**Práctica.** Realiza un programa que muestre una matriz de dos filas y tres columnas.

- Guardar seis números en un arreglo con dos pares de corchetes.
- Mostrar cada fila en una línea.
- Calcular por separado la suma de cada fila.
- No acceder a filas o columnas fuera del arreglo.

### 01.07. Arreglos

Vamos a combinar un arreglo de una dimensión con una matriz. En notas guardamos dos alumnos, cada uno con tres calificaciones; en promedios guardamos un resultado por alumno. Recorremos una fila, sumamos sus notas y dividimos entre 3.0. Al escribir 3.0, la división conserva los decimales del promedio.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/07_Arreglos/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    // Cada fila guarda las tres notas de un alumno; las posiciones empiezan en cero.
    int notas[2][3]{{8, 9, 10}, {7, 8, 9}};
    double promedios[2]{};
    for (int fila = 0; fila < 2; ++fila) {
        int suma = 0;
        for (int nota : notas[fila]) {
            suma += nota;
        }
        // Con 3.0 obtenemos un resultado con decimales.
        promedios[fila] = suma / 3.0;
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}
```

**Práctica.** Realiza un programa integrador de calificaciones por alumno.

- Guardar tres alumnos con cuatro notas cada uno en una matriz.
- Guardar los tres promedios en otro arreglo.
- Mostrar el promedio y si cada alumno aprobó.
- Mantener las notas entre 0 y 10.

### 01.08. Cadenas con string

Vamos a trabajar con texto usando string. Podemos imaginar un collar en el que cada cuenta es una letra o un signo. Con + unimos textos, con size contamos sus posiciones y con find buscamos una parte. Si la búsqueda devuelve string::npos, esa parte no existe. Solo después de comprobarlo usamos substr para tomar un fragmento. Aquí trabajamos con texto sencillo; una letra con acento puede ocupar más de una posición según cómo se guarde.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/08_Cadenas/main.cpp).

```cpp
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
```

**Práctica.** Realiza un programa que busque una palabra dentro de una frase.

- Guardar la frase y la palabra en variables string.
- Mostrar la posición cuando la palabra exista.
- Mostrar un aviso cuando find devuelva string::npos.
- Extraer el fragmento únicamente si fue encontrado.

### 01.09. Punteros: una caja, una tarjeta y una tarjeta de otra tarjeta

Primero vamos a distinguir el dato de su dirección. Una variable como int es una caja que guarda un entero; un puntero también es una variable, pero guarda la dirección de otra caja. Podemos imaginar un dedo que señala dónde está el dato. Con & obtenemos esa dirección; con * seguimos la dirección para leer o cambiar el dato. Copiar el puntero copia la dirección, no la caja. Con int** guardamos la dirección de un puntero: seguimos dos señales para llegar al entero.

Una referencia es otra etiqueta de la misma caja; un puntero puede cambiar de destino o guardar nullptr, que significa que no señala nada. Nos sirve, por ejemplo, para elegir un producto o unir nodos de listas, árboles y grafos. No necesitamos crear memoria nueva para señalar una variable existente. Antes de seguir un puntero comprobamos que tiene un destino y que ese dato aún existe: una dirección no mantiene viva la caja ni se vuelve nullptr automáticamente cuando desaparece.

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

**Práctica.** Realiza un programa que permita seleccionar entre dos enteros mediante un puntero.

- Crear dos variables y un puntero que señale una de ellas.
- Cambiar el dato mediante * y mostrar la variable original.
- Cambiar el destino del puntero y mostrar ambos enteros.
- Asignar nullptr al terminar y comprobarlo antes de intentar leer.
- Dibujar las cajas y las flechas después de cada cambio.

### 01.10. Leer y escribir archivos

Vamos a conservar texto cuando termine el programa. Podemos pensar en la memoria como un pizarrón y en un archivo como un cuaderno que guardamos. Con `ofstream` abrimos el cuaderno para escribir y con `ifstream` lo abrimos para leer. Ambos vienen de `<fstream>`. Usamos `ios::app` para agregar líneas al final sin borrar las anteriores. Comprobamos que cada archivo se pudo abrir y leemos una línea por vuelta; cuando no hay otra, el ciclo termina.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/10_Archivos/main.cpp).

```cpp
#include <iostream>

// Con fstream podemos escribir y leer archivos.
#include <fstream>

// Con string guardamos la ruta y cada línea leída.
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";

    // Con ios::app agregamos una línea sin borrar las anteriores.
    {
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo para escribir.\n";
            return 1;
        }

        salida << "Estudiar C++\n";
        // Al salir de este bloque, el archivo se cierra solo.
    }

    // Abrimos el mismo archivo para leerlo.
    ifstream entrada(ruta);
    if (!entrada) {
        cerr << "No se pudo abrir el archivo para leer.\n";
        return 1;
    }

    string linea;
    // getline lee línea por línea y el bucle termina por sí solo al llegar al final del archivo.
    while (getline(entrada, linea)) {
        cout << linea << "\n";
    }

    // Al terminar el programa, el archivo también se cierra solo.
    return 0;
}
```

**Práctica.** Realiza un programa que guarde y consulte recordatorios.

- Agregar un recordatorio al final de un archivo de texto.
- Comprobar que el archivo se pudo abrir para escribir y leer.
- Leer y mostrar todas sus líneas.
- Ejecutarlo dos veces y comprobar que conserva ambos recordatorios.

### 01.11. Recursión

Vamos a resolver una tarea llamando a la misma función con un caso más pequeño; a eso lo llamamos recursión. Aquí calculamos el factorial: 4! significa 4 por 3 por 2 por 1. En `factorial(n)` multiplicamos n por el resultado de `factorial(n - 1)`. Detenemos las llamadas cuando n es 0 o 1. Podemos imaginar cajas dentro de cajas: abrimos hasta la más pequeña y después regresamos reuniendo resultados. Antes de llamar a la función comprobamos que el número esté entre 0 y 12, para que el resultado quepa en `int`.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/11_Recursion/main.cpp).

```cpp
#include <iostream>

using namespace std;

int factorial(int n) {
    // Caso base: 0! y 1! valen 1. Sin un caso que termine, la recursión no se detendría.
    if (n <= 1) {
        return 1;
    }
    // Cada llamada resuelve un problema menor; al regresar se multiplican los resultados.
    return n * factorial(n - 1);
}

int main() {
    const int numero = 5;
    if (numero < 0 || numero > 12) {
        cerr << "Usa un numero entre 0 y 12.\n";
        return 1;
    }
    cout << factorial(numero) << "\n";
}
```

**Práctica.** Realiza un programa que calcule una suma mediante recursión.

- Crear una función para sumar desde 1 hasta n.
- Definir un caso que termine sin otra llamada.
- Usar un valor menor en cada llamada.
- Probar 0, 1 y 5 y explicar cómo vuelve el resultado.

### 01.12. Const y headers en programación estructurada

Vamos a repartir un programa en archivos. En Calificaciones.h escribimos qué funciones podemos usar; en Calificaciones.cpp escribimos sus pasos; desde main.cpp las llamamos. Podemos imaginar el .h como el menú y el .cpp como la cocina. Con const protegemos las notas para no cambiarlas por accidente. Pasamos también cuántas notas hay: al recibir un arreglo como parámetro, la función necesita esa cantidad para saber dónde detenerse. Con #ifndef, #define y #endif evitamos leer dos veces el mismo header dentro de un archivo que compilamos.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/12_Const_y_Headers/main.cpp).

```cpp
#include "Calificaciones.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const int notas[3]{8, 9, 10};
    double promedio = 0;
    // Recibimos true si las notas son válidas; el promedio se escribe mediante una referencia.
    if (!calcularPromedio(notas, 3, promedio)) {
        cerr << "Las notas deben estar entre 0 y 10.\n";
        return 1;
    }
    cout << "Promedio: " << promedio << "\n";
    if (estaAprobado(promedio)) {
        cout << "Aprobado\n";
    } else {
        cout << "Reprobado\n";
    }
}
```

**Práctica.** Realiza un programa de calificaciones dividido en tres archivos.

- Declarar las funciones en un .h y escribirlas en otro .cpp.
- Recibir las notas como un arreglo const junto con su cantidad.
- Calcular promedio y nota máxima sin modificar las notas.
- Mostrar desde main si el promedio alcanza la nota aprobatoria.
- Compilar los dos .cpp juntos.

### 01.13. Integrador: reporte de calificaciones

Vamos a reunir lo aprendido en un reporte. Guardamos notas en un arreglo, calculamos el promedio con una función y usamos una condición para decidir si hay aprobación. Con consulta guardamos la dirección del resultado: *consulta permite leer ese mismo promedio. Después armamos una línea de texto y la agregamos a un archivo. Podemos seguir el camino completo del dato: notas, cálculo, decisión, mensaje y cuaderno guardado.

Ejemplo completo: [main.cpp](01_Programacion_Estructurada/13_Integrador/main.cpp).

```cpp
// Leemos y guardamos archivos con ifstream y ofstream.
#include <fstream>
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

bool promedio(const int notas[], int cantidad, double& salidaPromedio) {
    if (cantidad <= 0) {
        return false;
    }
    long long suma = 0;
    for (int indice = 0; indice < cantidad; ++indice) {
        const int nota = notas[indice];
        if (nota < 0 || nota > 10) {
            return false;
        }
        suma += nota;
    }
    salidaPromedio = static_cast<double>(suma) / cantidad;
    return true;
}

int main() {
    const int notas[3]{8, 9, 10};
    double resultado = 0;
    if (!promedio(notas, 3, resultado)) {
        cerr << "Las notas no son validas.\n";
        return 1;
    }
    // Este puntero permite consultar el promedio sin modificarlo ni hacerse dueño de su memoria.
    const double* consulta = &resultado;

    string estado;
    if (*consulta >= 6) {
        estado = "Aprobado";
    } else {
        estado = "Reprobado";
    }
    const string reporte = "Ana: " + to_string(*consulta) + " - " + estado;
    // El reporte reúne arreglo, función, decisión, cadena y archivo en un mismo recorrido.
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

**Práctica.** Realiza un programa integrador de reportes escolares.

- Guardar nombres y tres notas por alumno con string y arreglos.
- Calcular promedio y nota máxima mediante funciones.
- Usar una referencia para actualizar un dato y un puntero para consultar otro.
- Clasificar cada promedio con if y mostrar el reporte.
- Guardar los reportes en un archivo sin borrar los anteriores.
- Separar declaraciones y funciones en un .h y un .cpp.

## Programación orientada a objetos

### 02.01. Clases y objetos

Vamos a reunir datos y acciones que pertenecen a una misma cosa. Podemos imaginar una clase como el molde de un bloque de Minecraft: indica qué datos tiene y qué puede hacer cada bloque creado con ese molde. Cada bloque concreto sería un objeto. En este programa usamos Bicicleta: guardamos color y velocidad, y con pedalear aumentamos la velocidad. Creamos roja y azul por separado; pedalear con roja no cambia azul. Llamamos atributos a esos datos y métodos a las funciones que escribimos dentro de la clase. Con public permitimos usarlos desde main.

Ejemplo completo: [main.cpp](02_POO/01_Clases_y_Objetos/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

// La clase es el molde; cada objeto tendrá su propio color y velocidad.
class Bicicleta {
// Estos atributos públicos introducen objetos; el siguiente tema protegerá el estado.
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

**Práctica.** Realiza un programa con una clase Bloque inspirada en Minecraft.

- Guardar un nombre, una textura como texto y una dureza.
- Crear dos objetos con datos diferentes.
- Agregar una acción para reducir la dureza sin dejarla negativa.
- Mostrar que cambiar un bloque no cambia el otro.

### 02.02. Encapsulamiento y const

Vamos a proteger el saldo de una alcancía. En lugar de permitir cualquier cambio desde main, lo guardamos dentro de la clase y ofrecemos depositar y retirar. Cada función comprueba sus reglas antes de cambiar el saldo. Llamamos encapsulamiento a reunir esos datos y sus reglas detrás de operaciones controladas. Dentro de class, los datos son privados si no escribimos public. Con consultar() const podemos leer el saldo sin cambiarlo: const al final de una función promete respetar los datos del objeto.

Ejemplo completo: [main.cpp](02_POO/02_Encapsulamiento/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Alcancia {
    int saldo = 0; // Centavos enteros para evitar errores de redondeo.
// saldo es privado por defecto en class. Solo los métodos validados pueden cambiarlo.
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
    // const después de los paréntesis promete que la consulta no modifica el objeto.
    int consultar() const {
        return saldo;
    }
};

int main() {
    Alcancia ahorro;
    if (ahorro.depositar(-5)) {
        return 1;
    }
    if (!ahorro.depositar(500)) {
        return 1;
    }
    if (ahorro.retirar(600)) {
        return 1;
    }
    if (!ahorro.retirar(200)) {
        return 1;
    }

    cout << ahorro.consultar() << " centavos\n";
}
```

**Práctica.** Realiza un programa con una alcancía que proteja su saldo.

- Guardar el saldo como dato privado.
- Aceptar depósitos positivos y retiros que no superen el saldo.
- Devolver si cada operación pudo realizarse.
- Consultar el saldo con un método const.
- Probar un retiro mayor que el dinero disponible.

### 02.03. Constructores, destructores

Vamos a observar cuándo empieza y termina un objeto. El constructor tiene el nombre de la clase y prepara sus datos; en Sesion guarda el usuario y anuncia su entrada. El destructor lleva ~ delante del nombre y se ejecuta cuando termina la vida del objeto. Podemos imaginar que abrimos una tienda y la cerramos al salir. En este ejemplo las llaves delimitan esa estancia: al llegar a su cierre aparece el mensaje de salida. Más adelante usaremos la misma idea para liberar memoria y cerrar archivos automáticamente.

Ejemplo completo: [main.cpp](02_POO/03_Constructores_y_Destructores/main.cpp).

```cpp
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
```

**Práctica.** Realiza un programa que muestre la vida de dos sesiones.

- Guardar un nombre al construir cada objeto.
- Mostrar un mensaje en cada constructor y destructor.
- Crear los dos objetos dentro de las mismas llaves.
- Anotar en qué orden aparecen sus mensajes al salir.

### 02.04. Composición

Vamos a construir una cosa usando otra como parte. Un Auto tiene un Motor; por eso guardamos un objeto Motor dentro de Auto. A esta relación la llamamos composición. Desde main pedimos que arranque el auto, y el auto se encarga de encender su motor. Podemos imaginar un bloque que contiene un inventario: tener una parte no significa ser esa parte. Al terminar el auto también termina el motor que contiene.

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
    // Composición: un Auto TIENE un Motor. Su vida está ligada a la del auto.
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

    if (autoRojo.enMarcha()) {
        cout << "Motor encendido\n";
    }
}
```

**Práctica.** Realiza un programa con un cofre que contenga un inventario.

- Crear una clase Inventario con una cantidad de objetos.
- Guardar un Inventario como parte de Cofre.
- Agregar una operación del cofre que consulte esa cantidad.
- Crear dos cofres y comprobar que sus inventarios son independientes.

### 02.05. Herencia

Vamos a describir una versión más específica de algo que ya tenemos. Una BicicletaElectrica sigue siendo una Bicicleta, pero también tiene batería. Con : public Bicicleta conservamos las operaciones públicas de la bicicleta y agregamos las propias. Llamamos herencia a esta relación. En asistir revisamos la batería antes de gastarla y pedalear. Nos conviene cuando podemos decir «es una»; para decir «tiene una parte» usamos la composición del tema anterior.

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

// Herencia: una bicicleta eléctrica ES una bicicleta y reutiliza sus operaciones públicas.
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
    if (!bici.asistir()) {
        return 1;
    }

    cout << "Velocidad: " << bici.consultarVelocidad() << "\n";
}
```

**Práctica.** Realiza un programa con una bicicleta eléctrica.

- Conservar las operaciones de una clase Bicicleta mediante herencia.
- Agregar una batería con carga inicial.
- Impedir la asistencia cuando no alcance la batería.
- Mostrar velocidad y carga después de varios intentos.

### 02.06. Polimorfismo y clases abstractas

Vamos a pedir la misma acción a objetos diferentes. Con tocar pedimos que suene un Instrumento, pero una Guitarra y un Tambor responden de forma distinta. A eso lo llamamos polimorfismo. Con virtual permitimos que cada instrumento tenga su propia respuesta; con = 0 dejamos esa respuesta pendiente en la clase general; con override comprobamos que la nueva función corresponde a la que queremos reemplazar. Pasamos una referencia para usar el instrumento original. El destructor virtual permite limpiar el objeto completo si después lo eliminamos mediante un puntero a Instrumento.

Ejemplo completo: [main.cpp](02_POO/06_Polimorfismo/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

class Instrumento {
public:
    // Una base polimórfica usa destructor virtual para destruir correctamente sus objetos
    // derivados.
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

// La referencia evita copiar la base; virtual elige el sonido según el objeto real.
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

**Práctica.** Realiza un programa que haga sonar tres instrumentos.

- Conservar una clase general Instrumento con sonar virtual.
- Crear tres clases que respondan con sonidos distintos.
- Usar una sola función tocar para los tres objetos.
- Agregar destructor virtual a la clase general.

### 02.07.01. Memoria dinámica manual

Vamos a crear una caja mientras el programa está funcionando. Con new int(42) reservamos espacio para un entero y recibimos su dirección. Guardamos esa dirección en numero y con *numero consultamos el 42. Esa caja no desaparece por dejar de usar la variable puntero: aquí debemos liberarla una sola vez con delete. Después ponemos numero en nullptr para no reutilizar esa dirección. Nunca usamos delete sobre una variable normal ni seguimos un puntero después de liberar su dato.

Ejemplo completo: [main.cpp](02_POO/07_Memoria_y_Punteros/01_New_y_Delete/main.cpp).

**Práctica.** Realiza un programa que reserve un entero y cambie su valor.

- Crear el entero con new y guardar su dirección.
- Mostrar y modificar el dato mediante el puntero.
- Liberarlo exactamente una vez con delete.
- Dejar el puntero en nullptr y no volver a leer el dato liberado.

### 02.07.02. Propiedad con unique_ptr

Vamos a dar a una sola herramienta la responsabilidad de liberar la caja. Con `unique_ptr`, de `<memory>`, guardamos esa responsabilidad junto con la dirección. `make_unique` crea el dato y `get` nos presta su dirección para consultarlo. Ese puntero prestado no debe liberar el dato. Al terminar el programa, `propietario` libera el entero por nosotros. Así evitamos olvidar un `delete`.

Ejemplo completo: [main.cpp](02_POO/07_Memoria_y_Punteros/02_Unique_Ptr/main.cpp).

**Práctica.** Vamos a guardar una cantidad con `unique_ptr`.

- Crear un entero con make_unique.
- Leerlo mediante un puntero obtenido con get.
- Mostrar la cantidad mediante la dirección prestada.
- Dejar que `unique_ptr` libere el dato al terminar, sin usar `delete`.

### 02.07. Memoria y punteros en POO

Vamos a aplicar los punteros a un objeto `Alumno`. Creamos el alumno con `make_unique` y prestamos su dirección con `get`. Con `consulta->consultarNombre()` seguimos esa dirección y llamamos a una función del alumno; `->` significa seguir el puntero y usar el punto. Primero dejamos de usar la dirección prestada y ponemos `consulta` en `nullptr`. Después llamamos a `reset` para liberar el alumno. El puntero prestado nunca lo libera.

Ejemplo completo: [main.cpp](02_POO/07_Memoria_y_Punteros/main.cpp).

```cpp
#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos y trabajamos con texto mediante string.
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
    // get devuelve un observador: el unique_ptr sigue siendo el dueño y libera el objeto.
    const Alumno* consulta = propietario.get();

    cout << consulta->consultarNombre() << "\n";
    // Dejamos de usar la dirección prestada antes de destruir el objeto con reset.
    consulta = nullptr;
    propietario.reset();
}
```

**Práctica.** Realiza un programa integrador con un objeto administrado por unique_ptr.

- Crear una clase con nombre y una consulta const.
- Crear un objeto con make_unique y observarlo mediante get.
- Mostrar su nombre usando ->.
- Retirar el observador antes de llamar reset.
- Explicar qué variable liberó el objeto.

### 02.08. Const, headers y compilación de varios archivos

Vamos a separar una clase para poder usarla desde varios programas. En Producto.h mostramos qué datos guarda y qué operaciones ofrece; en Producto.cpp escribimos cómo trabajan esas operaciones. Desde main creamos un Producto con nombre y precio. Guardamos el precio en centavos enteros para evitar pequeñas diferencias de los decimales. Con const protegemos el objeto y sus consultas. Para ejecutar necesitamos compilar main.cpp junto con Producto.cpp; incluir el .h solo anuncia las funciones, no añade sus pasos.

Ejemplo completo: [main.cpp](02_POO/08_Headers/main.cpp).

```cpp
#include "Producto.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    // Un objeto const solo permite llamar métodos que respeten su estado, como estas consultas.
    const Producto cuaderno("Cuaderno", 1250);

    cout << cuaderno.consultarNombre() << ": " << cuaderno.consultarPrecio() << " centavos\n";
}
```

**Práctica.** Realiza un programa con una clase Producto separada en archivos.

- Guardar nombre y precio privado en centavos.
- Declarar la clase en Producto.h y sus funciones en Producto.cpp.
- Consultar ambos datos mediante métodos const.
- Crear dos productos desde main y mostrar sus datos.
- Rechazar un precio negativo.

### 02.09.01. DAO en memoria y CRUD

Vamos a reunir en LibroDAO las tareas de guardar, buscar, cambiar y eliminar libros. Podemos imaginar un encargado del catálogo: le pedimos un libro por su id, que es un número que lo identifica. DAO es el nombre habitual de una clase dedicada al acceso a datos. Aquí guardamos los libros en un vector, por lo que desaparecen al terminar el programa. buscar presta un puntero al libro, o devuelve nullptr si no existe. Antes de leerlo comprobamos el resultado; después de cambiar el catálogo volvemos a buscarlo, porque el vector puede mover sus libros.

Ejemplo completo: [main.cpp](02_POO/09_DAO/01_DAO_en_Memoria/main.cpp).

**Práctica.** Realiza un catálogo de libros que funcione en memoria.

- Crear libros con un id positivo y un título no vacío.
- Impedir dos libros con el mismo id.
- Buscar, actualizar y eliminar por id.
- Comprobar el puntero antes de mostrar un resultado.
- Informar cuando un libro no exista.

### 02.09.02. Persistir un DAO en un archivo

Vamos a guardar el catálogo en un archivo para recuperarlo después. En la primera línea escribimos cuántos libros hay; después usamos dos líneas por libro: una para su número y otra para su título. Así conservamos los espacios y las comillas del título. Al ejecutar el ejemplo otra vez, escribimos el catálogo actual en el archivo. Si encontramos datos incorrectos al leer, conservamos el catálogo que ya teníamos. Para probar una entrada incompleta usamos `istringstream`, de `<sstream>`: nos permite leer texto en memoria como si fuera un archivo, sin dañar el archivo real.

Ejemplo completo: [main.cpp](02_POO/09_DAO/02_DAO_en_Archivo/main.cpp).

**Práctica.** Realiza un catálogo que pueda guardarse y recuperarse.

- Guardar al menos dos libros en un archivo.
- Comprobar errores al abrir, escribir y leer.
- Recuperar los libros en otro objeto DAO.
- Probar títulos con espacios y comillas.
- Rechazar una lectura incompleta conservando el catálogo anterior.

### 02.09. DAO: separar el acceso a datos

Vamos a recorrer todo el trabajo del catálogo: crear libros, cambiar un título, eliminar un libro y recuperar lo guardado. Aquí usamos stringstream, de <sstream>, como un cuaderno temporal en memoria: podemos escribir en él y volver a leer sin crear un archivo en disco. Después probamos una lectura con ids repetidos. La regla es sencilla: si no podemos recuperar todos los datos correctamente, conservamos el catálogo que ya teníamos.

Ejemplo completo: [main.cpp](02_POO/09_DAO/main.cpp).

```cpp
#include "LibroDAO.h"
#include <iostream>
// Leemos o escribimos texto en memoria como si fuera un archivo.
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO original;
    if (!original.crear({1, "Estructuras"})) {
        return 1;
    }
    if (!original.crear({2, "Objetos"})) {
        return 1;
    }
    if (!original.actualizar(2, "Objetos y \"clases\"")) {
        return 1;
    }
    if (!original.eliminar(1)) {
        return 1;
    }
    // Simulamos un archivo en memoria para guardar y recuperar sin crear datos en disco.
    stringstream archivo;
    if (!original.guardar(archivo)) {
        return 1;
    }
    LibroDAO copia;
    if (!copia.cargar(archivo)) {
        return 1;
    }
    if (copia.todos().size() != 1) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    const Libro* libro = copia.buscar(2);
    if (libro == nullptr || libro->titulo != "Objetos y \"clases\"") {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    istringstream duplicados("2\n2\nUno\n2\nDos\n");
    if (copia.cargar(duplicados)) {
        return 1;
    }
    if (copia.todos().size() != 1) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << libro->titulo << "\n";
}

// Práctica integradora: vamos a administrar y recuperar un catálogo de tres libros.
// - Cambiamos un título, eliminamos un libro y guardamos los restantes.
// - Cargamos los datos en otro catálogo y comprobamos sus títulos.
// - Probamos datos repetidos y conservamos el catálogo anterior si falla la carga.
```

**Práctica.** Realiza un programa integrador para administrar y recuperar libros.

- Crear tres libros, cambiar un título y eliminar uno.
- Guardar el resultado y cargarlo en un segundo catálogo.
- Comparar los libros recuperados con los originales.
- Probar un id duplicado y un archivo incompleto.
- Conservar los datos anteriores si falla la carga.

### 02.10. Integrador: una biblioteca con objetos

Vamos a construir una pequeña biblioteca con varias clases que colaboran. Biblioteca contiene un DAO para guardar libros. Una Vista decide cómo mostrarlos: VistaDetalle escribe sus datos y VistaResumen muestra cuántos hay. Pedimos mostrar el catálogo de la misma manera aunque cambiemos de vista. Así reunimos composición, datos protegidos, consultas const y polimorfismo. Con unique_ptr dejamos claro quién se encarga de liberar la vista cuando ya no la usamos.

Ejemplo completo: [main.cpp](02_POO/10_Integrador/main.cpp).

```cpp
#include "../09_DAO/LibroDAO.h"
#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;
using namespace curso;

class Biblioteca {
    // Composición: la biblioteca delega el almacenamiento al DAO.
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
    if (!biblioteca.registrar({1, "Aprender C++"})) {
        return 1;
    }
    if (biblioteca.registrar({1, "Duplicado"})) {
        return 1;
    }
    // La misma interfaz muestra detalle o resumen gracias al polimorfismo; unique_ptr administra
    // su vida.
    unique_ptr<Vista> vista = make_unique<VistaDetalle>();

    cout << vista->mostrar(biblioteca.catalogo());
    vista = make_unique<VistaResumen>();

    cout << vista->mostrar(biblioteca.catalogo());
}

// Práctica integradora: vamos a añadir otra forma de mostrar la biblioteca.
// - Creamos una VistaTitulos que muestre solo los nombres de los libros.
// - Registramos dos libros y mostramos sus títulos mediante un puntero a Vista.
// - Mostramos después el resumen con la misma variable vista.
```

**Práctica.** Realiza una biblioteca integradora de POO.

- Separar clases y funciones en archivos .h y .cpp.
- Guardar los libros mediante un DAO contenido en Biblioteca.
- Ofrecer una vista de detalle y otra de resumen mediante una clase general.
- Rechazar ids duplicados y títulos vacíos.
- Consultar sin modificar mediante const.
- Guardar y recuperar el catálogo de un archivo.

## Estructuras de datos y algoritmos

### 03.01. Complejidad: tiempo y espacio

Vamos a comparar cuánto trabajo hacemos cuando aumentan los datos. Llegar directamente a una casilla requiere una cantidad fija de pasos, aunque haya más casillas (O(1); no significa exactamente un paso). Revisar diez casillas implica diez visitas y revisar veinte implica veinte (O(n), donde n es la cantidad de casillas). Si vamos dividiendo por la mitad, de 8 a 1 hacemos tres divisiones y de 16 a 1 hacemos cuatro (O(log n), donde log n describe ese crecimiento por mitades). Llamamos notación O grande a estas abreviaturas: describen crecimiento, no segundos exactos. También podemos contar cuántos datos adicionales guardamos para hacer la tarea; a eso lo llamamos memoria auxiliar.

Ejemplo completo: [main.cpp](03_EDD/01_Complejidad/main.cpp).

```cpp
#include <iostream>

using namespace std;

int pasosMitad(int n) {
    int pasos = 0;
    while (n > 1) {
        // Cada vuelta reduce lo pendiente a la mitad: 1024 llega a 1 en diez divisiones. Si
        // empezamos con el doble, 2048, basta una división más (crecimiento O(log n), con n como
        // cantidad inicial).
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

**Práctica.** Realiza un programa que compare dos formas de contar trabajo.

- Contar las visitas al recorrer 8, 16 y 32 elementos.
- Contar las divisiones necesarias para reducir esos números hasta 1.
- Mostrar ambos resultados en una tabla.
- Explicar con palabras por qué no crecen de la misma forma.

### 03.02.01. Crear y recorrer un vector

Vamos a usar un cajón cuya cantidad de casillas puede crecer: vector<int>, de <vector>. Con push_back agregamos al final y con size consultamos cuántos datos hay. Recorremos los números para sumarlos. Cuando se llena el espacio reservado, el vector puede mudarse a otro bloque y llevarse sus datos; las direcciones anteriores ya no sirven. Normalmente agregar al final es rápido. De vez en cuando copiamos todos los datos a un lugar más grande, como cuando cambiamos un cajón pequeño por otro con más espacio.

Ejemplo completo: [main.cpp](03_EDD/02_Vectores/01_Crear_y_Recorrer/main.cpp).

**Práctica.** Realiza un programa que reúna varias cantidades en un vector.

- Comenzar con dos números y agregar otros tres con push_back.
- Mostrar la cantidad de elementos.
- Recorrerlos para calcular suma y promedio.
- Comprobar que no esté vacío antes de dividir.

### 03.02.02. Insertar y eliminar en vectores

Vamos a abrir y quitar espacios en medio de un vector. Con begin() obtenemos una posición que señala el inicio; begin() + 1 señala el segundo elemento. A esa forma de señalar una posición la llamamos iterador. insert coloca un dato y desplaza los siguientes; erase quita uno y cierra el hueco. Por eso puede tocar mover casi todos los elementos. Después del cambio volvemos a obtener las posiciones que necesitamos. Antes de pop_back comprobamos empty para no quitar algo de un vector vacío.

Ejemplo completo: [main.cpp](03_EDD/02_Vectores/02_Insertar_y_Eliminar/main.cpp).

**Práctica.** Realiza un programa que edite una lista de números.

- Insertar un número entre otros dos.
- Eliminar el primero y mostrar el resultado.
- Quitar el último solo si hay elementos.
- Mostrar el vector después de cada operación.

### 03.02.03. Vectores de objetos

Vamos a guardar fichas completas dentro del vector. Con struct Alumno reunimos un nombre y una nota, como dos casillas de una misma ficha. vector<Alumno> guarda esas fichas y push_back agrega otra. Con const auto& leemos cada ficha sin copiarla: auto permite que C++ deduzca el tipo, & nos da otra etiqueta del mismo objeto y const impide cambiarlo mediante esa etiqueta. Usamos el punto para elegir un dato de la ficha.

Ejemplo completo: [main.cpp](03_EDD/02_Vectores/03_Vector_de_Objetos/main.cpp).

**Práctica.** Realiza un programa que guarde fichas de alumnos.

- Agrupar nombre y nota en un struct.
- Guardar al menos tres alumnos en un vector.
- Recorrer las fichas mediante referencias const.
- Mostrar los alumnos con nota de al menos 6.

### 03.02. Vectores

Vamos a reunir creación, cambios y fichas de objetos en una lista de tareas. Cada Tarea guarda su nombre y si ya terminó. Insertamos una tarea, marcamos otra y quitamos una ficha. Podemos imaginar una libreta donde agregamos y retiramos renglones. El vector mantiene juntos los datos, pero sus posiciones pueden cambiar al insertar o borrar; por eso no confundimos el nombre de una tarea con su posición actual.

Ejemplo completo: [main.cpp](03_EDD/02_Vectores/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

struct Tarea {
    string nombre;
    bool terminada;
};

int main() {
    vector<Tarea> tareas{{"Leer", false}, {"Practicar", false}};
    // Insertar en medio desplaza los elementos siguientes; el vector conserva su orden.
    tareas.insert(tareas.begin() + 1, {"Compilar", false});
    tareas.at(0).terminada = true;
    tareas.erase(tareas.begin());
    for (const auto& tarea : tareas) {
        cout << tarea.nombre << "\n";
    }
}
```

**Práctica.** Realiza un programa integrador de tareas con vector.

- Guardar nombre y estado de cada tarea en un struct.
- Agregar una tarea al final y otra en medio.
- Marcar una tarea como terminada.
- Eliminar una tarea y mostrar las restantes.
- Comprobar las posiciones antes de usarlas.

### 03.03.01. Lista simplemente ligada

Vamos a construir una cadena de cajas llamadas nodos. Cada nodo guarda un dato y un puntero al siguiente, como una nota que indica dónde está la próxima caja. La lista guarda la dirección del primero; el último señala nullptr. Para buscar seguimos las notas una a una: quizá debamos visitar todos los nodos. Al quitar un nodo unimos su vecino anterior con el siguiente antes de liberar la caja. Podemos ver esos pasos dentro de ListaSimple.h.

Ejemplo completo: [main.cpp](03_EDD/03_Listas_Ligadas/01_Simplemente_Ligada/main.cpp).

```cpp
#include "ListaSimple.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple lista;
    if (!(lista.valores().empty() && !lista.eliminar(99))) {
        return 1;
    }
    // Los nodos formarán la cadena 10 -> 20 -> 30; los enlaces se implementan en el header.
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

**Práctica.** Realiza un programa con una lista simplemente ligada.

- Agregar tres números mediante nodos y enlaces.
- Mostrar los números siguiendo los enlaces.
- Eliminar un nodo intermedio sin perder los demás.
- Probar la lista vacía y la eliminación de su último nodo.
- Liberar cada nodo cuando deje de pertenecer a la lista.

### 03.03.02. Lista doblemente ligada

Vamos a añadir una segunda flecha a cada nodo: una hacia el siguiente y otra hacia el anterior. Así podemos recorrer la cadena en ambos sentidos. Conservamos también el principio y el final para agregar al final ajustando unas pocas flechas, sin recorrer toda la lista. Al borrar cuidamos ambas conexiones, como al retirar un vagón de un tren unido por delante y por detrás. Podemos seguir el ajuste de los punteros en ListaDoble.h.

Ejemplo completo: [main.cpp](03_EDD/03_Listas_Ligadas/02_Doblemente_Ligada/main.cpp).

**Práctica.** Realiza un programa con una lista doblemente ligada.

- Guardar tres números y mostrarlos en ambos sentidos.
- Eliminar el nodo central y volver a recorrerla.
- Probar la eliminación del primero y del último.
- Comprobar que los enlaces de regreso coincidan con los de avance.

### 03.03.03. Lista circular

Vamos a cerrar la cadena formando un círculo: el último nodo vuelve al primero. Podemos imaginar turnos de jugadores que se repiten. Como no encontramos nullptr al dar la vuelta, detenemos el recorrido al regresar al inicio. Guardamos el último nodo para añadir otro con pocos cambios. Al quitar el único nodo dejamos la lista vacía; al quitar otro conservamos cerrado el círculo.

Ejemplo completo: [main.cpp](03_EDD/03_Listas_Ligadas/03_Circular/main.cpp).

**Práctica.** Realiza un programa que organice turnos en una lista circular.

- Agregar tres jugadores identificados por número.
- Mostrar exactamente una vuelta de turnos.
- Eliminar un jugador sin romper el círculo.
- Probar una lista de un solo jugador y después vaciarla.

### 03.03. Listas ligadas

Vamos a comparar las tres listas usando los mismos números. En la simple seguimos una flecha, en la doble podemos regresar y en la circular volvemos al inicio. Insertamos 10, 20 y 30, quitamos 20 y revisamos qué queda. La diferencia principal está en cómo unimos los nodos y cuándo detenemos el recorrido. Podemos dibujar las mismas tres cajas y cambiar solo sus flechas para entenderlo.

Ejemplo completo: [main.cpp](03_EDD/03_Listas_Ligadas/main.cpp).

**Práctica.** Realiza un programa integrador que compare tres listas.

- Insertar los mismos cinco datos en una lista simple, una doble y una circular.
- Eliminar el mismo dato de las tres.
- Mostrar los recorridos normales y el recorrido inverso de la doble.
- Limitar la circular a una vuelta.
- Probar cada lista después de vaciarla.

### 03.04.01. Una pila con vector

Vamos a usar un vector como una pila de platos: solo ponemos y quitamos por arriba. Con push_back agregamos, con back miramos el último dato y con pop_back lo retiramos. El último en entrar es el primero en salir. Antes de consultar o quitar revisamos que la pila no esté vacía. Si necesitamos el dato retirado, lo guardamos antes de llamar pop_back, porque esa operación no lo devuelve.

Ejemplo completo: [main.cpp](03_EDD/04_Pilas/01_Con_Vector/main.cpp).

**Práctica.** Realiza un programa que retire números como una pila de platos.

- Agregar cuatro números al final de un vector.
- Consultar y retirar siempre el último.
- Mostrar los números en su orden de salida.
- Evitar consultar o retirar cuando esté vacío.

### 03.04.02. El adaptador stack

Vamos a usar stack, la herramienta de <stack> que ofrece directamente las operaciones de una pila. push agrega arriba, top permite leer la cima y pop la retira. Podemos imaginar un historial para deshacer: la última acción que hicimos es la primera que revisamos. Aquí mostramos qué acción se desharía; retirarla del historial no modifica por sí sola un documento real.

Ejemplo completo: [main.cpp](03_EDD/04_Pilas/02_Con_Stack/main.cpp).

```cpp
#include <iostream>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    stack<string> historial;
    historial.push("Escribir");
    historial.push("Borrar");
    if (!historial.empty()) {

        // top consulta el último valor; pop lo elimina y no devuelve el dato.
        cout << "Deshacer: " << historial.top() << "\n";
        historial.pop();
    }
}
```

**Práctica.** Realiza un programa que muestre acciones pendientes de deshacer.

- Guardar tres descripciones de acciones en stack<string>.
- Mostrar la última acción antes de retirarla.
- Retirar todas en orden inverso a su llegada.
- Avisar cuando no queden acciones.

### 03.04. Pilas

Vamos a comparar una pila construida con vector con otra de tipo stack. Introducimos 1, 2 y 3 en ambas y retiramos por el extremo superior. En las dos debe salir primero el 3. La idea que estamos practicando es el orden de salida; una pila se reconoce por esa regla, aunque usemos herramientas distintas para guardarla.

Ejemplo completo: [main.cpp](03_EDD/04_Pilas/main.cpp).

**Práctica.** Realiza un programa integrador que compare dos pilas.

- Agregar los mismos datos a un vector y a un stack.
- Consultar las dos cimas antes de retirar.
- Comprobar que sale el mismo dato en cada paso.
- Terminar con ambas pilas vacías.

### 03.05.01. Cola FIFO

Vamos a atender una fila por orden de llegada. Con queue, de <queue>, agregamos al final mediante push, consultamos al primero con front y lo retiramos con pop. Podemos imaginar una fila de personas esperando una ventanilla. Antes de atender revisamos empty. A la regla «primero en entrar, primero en salir» también la llamamos FIFO; las siglas solo abrevian esa misma idea.

Ejemplo completo: [main.cpp](03_EDD/05_Colas/01_Con_Queue/main.cpp).

```cpp
#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    queue<string> fila;
    fila.push("Ana");
    fila.push("Luis");

    // La persona al frente llegó primero; consultar y retirar requieren una cola no vacía.
    while (!fila.empty()) {
        cout << "Atender: " << fila.front() << "\n";
        fila.pop();
    }
}
```

**Práctica.** Realiza un programa que atienda una fila de personas.

- Guardar al menos tres nombres en queue<string>.
- Mostrar quién está al frente antes de retirarlo.
- Atender en el mismo orden en que llegaron.
- Avisar cuando la fila quede vacía.

### 03.05.02. Cola de prioridad y heap

Vamos a atender según importancia en lugar de llegada. priority_queue coloca arriba el valor con mayor prioridad: con enteros, normalmente es el mayor. Si queremos el menor, como un costo, usamos greater<int>, una regla de comparación de <functional>. Podemos imaginar urgencias de un hospital: llegar antes no siempre significa pasar antes. Con top consultamos el siguiente y con pop lo retiramos; siempre necesitamos que haya datos.

Ejemplo completo: [main.cpp](03_EDD/05_Colas/02_Cola_de_Prioridad/main.cpp).

**Práctica.** Realiza un programa que compare prioridades y costos.

- Guardar los valores 2, 9 y 4 en dos colas de prioridad.
- Retirar primero el mayor en una y el menor en la otra.
- Mostrar todos los valores en ambos órdenes.
- Comprobar que no estén vacías antes de top o pop.

### 03.05. Colas

Vamos a poner los mismos datos en una fila normal y en una fila con prioridad. Al guardar 2, 9 y 4, la primera conserva ese orden; la segunda atiende primero el 9. Así podemos decidir qué regla necesita una aplicación: respetar la llegada o elegir por importancia. Cambiar la estructura cambia esa regla de atención, aunque los datos sean iguales.

Ejemplo completo: [main.cpp](03_EDD/05_Colas/main.cpp).

**Práctica.** Realiza un programa integrador de atención de solicitudes.

- Guardar las mismas prioridades en queue y priority_queue.
- Mostrar el orden completo de atención de cada una.
- Agregar una solicitud nueva después de atender una.
- Explicar cuál usar para una taquilla y cuál para urgencias.

### 03.06.01. Árbol binario: raíces, hijos y hojas

Vamos a unir nodos formando ramas. En un árbol binario cada nodo puede tener como máximo un hijo izquierdo y uno derecho. Al primer nodo lo llamamos raíz; a uno sin hijos lo llamamos hoja. Aquí solo estamos construyendo la forma: tener dos ramas no obliga a ordenar los números. Para contar, sumamos el nodo actual y los de sus dos ramas mediante recursión. Usamos unique_ptr para que cada rama libere sus nodos al terminar.

Ejemplo completo: [main.cpp](03_EDD/06_Arboles/01_Arbol_Binario/main.cpp).

```cpp
#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
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
    // Una rama vacía aporta cero; cada nodo suma uno más los nodos de sus dos hijos.
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

**Práctica.** Realiza un programa que construya un árbol binario de cinco nodos.

- Crear una raíz y ramas con máximo dos hijos por nodo.
- Dibujar qué nodo pertenece a cada rama.
- Contar los nodos mediante una función recursiva.
- Comprobar que una rama vacía aporta cero.

### 03.06.02. Árbol binario de búsqueda (ABB)

Vamos a añadir una regla al árbol: los números menores van a la izquierda y los mayores a la derecha. Así, al buscar elegimos una rama y descartamos la otra. Llamamos a esta organización árbol binario de búsqueda, o ABB. Aquí no guardamos repetidos. Al borrar un nodo con dos hijos buscamos un reemplazo que conserve el orden. Si el árbol queda como una cadena, tendremos que recorrer muchos nodos; no basta con llamarlo árbol para que siempre busque rápido.

Ejemplo completo: [main.cpp](03_EDD/06_Arboles/02_Binario_de_Busqueda/main.cpp).

**Práctica.** Realiza un programa con un árbol binario de búsqueda.

- Insertar siete números sin repetir.
- Buscar un número presente y otro ausente.
- Eliminar una hoja, un nodo con un hijo y uno con dos hijos.
- Mostrar los datos ordenados después de cada eliminación.

### 03.06.03. Recorridos de un árbol

Vamos a visitar el mismo árbol en tres órdenes. En preorden leemos primero el nodo y después sus ramas; en inorden leemos izquierda, nodo y derecha; en postorden dejamos el nodo para el final. En un árbol de búsqueda, inorden nos muestra los números ordenados. Podemos imaginar que recorremos las mismas habitaciones pero anotamos su nombre al entrar, a mitad de la visita o al salir. En todos los casos visitamos todos los nodos.

Ejemplo completo: [main.cpp](03_EDD/06_Arboles/03_Recorridos/main.cpp).

**Práctica.** Realiza un programa que muestre tres recorridos del mismo árbol.

- Construir un árbol con al menos siete nodos.
- Mostrar preorden, inorden y postorden por separado.
- Predecir las tres salidas con un dibujo antes de ejecutar.
- Comprobar que cada nodo aparece una vez en cada recorrido.

### 03.06. Árboles

Vamos a integrar las operaciones del árbol: insertar, buscar, recorrer y eliminar. Usamos Arbol.h para seguir los mismos enlaces en cada caso. Primero comprobamos el árbol vacío, agregamos datos, comparamos sus recorridos y al final retiramos todos los nodos. Podemos pensar en cuidar un árbol de carpetas: cada cambio debe conservar el acceso a las ramas que todavía existen.

Ejemplo completo: [main.cpp](03_EDD/06_Arboles/main.cpp).

**Práctica.** Realiza un programa integrador para administrar números en un árbol.

- Agregar y buscar números sin permitir repetidos.
- Ofrecer los tres recorridos.
- Eliminar la raíz sin perder los otros datos.
- Vaciar el árbol y volver a insertar.
- Mostrar un mensaje cuando una búsqueda no encuentre el número.

### 03.07. Tablas hash con unordered_map

Vamos a buscar por una clave, como encontrar una ficha de alumno por su matrícula. unordered_map relaciona una clave con un dato; aquí un número con un nombre. Por dentro usa una función hash, que calcula en qué grupo buscar la clave. Con find buscamos sin crear una ficha; si obtenemos end(), no existe. En la ficha encontrada, first es la clave y second el dato. No esperamos que sus fichas aparezcan ordenadas. Habitualmente revisamos pocas entradas, pero si muchas claves caen juntas podemos tener que revisar muchas.

Ejemplo completo: [main.cpp](03_EDD/07_Tablas_Hash/main.cpp).

```cpp
#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Relacionamos una clave con un dato para buscar, como matrícula y nombre.
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> alumnos;
    alumnos.emplace(101, "Ana");
    alumnos.emplace(102, "Luis");
    // find consulta sin insertar una clave nueva; aquí sabemos que 101 existe porque se agregó
    // antes.
    auto encontrado = alumnos.find(101);
    cout << encontrado->second << "\n";
    if (!(alumnos.erase(102) == 1 && alumnos.size() == 1)) {
        return 1;
    }
}
```

**Práctica.** Realiza un directorio de alumnos por matrícula.

- Guardar tres matrículas distintas con sus nombres.
- Buscar con find y comprobar si el resultado es end().
- Eliminar una matrícula y volver a buscarla.
- Mostrar un aviso sin crear datos cuando no exista una matrícula.

### 03.08.01. Representar grafos

Vamos a dibujar lugares unidos por caminos. A cada lugar lo llamamos vértice y a cada conexión arista; al conjunto lo llamamos grafo. En conectar indicamos origen, destino y costo. Si queremos ida y vuelta agregamos ambas direcciones. Guardamos una lista de vecinos por lugar: la memoria crece con los lugares y caminos. Otra posibilidad es una tabla con una casilla por pareja de lugares: cinco lugares necesitan 25 casillas y diez necesitan 100.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/01_Representacion/main.cpp).

```cpp
#include "../Grafo.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(3);
    // Una arista representa un trayecto de origen a destino; el tercer argumento es su costo.
    mapa.conectar(0, 1, 5);
    mapa.conectar(1, 0, 5); // Carretera de ida y vuelta.
    mapa.conectar(1, 2, 2); // Solo ida.

    for (const auto& arista : mapa.vecinos(1)) {
        cout << "1 -> " << arista.destino << " costo " << arista.peso << "\n";
    }
}
```

**Práctica.** Realiza un programa que represente cuatro lugares y sus caminos.

- Crear un grafo con cuatro vértices.
- Agregar caminos de ida y otro de ida y vuelta.
- Guardar un costo no negativo por camino.
- Mostrar los vecinos de cada lugar.
- Dibujar el mismo mapa con círculos y flechas.

### 03.08.02. BFS: búsqueda en anchura

Vamos a explorar un mapa por capas. Primero visitamos el inicio, después sus vecinos y después los vecinos de estos. Guardamos lo pendiente en una cola para respetar ese orden. A este recorrido lo llamamos BFS, o búsqueda en anchura. Marcamos cada lugar al agregarlo para no repetirlo, aunque haya caminos de regreso. Solo llegamos a lugares conectados con el inicio. Si recorremos todo el mapa, revisamos sus lugares y caminos.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/02_BFS/main.cpp).

**Práctica.** Realiza un programa que recorra un mapa por capas con BFS.

- Crear un mapa con cinco lugares y uno aislado.
- Usar una cola para los lugares pendientes.
- Marcar los visitados para evitar repeticiones.
- Mostrar el orden desde un origen y explicar por qué el aislado no aparece.

### 03.08.03. DFS: búsqueda en profundidad

Vamos a seguir un camino hasta donde podamos y después regresar para probar otro. Podemos imaginar la exploración de un laberinto. A este recorrido lo llamamos DFS, o búsqueda en profundidad. Aquí usamos recursión para recordar por dónde volver. Marcamos los lugares visitados para no dar vueltas sin fin. El orden puede diferir del de BFS aunque ambos alcancen los mismos lugares. Si revisamos todo el mapa, el trabajo crece con sus lugares y caminos.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/03_DFS/main.cpp).

**Práctica.** Realiza un programa que explore un mapa con DFS.

- Crear varios caminos y uno que regrese al origen.
- Marcar los lugares visitados.
- Mostrar el recorrido sin repetir lugares.
- Comparar el orden con BFS usando el mismo mapa.

### 03.08.04. Dijkstra: caminos de menor costo

Vamos a buscar el camino cuyo costo total sea menor. Podemos imaginar que cada carretera indica minutos: llegar con menos carreteras no siempre significa llegar antes. Con Dijkstra guardamos el mejor costo conocido y atendemos primero el candidato más barato mediante una cola de prioridad. Si encontramos una mejora, actualizamos el costo. Esta versión requiere costos no negativos. INFINITO es una marca para indicar que aún no encontramos una ruta; no representa minutos reales. dijkstra devuelve costos; en caminosMinimos también guardamos de dónde llegamos para reconstruir una ruta.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/04_Dijkstra/main.cpp).

**Práctica.** Realiza un programa que calcule el menor costo entre lugares.

- Crear un mapa con costos no negativos.
- Incluir una ruta indirecta más barata que una directa.
- Calcular los costos desde un origen con Dijkstra.
- Mostrar un aviso para un destino sin ruta.
- Dibujar y sumar a mano la ruta más barata para comprobarla.

### 03.08. Grafos

Vamos a usar un mismo mapa para contestar preguntas distintas. Con BFS exploramos por capas; con DFS seguimos una rama antes de volver; con Dijkstra buscamos el menor costo acumulado. Compartimos Grafo.h para no construir un mapa diferente en cada prueba. Podemos comparar los recorridos, pero no interpretamos el orden de BFS o DFS como una lista de costos: cada herramienta responde una pregunta diferente.

Ejemplo completo: [main.cpp](03_EDD/08_Grafos/main.cpp).

**Práctica.** Realiza un programa integrador de rutas de una escuela.

- Guardar al menos cinco edificios y los minutos entre ellos.
- Mostrar BFS y DFS desde el mismo edificio.
- Calcular el menor costo con Dijkstra.
- Incluir un edificio sin conexión y avisar si no es alcanzable.
- Separar el grafo y sus operaciones en un header.

### 03.09.01. Burbuja

Vamos a ordenar comparando vecinos. Si el de la izquierda es mayor, cambiamos sus posiciones; repetimos una pasada y el mayor pendiente acaba al final. Podemos imaginar burbujas grandes que van subiendo. Si una pasada no hace cambios, ya terminamos. Con muchos datos podemos repetir las comparaciones una y otra vez; si ya estaban ordenados basta una pasada. La función completa está en Ordenamientos.h.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/01_Burbuja/main.cpp).

**Práctica.** Realiza un programa que ordene números por burbuja.

- Usar datos con negativos y repetidos.
- Comparar vecinos y cambiarlos cuando estén invertidos.
- Detenerse cuando una pasada no haga cambios.
- Mostrar el vector antes y después.

### 03.09.02. Selección

Vamos a buscar el menor dato pendiente y colocarlo al principio de la zona sin ordenar. Después repetimos con el resto. Podemos imaginar que elegimos el libro más pequeño de un montón y lo ponemos en una fila. Aunque los números ya estén ordenados, seguimos buscando el menor de cada grupo; con muchos datos repetimos la búsqueda del menor muchas veces. Al intercambiar posiciones lejanas podemos cambiar el orden de elementos que empatan.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/02_Seleccion/main.cpp).

**Práctica.** Realiza un programa que ordene por selección.

- Buscar la posición del menor dato pendiente.
- Intercambiarlo con el primero de la zona sin ordenar.
- Mostrar el arreglo después de cada pasada.
- Probar datos ya ordenados y datos repetidos.

### 03.09.03. Inserción

Vamos a ordenar como una mano de cartas. Tomamos un dato nuevo y desplazamos los anteriores que sean mayores hasta abrirle un lugar. Así mantenemos ordenada la parte izquierda. Si los datos ya están ordenados avanzamos una sola vez; si debemos desplazar muchos en cada paso, podemos necesitar muchas comparaciones. Al no adelantar un dato sobre otro igual conservamos el orden de los empates.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/03_Insercion/main.cpp).

**Práctica.** Realiza un programa que ordene por inserción.

- Mantener ordenada la parte izquierda del vector.
- Guardar el dato actual antes de desplazar los mayores.
- Mostrar dónde queda cada nuevo dato.
- Probar una lista ordenada y otra en orden inverso.

### 03.09.04. Merge sort

Vamos a dividir un montón en mitades hasta tener grupos pequeños y después reunirlos en orden. Podemos imaginar dos ayudantes que ordenan sus hojas: al juntarlas elegimos siempre la menor hoja disponible. Eso hace merge sort. Necesitamos otro espacio para la mezcla, que crece con todos los datos. En cada nivel recorremos todos los datos y tenemos tantos niveles como divisiones por mitades. Ante un empate tomamos primero el dato de la izquierda para conservar su orden.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/04_Merge_Sort/main.cpp).

**Práctica.** Realiza un programa que ordene por mezcla.

- Dividir los datos hasta llegar a grupos de un elemento.
- Mezclar dos grupos ordenados en un espacio auxiliar.
- Tomar primero el de la izquierda cuando haya empate.
- Dibujar las divisiones y las mezclas de seis números.

### 03.09.05. Quick sort

Vamos a elegir un dato como referencia para separar los demás; a ese dato lo llamamos pivote. Ponemos los menores de un lado y repetimos en cada grupo. Eso hace quick sort. Si los grupos quedan parejos, cada nivel revisa todos los datos y los niveles crecen por mitades. Aquí elegimos el último dato: con entradas ordenadas o iguales puede quedar casi todo de un lado y repetirse mucho trabajo. Esta elección nos ayuda a observar por qué importa el pivote.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/05_Quick_Sort/main.cpp).

**Práctica.** Realiza un programa que ordene con quick sort.

- Elegir y señalar el pivote en cada paso.
- Separar los menores antes de continuar con los grupos.
- Probar datos mezclados, ordenados e iguales.
- Dibujar un caso donde un grupo quede casi vacío.

### 03.09.06. Ordenar con la biblioteca estándar

Vamos a comparar lo aprendido con herramientas que C++ ya trae en <algorithm>. sort ordena un grupo entre begin() y end(); end() marca el lugar después del último dato. Para fichas de alumnos damos una función que decide cuál va primero. La función pequeña escrita con [] se llama lambda: aquí recibe dos alumnos y compara sus notas con <. stable_sort conserva el orden previo de quienes empatan. Primero entendemos los movimientos manuales y ahora podemos usar esta herramienta para resolver una tarea completa.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/06_STD_Sort/main.cpp).

```cpp
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
```

**Práctica.** Realiza un programa que ordene fichas de alumnos.

- Guardar nombre y nota en un vector de structs.
- Ordenar por nota con una función de comparación.
- Usar stable_sort para conservar el orden de los empates.
- Mostrar el resultado y comprobar dos alumnos con la misma nota.

### 03.09. Algoritmos de ordenamiento

Vamos a comprobar cinco maneras de ordenar usando las mismas entradas. Creamos una copia para cada algoritmo y comparamos su resultado con sort. Incluimos datos vacíos, negativos, repetidos y ya ordenados. Guardamos direcciones de funciones para poder llamar a cada algoritmo de la misma manera: igual que un puntero puede señalar una caja, un puntero a función puede señalar una tarea que podemos ejecutar. Si alguna comparación falla, mostramos el problema y terminamos.

Ejemplo completo: [main.cpp](03_EDD/09_Ordenamiento/main.cpp).

**Práctica.** Realiza un programa integrador de ordenamientos.

- Aplicar burbuja, selección, inserción, merge sort y quick sort a copias de los mismos datos.
- Comparar sus resultados.
- Probar vacío, un elemento, negativos, repetidos y orden inverso.
- Contar comparaciones en al menos dos algoritmos.
- Explicar por qué una misma salida puede requerir distinto trabajo.

### 03.10.01. Búsqueda lineal

Vamos a buscar como si revisáramos un cajón casilla por casilla. No necesitamos ordenar antes: avanzamos hasta encontrar el dato o llegar al final. Podemos visitar todos los elementos. Para devolver el resultado usamos optional: una cajita de <optional> que puede guardar una posición o estar vacía. Comprobamos si contiene algo antes de leer *posicion. Una posición cero es un resultado válido; no debemos confundirla con «no encontrado».

Ejemplo completo: [main.cpp](03_EDD/10_Busqueda/01_Lineal/main.cpp).

**Práctica.** Realiza un programa que busque números uno por uno.

- Buscar sin ordenar el vector.
- Devolver la primera posición encontrada.
- Distinguir una posición cero de un resultado ausente.
- Probar el primero, el último, uno repetido y uno inexistente.

### 03.10.02. Búsqueda binaria

Vamos a buscar en una lista ya ordenada. Miramos el centro y decidimos en qué mitad podría estar el número. Podemos imaginar una guía de páginas numeradas: si buscamos una página menor, descartamos la mitad derecha. Reducir 16 candidatos a 8, 4, 2 y 1 requiere cuatro divisiones; empezar con 32 agrega solo otra. Esta versión encuentra la primera coincidencia. Recibimos una posición o un resultado vacío y comprobamos cuál antes de leerlo.

Ejemplo completo: [main.cpp](03_EDD/10_Busqueda/02_Binaria/main.cpp).

```cpp
#include "../Busquedas.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    // Los datos ya están ordenados: cada comparación puede descartar la mitad pendiente.
    const vector<int> datos{1, 3, 3, 5, 8};
    auto posicion = binaria(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}
```

**Práctica.** Realiza un programa que busque mediante división por mitades.

- Usar números ordenados de menor a mayor.
- Mostrar cómo cambian los límites de la búsqueda.
- Encontrar la primera coincidencia si hay repetidos.
- Avisar cuando el dato no exista.
- Explicar por qué no funciona igual en datos desordenados.

### 03.10. Búsqueda

Vamos a comparar la búsqueda uno por uno con la búsqueda por mitades. Primero buscamos en datos sin ordenar, después ordenamos y probamos ambas sobre el mismo vector. El número sigue siendo el mismo, pero su posición puede cambiar al ordenar. También contamos el trabajo previo: preparar una lista ordenada es una tarea adicional, aunque buscar dentro de ella después sea más rápido.

Ejemplo completo: [main.cpp](03_EDD/10_Busqueda/main.cpp).

**Práctica.** Realiza un programa integrador de búsquedas.

- Buscar varios valores con búsqueda lineal.
- Crear una copia ordenada para la búsqueda binaria.
- Comparar si ambas encuentran o no cada valor.
- Mostrar cómo cambia la posición al ordenar.
- Probar también un vector vacío.

### 03.11. Const y headers en EDD

Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar nada. Si duplicamos la cantidad de datos hacemos el doble de visitas. Solo añadimos un contador y unas pocas variables.

Ejemplo completo: [main.cpp](03_EDD/11_Const_y_Headers/main.cpp).

```cpp
#include "Consultas.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{9, 4, 10, 6};
    // La consulta recibe const vector<int>&: cuenta sin copiar ni modificar los datos.
    const size_t cantidad = contarMayores(datos, LIMITE_DE_EJEMPLO);
    cout << "Valores mayores a " << LIMITE_DE_EJEMPLO << ": " << cantidad << "\n";
    for (const int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
```

**Práctica.** Realiza un programa de consultas separado en archivos.

- Declarar una función en un .h y escribirla en un .cpp.
- Recibir un vector mediante const vector<int>&.
- Contar valores menores que un límite usando un ciclo.
- Devolver cero para un vector vacío.
- Comprobar que los datos originales no cambiaron.

### 03.12. Integrador: procesar tareas y consultar rutas

Vamos a reunir las estructuras en un taller de tareas y entregas. Guardamos tareas en un vector, atendemos por una cola y anotamos lo ocurrido en una lista. Con una pila consultamos cuál sería la última acción a deshacer. Usamos un árbol y una tabla por id para practicar consultas; ordenamos números antes de buscarlos por mitades. Finalmente usamos un grafo para calcular rutas. Cada estructura responde una necesidad distinta; este ejemplo las reúne para observar cómo se pasan los datos.

Ejemplo completo: [main.cpp](03_EDD/12_Integrador/main.cpp).

```cpp
#include "../03_Listas_Ligadas/01_Simplemente_Ligada/ListaSimple.h"
#include "../06_Arboles/Arbol.h"
#include "../08_Grafos/Grafo.h"
#include "../09_Ordenamiento/Ordenamientos.h"
#include "../10_Busqueda/Busquedas.h"
#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Relacionamos una clave con un dato para buscar, como matrícula y nombre.
#include <unordered_map>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> nombres{{1, "Leer"}, {2, "Compilar"}, {3, "Practicar"}};
    // La cola organiza el trabajo por llegada; la tabla hash relaciona cada ID con su nombre.
    queue<int> pendientes;
    priority_queue<int> urgencias;
    for (int id : ids) {
        pendientes.push(id);
        urgencias.push(id);
    }
    ListaSimple historial;
    // La pila consulta la última tarea; la lista registra el historial y el ABB facilita
    // consultas.
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
    if (!(historial.valores() == ids && deshacer.top() == 2)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(urgencias.top() == 3 && indice.contiene(2))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    mergeSort(ids);
    if (!(ids == indice.valores())) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(binaria(ids, 2).value() == 1)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }

    // El grafo modela trayectos; Dijkstra calcula el costo de entrega más bajo.
    Grafo rutas(3);
    rutas.conectar(0, 1, 4);
    rutas.conectar(0, 2, 1);
    rutas.conectar(2, 1, 1);
    if (!(bfs(rutas, 0).size() == 3 && dfs(rutas, 0).size() == 3)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(dijkstra(rutas, 0).at(1) == 2)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << "Ultima tarea (deshacer): " << nombres.at(deshacer.top()) << "\n";
    cout << "Costo minimo de entrega 0 -> 1: " << dijkstra(rutas, 0).at(1) << "\n";
}
```

**Práctica.** Realiza un programa integrador de tareas y rutas.

- Guardar ids y nombres de al menos cuatro tareas.
- Atender por llegada con una cola y guardar historial en una lista.
- Consultar la última tarea mediante una pila.
- Ordenar ids y buscar uno mediante búsqueda binaria.
- Representar entregas con un grafo y calcular costos con Dijkstra.
- Explicar qué responsabilidad cumple cada estructura.

### 03.13.01. 1. Un arreglo que contiene objetos

Vamos a guardar objetos completos en un arreglo. En Producto productos[3] cada compartimento contiene un producto con su nombre y precio. Reutilizamos Producto.h, que ya estudiamos en POO. Podemos imaginar un cajón con tres bloques de Minecraft: cada bloque conserva sus propios datos, aunque todos tengan el mismo tipo. Recorremos los productos mediante const Producto& para leer el original sin copiarlo ni cambiarlo. Cuando termina el arreglo también terminan los objetos que contiene.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/01_Arreglo_de_Clases/main.cpp).

**Práctica.** Realiza un programa con un arreglo de productos.

- Crear tres objetos completos con nombre y precio.
- Recorrerlos mediante referencias const.
- Sumar sus precios en centavos.
- Mostrar cada producto y el total.
- Explicar qué contiene una casilla del arreglo.

### 03.13.02. 2. Un struct contiene una clase; un arreglo contiene esos structs

Vamos a añadir la cantidad disponible a cada producto. Con struct Registro juntamos un Producto y un entero cantidad; después guardamos varias fichas Registro en un arreglo. Podemos imaginar un compartimento que contiene el producto y una etiqueta con sus existencias. Con registros[0].producto llegamos al objeto y con registros[0].cantidad al número. recibirUnidad recibe Registro& para cambiar la ficha original: si quitamos &, cambiaríamos solo una copia.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/02_Arreglo_de_Structs_con_Clases/main.cpp).

**Práctica.** Realiza un programa que registre existencias por producto.

- Crear un struct que contenga un Producto y una cantidad.
- Guardar al menos dos registros en un arreglo.
- Recibir unidades mediante una función con referencia.
- Rechazar cantidades negativas y evitar superar el límite del entero.
- Mostrar las fichas después del cambio.

### 03.13.03. 3. Un arreglo de tarjetas para enteros

Vamos a guardar direcciones en lugar de enteros. En int* direcciones[3] tenemos tres tarjetas: cada una puede señalar una caja que está fuera del arreglo. Con *direcciones[0] seguimos la primera tarjeta y cambiamos rojo; con direcciones[0] = &azul cambiamos únicamente la tarjeta. Podemos tener dos tarjetas para la misma caja, o nullptr cuando no elegimos ninguna. El arreglo guarda los punteros, pero no se encarga de borrar los enteros locales a los que apuntan.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/03_Arreglo_de_Punteros/main.cpp).

**Práctica.** Realiza un programa con tres tarjetas para dos enteros.

- Guardar direcciones en un arreglo int* tarjetas[3].
- Hacer que dos tarjetas señalen el mismo entero.
- Cambiar ese entero mediante una tarjeta y consultar desde la otra.
- Dejar una tarjeta en nullptr y comprobarla antes de seguirla.
- Mostrar que cambiar una dirección no cambia el contenido anterior.

### 03.13.04. 4. Un vector de punteros: una vista del inventario

Vamos a seleccionar productos sin copiarlos. Guardamos los productos en un arreglo y sus direcciones en vector<Producto*>. A esa selección la llamamos vista: puede crecer o mostrar un producto varias veces sin crear productos nuevos. Con Producto*& damos a seleccionar otra etiqueta del puntero original, por lo que puede cambiar su destino. Si recibiera solo Producto*, cambiaría una copia de la tarjeta. Aunque crezca el vector de direcciones, estos productos del arreglo permanecen en su lugar; deben seguir existiendo mientras los consultamos.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/04_Vector_de_Punteros/main.cpp).

**Práctica.** Realiza un programa que muestre una selección de productos.

- Guardar tres productos completos en un arreglo.
- Guardar sus direcciones en un vector de punteros.
- Cambiar una selección mediante una referencia a puntero.
- Mostrar un producto dos veces sin copiarlo.
- Comprobar que los productos originales conservan su posición.

### 03.13.05. 5. Un arreglo de arreglos de punteros

Vamos a organizar las tarjetas en filas y columnas. Producto* casillas[2][2] representa dos filas de dos direcciones. Con casillas[0][1] elegimos una tarjeta; si no es nullptr, podemos seguirla hasta el producto. Dos casillas pueden mostrar el mismo producto, como dos letreros que señalan la misma tienda. En este ejemplo añadimos const después de * para fijar las tarjetas; todavía podemos modificar los productos señalados. No confundimos una matriz con Producto**: la matriz contiene sus filas, mientras que el doble puntero guarda una dirección hacia otro puntero.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/05_Matriz_de_Punteros/main.cpp).

**Práctica.** Realiza una vitrina de productos con una matriz de punteros.

- Crear dos filas con dos casillas cada una.
- Incluir una casilla nullptr y dos que señalen el mismo producto.
- Mostrar un aviso en las casillas vacías.
- Cambiar un producto y comprobar que ambas tarjetas muestran el cambio.
- Contar casillas ocupadas sin confundirlas con productos distintos.

### 03.13.06. 6. Nodos dentro de un arreglo, unidos por punteros

Vamos a guardar nodos completos dentro de un arreglo y unirlos con punteros. Cada Nodo contiene un Producto y siguiente, la dirección del próximo nodo. Las cajas están en las posiciones 0, 1 y 2, pero podemos recorrerlas en el orden 0, 2 y 1 siguiendo las flechas. El último enlace es nullptr. Como las cajas pertenecen al arreglo y no las creamos con new, no usamos delete. Limitamos las visitas a tres para detectar si por error cerramos un círculo. Al copiar manualmente estas fichas habría que reconstruir sus flechas para no seguir apuntando a las originales.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/06_Arreglo_de_Nodos/main.cpp).

**Práctica.** Realiza un programa que enlace nodos dentro de un arreglo.

- Guardar tres nodos con productos.
- Conectar las posiciones en el orden 2, 0 y 1.
- Recorrer desde el nodo inicial siguiendo siguiente.
- Detenerse en nullptr o avisar si se excede la cantidad de nodos.
- Dibujar posiciones del arreglo y orden de visita por separado.

### 03.13.07. 7. Un vector de propietarios y un puntero observador

Vamos a separar la ubicación de las tarjetas y la de los productos. En vector<unique_ptr<Producto>> cada tarjeta también tiene la responsabilidad de liberar su producto. Cuando el vector necesita más espacio puede mover las tarjetas; los productos creados aparte conservan sus direcciones. Con get prestamos una dirección, pero no la responsabilidad de borrar. Al eliminar la tarjeta responsable también se destruye el producto; antes dejamos de usar todos los punteros prestados. Esto es distinto de vector<Producto>, donde al crecer pueden mudarse los productos mismos.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/07_Vector_de_Unique_Ptr/main.cpp).

**Práctica.** Realiza un programa con productos administrados por unique_ptr dentro de un vector.

- Crear dos productos con make_unique.
- Obtener un puntero de consulta mediante get.
- Aumentar la capacidad del vector y comprobar la dirección del producto.
- Retirar todas las consultas antes de borrar a su propietario.
- Mostrar cuántos productos quedan.

### 03.13.08. 8. Una clase administra nodos struct

Vamos a reunir la cadena y sus reglas dentro de Estante. Cada nodo contiene un Producto y un unique_ptr al siguiente; el estante se encarga del primero. Desde fuera pedimos agregar o consultar, sin cambiar directamente los enlaces. Podemos imaginar un encargado de estantería que acomoda las cajas y nos presta sus etiquetas para leerlas. primero() y siguienteNodo() prestan direcciones; consultarProducto() presta una referencia de lectura. Cuando vaciamos el estante, esas consultas dejan de servir porque sus cajas ya no existen.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/08_Clase_con_Nodos/main.cpp).

**Práctica.** Realiza un programa con una clase que administre una lista de productos.

- Guardar el primer nodo dentro de la clase.
- Agregar tres productos mediante una operación pública.
- Recorrerlos usando consultas const.
- Calcular el valor total.
- Vaciar la lista sin volver a usar direcciones de nodos eliminados.

### 03.13.09. 9. Un vector contiene clases que administran nodos

Vamos a guardar varios estantes en un vector. Dentro de cada estante hay nodos y dentro de cada nodo un producto: seguimos esas capas una a una. Al crecer el vector puede mudarse un estante, por lo que retiramos los punteros al propio estante antes de forzar ese cambio. Sus nodos se crearon aparte y no se mudan al transferir quién los administra. Por eso podemos conservar una consulta a un nodo mientras siga existiendo. Si vaciamos su estante, el nodo desaparece y debemos dejar de usar esa consulta.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/09_Vector_de_Clases_con_Nodos/main.cpp).

**Práctica.** Realiza un programa con un vector de estantes que tengan nodos.

- Crear dos estantes y agregar productos a sus listas.
- Distinguir un puntero al estante de otro a uno de sus nodos.
- Retirar el puntero al estante antes de aumentar la capacidad del vector.
- Consultar el nodo desde su nuevo propietario.
- Retirar la consulta antes de vaciar su lista.

### 03.13. Integrador: propietarios, vistas, matrices y ordenamiento

Vamos a combinar las capas para mostrar productos ordenados sin mover sus cajas originales. Guardamos estantes en un vector; cada estante contiene nodos y cada nodo contiene un producto. Reunimos direcciones de esos nodos en vista y ordenamos solo las tarjetas por precio. Después elegimos tarjetas para una matriz de exposición. Una misma tarjeta puede aparecer varias veces: contar casillas ocupadas no significa contar productos distintos. Calculamos el valor total desde los estantes para no sumar dos veces un producto repetido en la vitrina.

Ejemplo completo: [main.cpp](03_EDD/13_Combinacion_de_Conceptos/main.cpp).

```cpp
// Usamos sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
#include <iostream>
// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Guardamos una colección que puede crecer con vector.
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
    const Estante::Nodo* const casillas[2][2]{
        {seleccion, nullptr},
        {vista.at(1), seleccion}
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

**Práctica.** Realiza un inventario integrador con estantes, nodos y vistas.

- Guardar varios estantes en un vector y sus productos en nodos struct.
- Crear una vista de punteros de lectura sin copiar los productos.
- Ordenar la vista por nombre o precio.
- Mostrar parte de la vista en una matriz de punteros con casillas vacías.
- Cambiar una selección mediante una referencia a puntero.
- Comprobar que el orden original y el total no cambian al ordenar la vista.
- Explicar qué estructura libera cada objeto.

## Proyecto integrador

Vamos a construir una aplicación de biblioteca y rutas del campus. Desde un menú agregamos libros, buscamos por id, organizamos entregas y consultamos caminos. Dividimos el trabajo: la consola conversa con la persona, Biblioteca aplica las reglas, el DAO guarda los libros y MapaCampus calcula rutas. Reutilizamos los headers del curso para conectar clases, listas, pilas, colas, búsquedas y grafos. Podemos seguir un pedido desde que entra hasta que queda registrado; cada archivo se ocupa de una parte de ese recorrido. La guía del proyecto explica las piezas con fragmentos de código.

[Guía por secciones](04_Proyecto_Integrador/README.md).

**Práctica.** Realiza una aplicación integradora de biblioteca y entregas.

- Organizar modelos, datos, servicios e interfaz en carpetas con .h y .cpp.
- Agregar, consultar, actualizar y eliminar libros con un DAO.
- Buscar ids mediante una vista ordenada y búsqueda binaria.
- Registrar el historial en una lista doble y los pendientes en una cola.
- Usar una pila para deshacer cambios del catálogo.
- Representar edificios como un grafo y calcular rutas con Dijkstra.
- Guardar los datos y recuperarlos al reiniciar.
- Validar entradas y conservar el catálogo cuando falle una escritura.
