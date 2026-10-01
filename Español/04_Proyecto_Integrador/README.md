# Biblioteca y rutas del campus

Vamos a construir una biblioteca donde podamos registrar libros y organizar entregas entre edificios. Vamos a seguir cada operación desde el menú hasta sus datos, usando las clases y estructuras que ya estudiamos.

Los bloques de esta guía son fragmentos. Podemos abrir los archivos enlazados para seguir el programa completo. En la [versión inglesa](../../English/04_Integrated_Project/README.md) encontramos la misma aplicación.

## 1. Qué hace la aplicación

Vamos a elegir las operaciones desde este menú. Un ID es el número que identifica un libro; lo usamos para encontrarlo aunque cambie su título.

| Opción | Operación | Qué aplica |
| --- | --- | --- |
| 1 | Mostrar catálogo ordenado por ID | Vector de punteros de lectura y ordenamiento |
| 2 | Buscar un libro por ID | Búsqueda binaria sobre IDs ordenados |
| 3, 4, 5 | Agregar, renombrar y eliminar libros | POO, validación, DAO y archivos |
| 6 | Deshacer el último cambio del catálogo | Pila de copias para deshacer |
| 7 | Solicitar entrega de un libro | Fichas copiadas y cola por llegada |
| 8 | Atender la siguiente entrega | Grafo, Dijkstra y reconstrucción del camino |
| 9 | Consultar solicitudes pendientes | Copia de una cola sin consumirla |
| 10 | Ver historial hacia delante o atrás | Lista doble de índices y vector de mensajes |
| 11 | Mostrar mapa y edificios alcanzables | Vecinos de cada edificio y recorrido por capas |
| 0 | Cerrar la sesión | Destructores y liberación de recursos |

Guardamos el catálogo después de cada cambio confirmado. Las entregas pendientes, el historial y los cambios que podemos deshacer duran solo durante la sesión. Al pedir una entrega copiamos la ficha del libro: así conservamos el título que tenía al solicitarla, aunque después lo cambiemos o eliminemos del catálogo. Aquí simulamos entregas; no llevamos cantidades físicas de libros.

## 2. Organización del proyecto

Vamos a repartir el trabajo como en una biblioteca real: una persona atiende la ventanilla, otra cuida el catálogo y otra consulta el mapa. En el programa damos una responsabilidad a cada grupo de archivos.

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

En los `.h` anunciamos las clases y sus operaciones; en los `.cpp` escribimos sus pasos. Con `-Iinclude` indicamos dónde buscar nuestros headers. Reutilizamos [LibroDAO.h](../02_POO/09_DAO/LibroDAO.h), [ListaDoble.h](../03_EDD/03_Listas_Ligadas/02_Doblemente_Ligada/ListaDoble.h), [Busquedas.h](../03_EDD/10_Busqueda/Busquedas.h) y [Grafo.h](../03_EDD/08_Grafos/Grafo.h). Por eso mantenemos esta carpeta dentro del curso.

## 3. Compilar y ejecutar

Abrimos Git Bash en `Español/04_Proyecto_Integrador` y compilamos todos los archivos que forman esta aplicación:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/datos/AlmacenCatalogo.cpp src/servicios/MapaCampus.cpp src/servicios/Biblioteca.cpp src/interfaz/Consola.cpp tests/Autocomprobacion.cpp -o build/biblioteca.exe
./build/biblioteca.exe
```

En PowerShell creamos la carpeta con `New-Item -ItemType Directory -Force build`; después usamos el mismo comando de compilación. Ejecutamos desde la carpeta del proyecto para que `datos/catalogo.txt` quede en el lugar previsto. En Linux o macOS podemos omitir `.exe`.

```bash
./build/biblioteca.exe --demo
./build/biblioteca.exe --data "datos/mi_catalogo.txt"
./build/biblioteca.exe --self-test
./build/biblioteca.exe --help
```

Con `--demo` practicamos con tres libros en memoria. Con `--data` elegimos otro archivo. Con `--self-test` ejecutamos las comprobaciones y terminamos sin cambiar archivos. Elegimos un modo cada vez. Solo necesitamos C++17, sus bibliotecas estándar y los headers del curso.

En `main` recibimos las palabras del comando mediante `argv`. Para una ruta con acentos u otro alfabeto necesitamos que la terminal entregue ese texto en UTF-8, una forma de representar esos caracteres. Para empezar podemos usar la ruta relativa predeterminada; el programa no necesita funciones particulares de Windows.

## 4. Un recorrido para empezar

Vamos a ejecutar `--demo`. Con la opción 1 vemos los libros 10, 20 y 30 ordenados por ID; con la 2 buscamos el 20. Los datos originales no necesitan estar guardados en ese orden: preparamos una selección ordenada para consultarlos.

Con la opción 7 pedimos el libro 10 desde el edificio 0 hasta el 4. Consultamos la cola con 9 y atendemos con 8. Obtenemos:

```text
Biblioteca -> Ingenieria -> Laboratorio -> Administracion -> Residencias | 7 minutos
```

Después agregamos un libro con 3 y deshacemos el cambio con 6. Con 10 recorremos el historial en ambos sentidos. Si pedimos el edificio 5, avisamos que no hay ruta y no agregamos esa entrega a la cola. También probamos `2abc` o una opción desconocida: pedimos corregir el dato antes de continuar.

## 5. POO y DAO: decidir quién hace cada trabajo

En [Biblioteca.h](include/servicios/Biblioteca.h) reunimos las reglas de los libros y las entregas. En [Consola.h](include/interfaz/Consola.h) hacemos las preguntas y mostramos respuestas. Así podemos cambiar el menú sin cambiar la forma de guardar los libros.

Con el DAO concentramos crear, buscar, actualizar y eliminar fichas. Al guardar convertimos sus datos en texto; a ese paso lo llamamos serializar. En [AlmacenCatalogo.h](include/datos/AlmacenCatalogo.h) ofrecemos dos maneras de conservarlos:

```cpp
class AlmacenCatalogo {
public:
    virtual ~AlmacenCatalogo() = default;
    virtual LibroDAO cargar() const = 0;
    virtual void guardar(const LibroDAO& dao) = 0;
};
```

Con `AlmacenMemoria` los guardamos mientras dura la demostración. Con `AlmacenArchivo` los guardamos en disco. Pedimos `cargar` y `guardar` mediante una referencia a `AlmacenCatalogo`; gracias a `virtual`, usamos los pasos de la variante elegida. Aquí aplicamos la misma idea de los instrumentos: una petición común, distintas formas de resolverla.

## 6. Propiedad, referencias y punteros

Vamos a distinguir quién libera un objeto y quién solo lo consulta. En [main.cpp](src/main.cpp) un `unique_ptr<AlmacenCatalogo>` queda a cargo del almacén. Pasamos referencias a los objetos que necesitan usarlo. También pasamos `cin` y `cout` a la consola para indicar de dónde leer y dónde escribir:

```cpp
Biblioteca biblioteca(*almacen);
Consola consola(biblioteca, cin, cout);
consola.ejecutar();
```

Podemos imaginar cajas y etiquetas. `*almacen` nos lleva a la caja del almacén; la referencia entrega otra etiqueta para usar esa misma caja. Conservamos el almacén hasta después de terminar Biblioteca. Cuando recibimos `const Libro&` o `const string&` podemos leer el original sin copiarlo ni cambiarlo mediante esa referencia.

Los punteros de una vista son tarjetas con direcciones. Una entrega, en cambio, guarda una ficha propia. Si cambiamos el catálogo, las tarjetas anteriores pueden dejar de servir; la ficha copiada en la entrega conserva sus datos.

## 7. Vector de punteros y búsqueda binaria

Vamos a ordenar tarjetas para consultar libros sin cambiar su ubicación original. En [Biblioteca.cpp](src/servicios/Biblioteca.cpp) reunimos las direcciones de los libros en un vector y ordenamos esas direcciones por ID:

```cpp
vector<const Libro*> vista;
for (const Libro& libro : dao.todos()) {
    vista.push_back(&libro);
}
sort(vista.begin(), vista.end(), [](const Libro* izquierdo, const Libro* derecho) {
    return izquierdo->id < derecho->id;
});
```

La función pequeña escrita con `[]` compara dos libros y decide cuál va primero. La llamamos lambda. Después reunimos sus IDs en ese mismo orden y buscamos por mitades:

```cpp
const auto posicion = binaria(ids, id);
if (!posicion) {
    return nullptr;
}
return vista[*posicion];
```

La búsqueda devuelve `optional<size_t>`: una cajita que contiene una posición o está vacía. Una posición cero también cuenta como encontrada. Si está vacía devolvemos `nullptr`; si tiene un resultado, prestamos la dirección del libro correspondiente. La usamos antes de modificar el catálogo, porque agregar, borrar, cambiar un título o deshacer sustituye sus libros y deja sin validez las direcciones anteriores.

Una vez ordenados, descartamos aproximadamente la mitad de los libros posibles en cada paso. Si empezamos con 16, después quedan 8, luego 4, 2 y 1. Antes de buscar debemos reunir y ordenar las tarjetas; ese trabajo también cuenta.

## 8. Structs y cola de entregas

Vamos a preparar una ficha para cada entrega. En [Entrega.h](include/modelos/Entrega.h) guardamos una copia del libro y las posiciones de salida y llegada:

```cpp
struct Entrega {
    Libro libro;
    size_t origen;
    size_t destino;
};
```

Antes de agregarla comprobamos que el libro existe y hay un camino. Guardamos las fichas en `queue<Entrega>` y atendemos por llegada: primero entra, primero sale. A esa regla también la llamamos FIFO. Para mirar pendientes recorremos una copia de la cola; así no quitamos solicitudes al mostrarlas.

Al atender calculamos la ruta, guardamos el resultado y retiramos la primera solicitud. Devolvemos datos propios de la entrega resuelta, para poder seguir mostrándolos después de quitarla de la cola.

## 9. Grafo, BFS y Dijkstra

Vamos a representar los edificios con puntos y los caminos con conexiones. En [MapaCampus.cpp](src/servicios/MapaCampus.cpp) guardamos los nombres en un `vector<string>`; sus posiciones son los números de los edificios. En el grafo guardamos la lista de caminos que salen de cada edificio. Para permitir ida y vuelta agregamos una conexión en cada sentido.

| Conexión | Minutos |
| --- | --- |
| 0 Biblioteca ↔ 1 Laboratorio | 4 |
| 0 Biblioteca ↔ 2 Ingeniería | 1 |
| 2 Ingeniería ↔ 1 Laboratorio | 1 |
| 1 Laboratorio ↔ 3 Administración | 3 |
| 2 Ingeniería ↔ 3 Administración | 6 |
| 3 Administración ↔ 4 Residencias | 2 |

Dejamos el edificio 5 aislado. Con BFS exploramos por capas y vemos a cuáles podemos llegar. Para encontrar el viaje de menos minutos usamos Dijkstra: atendemos primero el candidato de menor costo conocido y actualizamos cuando aparece un camino mejor.

```cpp
if (candidato < resultado.distancias[arista.destino]) {
    resultado.distancias[arista.destino] = candidato;
    resultado.anteriores[arista.destino] = actual;
    cola.push({candidato, arista.destino});
}
```

En `anteriores` recordamos desde qué edificio llegamos a cada destino; a ese edificio previo también lo llamamos predecesor. `caminosMinimos` guarda costos y anteriores; `dijkstra` devuelve solo los costos. Reconstruimos la ruta desde el destino hacia atrás y después invertimos el resultado:

```cpp
while (actual != origen) {
    ruta.paradas.push_back(actual);
    const auto anterior = resultado.anteriores[actual];
    if (!anterior) {
        throw logic_error("La ruta tiene un enlace anterior invalido");
    }
    actual = *anterior;
}
```

De 0 a 4 pasamos por 2, 1 y 3: sumamos `1 + 1 + 3 + 2 = 7`. Cuando no hay ruta devolvemos `nullopt`, el resultado vacío. Ir del origen a sí mismo cuesta cero. No aceptamos minutos negativos y comprobamos que una suma no supere el mayor número que podemos guardar.

## 10. Lista doble y vector de mensajes

Vamos a guardar los mensajes y el orden en que los consultamos con dos estructuras:

```cpp
vector<string> eventos;
ListaDoble orden;
```

En el vector guardamos el texto de cada mensaje. En cada nodo de la lista guardamos su posición, como un número de página. Si el vector se muda a un espacio mayor, esos números siguen funcionando porque solo agregamos mensajes al final; no los borramos ni cambiamos su orden.

```text
Lista: [0] <-> [1] <-> [2]
        |       |       |
Vector: mensaje mensaje mensaje
```

Con la lista doble podemos pasar al mensaje siguiente o al anterior. Al terminar liberamos sus nodos. Cuando la consola pide el historial, le entregamos copias de los textos; no necesita cambiar ni conocer las flechas de la lista.

## 11. Pila, cambios candidatos y guardado

Vamos a preparar cada cambio en una copia del catálogo. Si cumple las reglas, guardamos una copia del estado anterior en una pila para poder deshacer. Si falla la escritura, retiramos esa nueva copia y conservamos el catálogo anterior:

```cpp
deshacerCambios.push(dao);
try {
    almacen.guardar(candidato);
} catch (...) {
    deshacerCambios.pop();
    throw;
}
swap(dao, candidato);
```

Con `try` intentamos guardar; con `catch` atendemos el error. `throw` vuelve a comunicarlo para que la consola lo muestre. Después de guardar usamos `swap`: `dao` recibe el catálogo nuevo y `candidato` se queda con el anterior. Si guardar falla, no hacemos ese intercambio y conservamos los libros que ya teníamos. Para deshacer seguimos el orden inverso de los cambios: último en entrar, primero en salir, también llamado LIFO. Cada copia ocupa espacio; con muchos libros y cambios podríamos guardar solo los datos necesarios para revertir cada operación.

En [AlmacenCatalogo.cpp](src/datos/AlmacenCatalogo.cpp) escribimos primero un archivo temporal `.tmp`. Después conservamos el anterior como respaldo `.bak` y colocamos el nuevo. Si falla ese cambio de archivos intentamos recuperar el anterior. Si al volver a abrir solo queda el respaldo, lo leemos. Si hay datos dañados, avisamos y conservamos el archivo para revisarlo.

El texto guardado tiene esta forma:

```text
2
10
Fundamentos de C++
20
Libro con "comillas"
```

En la primera línea indicamos cuántos libros siguen. Después usamos dos líneas por libro: su ID y su título. Así conservamos los espacios y las comillas del título. Permitimos hasta 10 000 libros, IDs positivos distintos y títulos con texto de hasta 200 bytes. Un byte es una unidad de memoria; algunas letras ocupan varios. Rechazamos saltos de línea y otros caracteres de control dentro del título. Usamos este guardado desde una sola ejecución del programa a la vez; para varias aplicaciones escribiendo juntas necesitaríamos coordinar sus cambios, por ejemplo mediante una base de datos. El respaldo ayuda a recuperar fallos, pero no garantiza conservar la última escritura ante un corte eléctrico.

## 12. Entrada, errores y comprobación

Vamos a leer cada respuesta completa con `getline` en [Consola.cpp](src/interfaz/Consola.cpp). Después usamos `istringstream`, de `<sstream>`, como un lector de ese texto: intentamos obtener un entero y comprobamos que no sobre ningún otro carácter. Así rechazamos `12abc`. Si termina la entrada, cerramos la sesión; a ese fin de entrada también lo llamamos EOF. No guardamos una operación que quedó a medias.

En [Autocomprobacion.cpp](tests/Autocomprobacion.cpp) probamos búsquedas, rutas, orden de entregas, deshacer, historial y entradas incorrectas. También simulamos un error al guardar para comprobar que conservamos los libros anteriores. Usamos condiciones normales que siguen activas al compilar la versión final.

```bash
./build/biblioteca.exe --self-test
```

Si todo coincide terminamos con 0; si algo falla mostramos el caso y devolvemos 1. Para probar archivos ejecutamos sin `--demo`, agregamos un título con comillas, cerramos y volvemos a abrir: debemos recuperar el mismo título.

## 13. Costos y cómo seguir estudiando

Vamos a pensar qué tareas requieren más pasos cuando crecen los datos. Por ejemplo, buscar entre diez libros suele llevar menos trabajo que hacerlo entre mil. En cada fila describimos lo que el programa necesita revisar o copiar.

| Operación | Qué trabajo realiza al crecer los datos |
| --- | --- |
| Preparar la vista ordenada | Reúne y ordena las direcciones de los libros. Con más libros hay más tarjetas que acomodar. |
| Buscar con los IDs ya ordenados | Descarta la mitad de los candidatos en cada paso. |
| Copiar para deshacer | Copia cada ficha y cada título; los títulos largos requieren más espacio. |
| Agregar un dato al historial | Ajusta unas pocas flechas, sin recorrer los mensajes anteriores. |
| Consultar el historial | Visita cada mensaje y copia su texto. |
| Consultar pendientes | Visita cada solicitud y copia sus datos. |
| BFS | Visita los edificios alcanzables y revisa los caminos que los unen. |
| Dijkstra | Revisa conexiones y mantiene una cola que permite elegir el candidato de menor costo. Más candidatos requieren más ajustes y pueden existir registros repetidos de un edificio. |
| Reconstruir el camino | Sigue los edificios de la ruta desde el destino; como máximo visita todos los edificios. |

Al cargar, comparamos cada libro con los que ya leímos para detectar números repetidos. Con muchos libros repetimos estas comparaciones muchas veces. Podemos empezar con pocos libros y observar cada paso; la [lección de complejidad](../03_EDD/01_Complejidad/main.cpp) da nombre a estas formas de crecer.

## 14. Práctica integradora

**Práctica.** Realiza una aplicación integradora de biblioteca y entregas.

- Organizar modelos, datos, servicios e interfaz en carpetas con .h y .cpp.
- Agregar, consultar, actualizar y eliminar libros con un DAO.
- Buscar ids mediante una vista ordenada y búsqueda binaria.
- Registrar el historial en una lista doble y los pendientes en una cola.
- Usar una pila para deshacer cambios del catálogo.
- Representar edificios como un grafo y calcular rutas con Dijkstra.
- Guardar los datos y recuperarlos al reiniciar.
- Validar entradas y conservar el catálogo cuando falle una escritura.

## 15. Para qué usamos cada biblioteca

Aquí reunimos las herramientas que aparecen en el proyecto. Podemos volver al ejemplo donde se presenta cada una antes de seguir una operación que la use.

| Biblioteca | Para qué la usamos |
| --- | --- |
| `<algorithm>` | Ordenamos datos con sort o invertimos su orden con reverse. |
| `<cstddef>` | Usamos size_t para contar elementos y representar posiciones no negativas. |
| `<exception>` | Recogemos errores mediante exception y leemos su mensaje con what(). |
| `<filesystem>` | Manejamos rutas, carpetas y cambios de nombre de archivos. |
| `<fstream>` | Leemos y guardamos archivos con ifstream y ofstream. |
| `<istream>` | Recibimos una fuente de lectura: puede ser teclado, archivo o texto en memoria. |
| `<limits>` | Consultamos con numeric_limits el mayor entero permitido antes de sumar. |
| `<memory>` | Usamos unique_ptr para liberar automáticamente el objeto que administra. |
| `<optional>` | Guardamos un resultado que puede faltar: optional tiene un valor o está vacío. |
| `<ostream>` | Recibimos un destino de escritura: pantalla, archivo o texto en memoria. |
| `<queue>` | Atendemos por llegada con queue o por importancia con priority_queue. |
| `<sstream>` | Leemos o escribimos texto en memoria como si fuera un archivo. |
| `<stack>` | Guardamos una pila: con stack sale primero lo último que entró. |
| `<stdexcept>` | Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido. |
| `<string>` | Guardamos y trabajamos con texto mediante string. |
| `<system_error>` | Consultamos si una operación de archivos falló mediante error_code. |
| `<utility>` | Usamos swap para intercambiar dos catálogos. |
| `<vector>` | Guardamos una colección que puede crecer con vector. |
