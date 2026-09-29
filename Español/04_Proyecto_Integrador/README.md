# Biblioteca y rutas del campus

Una aplicación de consola que permite administrar libros y solicitar entregas entre edificios. El objetivo es unir las herramientas del curso alrededor de operaciones concretas: consultar, modificar, guardar, encolar, recorrer y encontrar una ruta.

Los fragmentos de esta guía muestran partes de la implementación, no programas independientes. Sigue los enlaces para leer las declaraciones y los métodos completos; el código también explica sus decisiones con comentarios. La [versión inglesa](../../English/04_Integrated_Project/README.md) tiene el mismo comportamiento.

## 1. Qué hace la aplicación

| Opción | Operación | Qué aplica |
| --- | --- | --- |
| 1 | Mostrar catálogo ordenado por ID | Vector de punteros de lectura y ordenamiento |
| 2 | Buscar un libro por ID | Búsqueda binaria sobre IDs ordenados |
| 3, 4, 5 | Agregar, renombrar y eliminar libros | POO, validación, DAO y archivos |
| 6 | Deshacer el último cambio del catálogo | Pila LIFO de instantáneas |
| 7 | Solicitar entrega de un libro | Structs, copia de objetos y cola FIFO |
| 8 | Atender la siguiente entrega | Grafo, Dijkstra y reconstrucción del camino |
| 9 | Consultar solicitudes pendientes | Copia de una cola sin consumirla |
| 10 | Ver historial hacia delante o atrás | Lista doble de índices y vector de mensajes |
| 11 | Mostrar mapa y edificios alcanzables | Lista de adyacencia y BFS |
| 0 | Cerrar la sesión | Destructores y liberación de recursos |

El catálogo se guarda después de cada cambio confirmado y de cada operación de deshacer. Solicitudes, historial y pila pertenecen a la sesión actual. Una solicitud guarda el título que tenía el libro al solicitarla; renombrar o eliminar su ficha después no altera esa solicitud. Simulamos el reparto, sin llevar existencias físicas ni préstamos.

## 2. Organización del proyecto

```text
04_Proyecto_Integrador/
├── README.md
├── include/
│   ├── modelos/Entrega.h
│   ├── datos/AlmacenCatalogo.h
│   ├── servicios/MapaCampus.h
│   ├── servicios/Biblioteca.h
│   ├── interfaz/Consola.h
│   └── pruebas/Autocomprobacion.h
├── src/
│   ├── main.cpp
│   ├── datos/AlmacenCatalogo.cpp
│   ├── servicios/MapaCampus.cpp
│   ├── servicios/Biblioteca.cpp
│   └── interfaz/Consola.cpp
├── tests/Autocomprobacion.cpp
└── datos/                       Catálogo generado al ejecutar
```

| Parte | Responsabilidad |
| --- | --- |
| Modelos | Describir una solicitud, una ruta y una entrega resuelta |
| Almacén | Cargar y guardar el DAO en memoria o en archivo |
| Mapa | Relacionar edificios y calcular recorridos |
| Biblioteca | Aplicar reglas y coordinar catálogo, cola, pila e historial |
| Consola | Pedir datos, presentar resultados y mostrar errores |
| main | Elegir el modo de ejecución y conectar los objetos |
| Comprobación | Verificar los flujos principales sin interacción manual |

Los `.h` declaran contratos y los `.cpp` implementan operaciones. Los includes usan `-Iinclude`; no se incluyen archivos `.cpp`. Reutilizamos [LibroDAO.h](../02_POO/09_DAO/LibroDAO.h), [ListaDoble.h](../03_EDD/03_Listas_Ligadas/02_Doblemente_Ligada/ListaDoble.h), [Busquedas.h](../03_EDD/10_Busqueda/Busquedas.h) y [Grafo.h](../03_EDD/08_Grafos/Grafo.h), en lugar de copiarlos. Por eso hay que conservar el proyecto dentro del curso.

## 3. Compilar y ejecutar

Abre Git Bash **en esta carpeta**, `Español/04_Proyecto_Integrador`. Necesitas C++17 y `g++`:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/datos/AlmacenCatalogo.cpp src/servicios/MapaCampus.cpp src/servicios/Biblioteca.cpp src/interfaz/Consola.cpp tests/Autocomprobacion.cpp -o build/biblioteca.exe
./build/biblioteca.exe
```

En PowerShell, crea la carpeta con `New-Item -ItemType Directory -Force build`; el comando de compilación es el mismo. Ejecuta desde la raíz del proyecto, porque la ruta predeterminada del catálogo es `datos/catalogo.txt`. En Linux o macOS puedes omitir `.exe`.

```bash
./build/biblioteca.exe --demo
./build/biblioteca.exe --data "datos/mi_catalogo.txt"
./build/biblioteca.exe --self-test
./build/biblioteca.exe --help
```

`--demo` prepara tres libros en memoria para practicar sin crear un catálogo en disco. `--data` permite elegir otro archivo. `--self-test` ejecuta la comprobación y termina; no modifica archivos. Son modos alternativos, no se combinan. No necesitas instalar bibliotecas adicionales.

En Windows, `main.cpp` obtiene los argumentos con las API nativas de Unicode para conservar rutas como `Español` o nombres en otros alfabetos. Esa parte está dentro de `#ifdef _WIN32`; en otros sistemas se usa `argv`. El resto de la aplicación utiliza la biblioteca estándar y los headers del curso.

## 4. Un recorrido para empezar

Ejecuta `--demo`. El catálogo empieza con los IDs 10, 20 y 30, aunque su vector propietario no está ordenado. Usa la opción 1 para verlos ordenados y la 2 para buscar el 20.

Después elige la opción 7, indica el libro 10, origen 0 y destino 4. Consulta pendientes con 9 y atiende con 8. Verás:

```text
Biblioteca -> Ingenieria -> Laboratorio -> Administracion -> Residencias | 7 minutos
```

Agrega un libro con 3, consulta el catálogo y deshaz con 6. En la opción 10 puedes recorrer el historial en ambos sentidos. Solicitar una ruta al edificio 5 muestra que no hay conexión; no agrega una solicitud imposible a la cola. Escribir `2abc`, un número fuera de rango o una opción desconocida obliga a corregir la entrada.

## 5. POO y DAO: decidir quién hace cada trabajo

[Biblioteca.h](include/servicios/Biblioteca.h) compone el DAO, mapa y estructuras de la sesión. No lee del teclado ni imprime menús. [Consola.h](include/interfaz/Consola.h) presta esa interfaz sin decidir cómo guardar los libros.

El DAO existente administra `Libro`, valida IDs únicos y serializa títulos con espacios y comillas. [AlmacenCatalogo.h](include/datos/AlmacenCatalogo.h) define dos maneras reales de conservarlo:

```cpp
class AlmacenCatalogo {
public:
    virtual ~AlmacenCatalogo() = default;
    virtual LibroDAO cargar() const = 0;
    virtual void guardar(const LibroDAO& dao) = 0;
};
```

`AlmacenMemoria` sirve al modo de demostración. `AlmacenArchivo` sirve al modo persistente. El servicio trabaja con una referencia a la base, y `virtual` selecciona la implementación. Así aparecen herencia y polimorfismo por una diferencia concreta del programa.

## 6. Propiedad, referencias y punteros

En [main.cpp](src/main.cpp), un `unique_ptr<AlmacenCatalogo>` es dueño de la implementación elegida. `Biblioteca` recibe una referencia; `Consola` recibe referencias a la biblioteca y a los streams. Los objetos se declaran en ese orden y se destruyen en el orden inverso:

```cpp
Biblioteca biblioteca(*almacen);
Consola consola(biblioteca, cin, cout);
consola.ejecutar();
```

El almacén debe vivir durante toda la vida de la biblioteca. `*almacen` accede al objeto administrado; no transfiere su propiedad. Los parámetros `const Libro&` y `const string&` consultan sin copiar argumentos. Cuando guardamos un `Libro` **como miembro por valor** de una solicitud, sí creamos una copia independiente.

Imagina que el DAO es el cajón de fichas, las referencias son otras etiquetas sobre sus cajas y los punteros son tarjetas con direcciones. La vista ordenada contiene tarjetas; una solicitud contiene su propia ficha. Cambiar el cajón puede invalidar tarjetas prestadas, mientras que la ficha copiada sigue existiendo.

## 7. Vector de punteros y búsqueda binaria

[catalogoOrdenado()](src/servicios/Biblioteca.cpp) crea una vista de lectura:

```cpp
vector<const Libro*> vista;
for (const Libro& libro : dao.todos()) {
    vista.push_back(&libro);
}
sort(vista.begin(), vista.end(), [](const Libro* izquierdo, const Libro* derecho) {
    return izquierdo->id < derecho->id;
});
```

No se copian libros ni se reordena el DAO: se ordenan sus direcciones. Después `buscar()` construye los IDs de esa misma vista y llama a la búsqueda binaria del curso:

```cpp
const auto posicion = binaria(ids, id);
if (!posicion) {
    return nullptr;
}
return vista.at(*posicion);
```

La condición indispensable es que los IDs estén ordenados. `optional<size_t>` distingue la ausencia de un índice válido, incluido el cero. El puntero devuelto observa un libro del DAO; deja de poder usarse después de agregar, eliminar, renombrar o deshacer un cambio, porque sustituimos el catálogo completo. La consola lo usa inmediatamente; las entregas copian el libro antes de cualquier modificación posterior.

La búsqueda binaria cuesta O(log n), pero preparar la vista en cada consulta cuesta O(n log n). Esta implementación enseña la conexión entre ordenamiento, vista y búsqueda; no presenta la consulta completa como O(log n).

## 8. Structs y cola de entregas

[Entrega.h](include/modelos/Entrega.h) reúne una ficha y dos posiciones del mapa:

```cpp
struct Entrega {
    Libro libro;
    size_t origen;
    size_t destino;
};
```

Antes de encolar, el servicio comprueba que el libro exista y que haya ruta. Una `queue<Entrega>` atiende por orden de llegada: primero entra, primero sale. Consultar pendientes recorre una copia, para que mirar no equivalga a consumir solicitudes.

Al atender una entrega se prepara un `EntregaResuelta`, se registra el resultado y después se retira el frente de la cola. El resultado devuelto contiene datos propios; no es una referencia a un elemento que acabamos de eliminar.

## 9. Grafo, BFS y Dijkstra

[MapaCampus.cpp](src/servicios/MapaCampus.cpp) mantiene un `array<string, 6>` con nombres y un `Grafo` de listas de adyacencia. Las posiciones del arreglo son los IDs de los vértices. Una conexión bidireccional se guarda como dos aristas dirigidas.

| Conexión | Minutos |
| --- | --- |
| 0 Biblioteca ↔ 1 Laboratorio | 4 |
| 0 Biblioteca ↔ 2 Ingeniería | 1 |
| 2 Ingeniería ↔ 1 Laboratorio | 1 |
| 1 Laboratorio ↔ 3 Administración | 3 |
| 2 Ingeniería ↔ 3 Administración | 6 |
| 3 Administración ↔ 4 Residencias | 2 |

El anexo 5 está aislado. BFS indica qué edificios son alcanzables; no calcula el menor tiempo cuando los pesos difieren. Dijkstra usa una cola de prioridad y mejora costos conocidos:

```cpp
if (candidato < resultado.distancias.at(arista.destino)) {
    resultado.distancias.at(arista.destino) = candidato;
    resultado.anteriores.at(arista.destino) = actual;
    cola.push({candidato, arista.destino});
}
```

La función `caminosMinimos()` añade predecesores al algoritmo existente. `dijkstra()` conserva la API anterior de solo distancias para los otros ejemplos del curso. En el proyecto reconstruimos el camino siguiendo predecesores desde el destino y finalmente lo invertimos:

```cpp
while (actual != origen) {
    ruta.paradas.push_back(actual);
    const auto anterior = resultado.anteriores.at(actual);
    if (!anterior) {
        throw logic_error("La ruta tiene un enlace anterior invalido");
    }
    actual = *anterior;
}
```

Para ir de 0 a 4, el camino por 2 mejora el acceso directo a 1: cuesta `1 + 1 + 3 + 2 = 7`. La ausencia de ruta se representa con `nullopt`; ir del mismo edificio a sí mismo cuesta cero. Dijkstra requiere pesos no negativos; el grafo rechaza pesos negativos y comprueba el desbordamiento al sumar.

## 10. Lista doble y vector de mensajes

El historial combina dos estructuras:

```cpp
vector<string> eventos;
ListaDoble orden;
```

El vector es dueño de los mensajes. Cada nodo de la lista guarda el índice de un mensaje, no un puntero hacia el vector. Si el vector realoca al crecer, los índices siguen sirviendo porque anexamos mensajes sin reordenarlos ni borrarlos. La lista enlaza ese orden y permite recorrerlo en ambos sentidos.

```text
Lista: [0] <-> [1] <-> [2]
        |       |       |
Vector: mensaje mensaje mensaje
```

La lista del curso libera sus nodos en su destructor e impide copias de propietarios. No se devuelve ningún nodo a la consola. `historial()` reúne copias de los mensajes siguiendo los índices; así la interfaz no necesita conocer los enlaces internos.

## 11. Pila, cambios candidatos y guardado

Un cambio trabaja sobre una copia del DAO. Si no cumple las reglas, no llega al guardado. Al confirmar, la pila conserva el estado anterior; si falla el almacén, se retira esa nueva instantánea y no se sustituye el catálogo:

```cpp
deshacerCambios.push(dao);
try {
    almacen.guardar(candidato);
} catch (...) {
    deshacerCambios.pop();
    throw;
}
dao = move(candidato);
```

Deshacer guarda primero el estado anterior, lo instala y solo entonces retira la cima. La pila es LIFO: el último cambio se revierte primero. Las instantáneas completas son fáciles de seguir, pero su memoria crece con el tamaño del catálogo y la cantidad de cambios; para una aplicación grande convendrían comandos inversos o un registro transaccional.

[AlmacenCatalogo.cpp](src/datos/AlmacenCatalogo.cpp) escribe una instantánea en `.tmp`, comprueba el cierre, mueve el catálogo anterior a `.bak` y coloca el nuevo archivo. Si falla el reemplazo, intenta restaurar el anterior. Si una interrupción deja solo `.bak`, la siguiente carga lo lee. Un catálogo corrupto se rechaza y se conserva para revisarlo.

El formato aprovecha la serialización del DAO:

```text
2
10 "Fundamentos de C++"
20 "Libro con \"comillas\""
```

La primera línea indica cuántos libros siguen. Hay un límite de 10 000, IDs positivos sin repetición y títulos con texto, sin caracteres de control y de hasta 200 bytes. El reemplazo con respaldo es para una aplicación local de un solo proceso; no sustituye transacciones de una base de datos ni garantiza durabilidad ante pérdida de energía. `.tmp`, `.bak` y el catálogo generado no se suben al repositorio.

## 12. Entrada, errores y comprobación

[Consola.cpp](src/interfaz/Consola.cpp) usa `getline` para no mezclar lecturas parciales. Después convierte la línea a entero y comprueba que no queden caracteres. EOF termina la sesión incluso si aparece a mitad de una operación; ningún cambio incompleto se confirma. Los errores de validación o guardado se presentan y permiten seguir usando el menú.

[Autocomprobacion.cpp](tests/Autocomprobacion.cpp) verifica búsqueda en catálogo vacío y ordenado, rutas y destino aislado, cola FIFO, pila LIFO, historial inverso, independencia de las solicitudes, recuperación tras un fallo simulado de guardado, entrada inválida y EOF. Usa condiciones que siguen activas con `NDEBUG`.

```bash
./build/biblioteca.exe --self-test
```

El resultado correcto termina con código 0; un fallo indica el caso y devuelve 1. Para comprobar persistencia manualmente, ejecuta sin `--demo`, agrega un título con comillas, cierra y abre otra vez: el catálogo debe conservarlo.

## 13. Costos y cómo seguir estudiando

| Operación | Costo aproximado |
| --- | --- |
| Preparar la vista ordenada | O(n log n) |
| Búsqueda binaria, con IDs ya preparados | O(log n) |
| Copiar una instantánea para deshacer | O(n) más los textos |
| Anexar un índice al historial | O(1) |
| Consultar todo el historial | O(h) más la copia de textos |
| Consultar pendientes | O(p) más la copia de solicitudes |
| BFS | O(V + E) |
| Dijkstra con entradas repetidas en la cola | O((V + E) log(V + E)) |
| Reconstruir el camino | O(V) como máximo |

La carga del DAO verifica duplicados mediante consultas lineales, por lo que puede costar O(n²). El proyecto prioriza leer y conectar sus piezas; cada costo corresponde a una decisión que puedes cambiar con una necesidad concreta.

Para practicar, cambia un peso y predice la ruta, añade una conexión al anexo, prueba IDs al principio y al final, o amplía la comprobación con otro error de entrada. Antes de agregar una estructura nueva, explica qué operación mejoraría. Un árbol o una tabla hash pueden servir para otro tipo de consulta, pero el programa ya utiliza cada estructura actual en una operación real.
