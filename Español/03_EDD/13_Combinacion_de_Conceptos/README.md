# Combinar conceptos: del cajón a un inventario con vistas

Saber qué es un puntero no dice todavía dónde conviene usarlo. Aquí vamos a partir de una necesidad y cambiar la representación cuando aparezca una necesidad nueva. Conservamos `Producto`, la clase del [tema de headers de POO](../../02_POO/08_Headers/Producto.h), para concentrarnos en cómo se combinan los conceptos.

Antes de empezar, ejecuta [referencias](../../01_Programacion_Estructurada/06_Funciones/02_Referencias/main.cpp) y [punteros básicos](../../01_Programacion_Estructurada/09_Punteros_Basicos/main.cpp). Sigue los pasos; cada `main.cpp` tiene la explicación junto a sus operaciones. Termina con el [integrador de esta carpeta](main.cpp).

## Ruta

| Paso | Programa | Decisión que aprendemos |
| --- | --- | --- |
| 1 | [Arreglo de clases](01_Arreglo_de_Clases/main.cpp) | Guardar objetos completos |
| 2 | [Arreglo de structs con clases](02_Arreglo_de_Structs_con_Clases/main.cpp) | Reunir un objeto y sus existencias |
| 3 | [Arreglo de punteros](03_Arreglo_de_Punteros/main.cpp) | Separar una tarjeta de su destino |
| 4 | [Vector de punteros](04_Vector_de_Punteros/main.cpp) | Crear una vista que crece sin copiar productos |
| 5 | [Matriz de punteros](05_Matriz_de_Punteros/main.cpp) | Organizar vistas por filas y casillas |
| 6 | [Arreglo de nodos enlazados](06_Arreglo_de_Nodos/main.cpp) | Separar ubicación física y orden lógico |
| 7 | [Vector de unique_ptr](07_Vector_de_Unique_Ptr/main.cpp) | Dar un propietario a cada objeto dinámico |
| 8 | [Clase con nodos struct](08_Clase_con_Nodos/main.cpp) | Encapsular una cadena y sus operaciones |
| 9 | [Vector de clases con nodos](09_Vector_de_Clases_con_Nodos/main.cpp) | Reunir listas y distinguir qué se mueve |

## 1. ¿Qué guarda realmente un arreglo de clases?

Queremos tres productos. `array<Producto, 3>` es un cajón con tres compartimentos: cada uno contiene un objeto completo con su nombre y precio. La clase define cómo es cada objeto; el arreglo define cuántos caben y cómo recorrerlos. No hace falta una dirección para todas las operaciones: una referencia al compartimento basta para consultar el producto.

```cpp
const Producto& producto = productos.at(0);
cout << producto.consultarNombre() << "\n";
```

La referencia no crea un producto extra. `at(0)` comprueba el índice; los índices empiezan en cero. Al terminar la vida del arreglo termina la de los objetos que contiene.

## 2. ¿Cómo agrego datos que pertenecen al mismo registro?

Ahora necesitamos la cantidad disponible. Un `Registro` contiene un `Producto` y un entero. El arreglo contiene registros; cada registro contiene un objeto de una clase. Son capas de composición, no conceptos rivales.

```cpp
struct Registro {
    Producto producto;
    int cantidad;
};

void recibirUnidad(Registro& registro) {
    if (registro.cantidad < 0 || registro.cantidad == numeric_limits<int>::max()) {
        throw invalid_argument("Cantidad invalida");
    }
    ++registro.cantidad;
}
```

`registros.at(0).producto` llega al objeto y `registros.at(0).cantidad` llega al número. Pasar el registro por referencia modifica la ficha original. Pasarlo por valor modificaría otra ficha. `struct` tiene acceso público por defecto; `class`, privado. Ambas pueden tener métodos y contener objetos de la otra.

## 3. ¿Qué cambia cuando el compartimento guarda una dirección?

`array<int*, 3>` contiene tres tarjetas, no tres enteros. Las cajas con los enteros están fuera del cajón. `direcciones.at(0) = &azul` cambia una tarjeta; `*direcciones.at(0) = 7` sigue la tarjeta y cambia el entero de destino. Antes de seguir una tarjeta hay que saber que su destino existe.

```text
cajón de tarjetas                   cajas originales
casilla 0: dirección de rojo ------> rojo: 2
casilla 1: dirección de azul ------> azul: 5
casilla 2: nullptr                   sin destino
```

La forma tradicional `int* tarjetas[3]` también es un arreglo de tres punteros. Usamos `array` porque conserva el tamaño y ofrece `at()` y `size()`. En una declaración, el `*` forma parte del tipo del puntero; en una expresión, sigue una dirección. Declara cada variable en su propia línea: en `int* a, b;` solo `a` sería puntero.

## 4. ¿Cómo selecciono productos sin copiarlos?

El inventario conserva los objetos. `vector<Producto*>` guarda una selección de sus direcciones. Puede crecer, omitir productos o mostrar uno varias veces. Tiene sentido cuando quiero una vista de datos que ya existen, no crear otros productos.

La función `seleccionar(Producto*& seleccion, Producto& nuevoDestino)` necesita cambiar la tarjeta del llamador. Por eso el primer parámetro es una referencia a un puntero. El segundo es un alias del nuevo producto: `&nuevoDestino` obtiene su dirección. Con `Producto* seleccion` solo cambiaríamos una copia de la tarjeta.

Aquí el propietario es un `array` local que permanece en su sitio. Realocar el vector de tarjetas no realoca los productos de ese arreglo. Sin embargo, una referencia a **una casilla del vector** sí se invalidaría al realocar: hay que distinguir la tarjeta guardada de la caja a la que apunta.

## 5. ¿Qué significa anidar arreglos de punteros?

Una vitrina tiene dos filas con dos casillas cada una:

```cpp
array<array<Producto*, 2>, 2> casillas{};
```

Se lee de dentro hacia fuera: `Producto*` es una tarjeta; `array<Producto*, 2>` es una fila de dos tarjetas; el arreglo exterior tiene dos filas. En esta declaración, `{}` inicializa todos los punteros con `nullptr`. En el programa asignamos las cuatro casillas, incluyendo una con `nullptr`. `casillas.at(fila).at(columna)` elige una tarjeta y `*casillas.at(fila).at(columna)` llega a un producto, siempre que la tarjeta tenga un destino válido.

Una matriz así no es `Producto**`. Un doble puntero describe dos niveles de direcciones; un arreglo anidado contiene las filas físicamente. Tampoco contar casillas ocupadas equivale a contar objetos únicos: dos casillas pueden mostrar el mismo producto.

`const array<Producto*, 2>` impide reasignar sus tarjetas, pero permite modificar sus destinos. `array<const Producto*, 2>` permite cambiar las tarjetas y ofrece acceso de lectura a sus destinos. Puedes combinar ambos `const`.

## 6. ¿Puede un nodo vivir dentro de un arreglo?

Sí. El nodo contiene el dato y un enlace:

```cpp
struct Nodo {
    Producto producto;
    Nodo* siguiente = nullptr;
};
```

El arreglo es propietario de los nodos. `siguiente` solo dice qué nodo visitar después. Si enlazamos `0 -> 2 -> 1`, el recorrido lógico cambia aunque los compartimentos físicos mantengan su posición. Primero elegimos el nodo inicial, después leemos su dato y seguimos su enlace; repetimos hasta `nullptr`.

El límite de visitas detecta un ciclo en este ejemplo de tres nodos. No se llama a `delete`: los nodos son elementos del arreglo. Copiar el arreglo copiaría las direcciones sin reconstruirlas; los enlaces de la copia seguirían apuntando a los nodos originales. Esta estructura enlazada necesita conservar la ubicación y la vida de su arreglo, o reconstruir los enlaces.

## 7. ¿Quién destruye un objeto creado dinámicamente?

`unique_ptr<Producto>` es una tarjeta con responsabilidad: su propietario destruye el objeto al retirarse. `make_unique` crea el producto; `get()` presta una dirección para observarlo; `move` permite transferir la responsabilidad. Un puntero ordinario obtenido con `get()` no recibe esa propiedad.

`vector<unique_ptr<Producto>>` puede reubicar sus elementos sin mover los productos administrados. En el ejemplo forzamos la realocación con una capacidad mayor y verificamos que la dirección del producto sigue siendo la misma. Después retiramos el observador antes de borrar a su propietario.

En `vector<Producto>`, los productos son los elementos del vector: realocar invalida sus referencias y punteros. `reserve` solo evita nuevas realocaciones mientras no se supere la capacidad; no hace eternas las direcciones. Mover propietarios tampoco protege contra `erase`, `reset`, reemplazar un propietario o destruir la estructura: esas operaciones pueden destruir el destino.

## 8. ¿Qué aporta la clase que administra los nodos?

[Estante.h](Estante.h) oculta el primer propietario y los enlaces. Dentro de cada nodo hay un `Producto` y un `unique_ptr<Nodo>` que administra el siguiente. La cadena queda así:

```text
Estante
  inicio: unique_ptr ---> Nodo [Producto | siguiente: unique_ptr]
                                             |
                                             v
                         Nodo [Producto | siguiente: nullptr]
```

`agregar()` crea un nodo y lo pone delante de la cadena: el orden de inserción se invierte. `primero()` y `siguienteNodo()` prestan `const Nodo*`; `consultarProducto()` presta `const Producto&`. Las consultas pueden leer sin cambiar los enlaces. El `friend` da a `Estante` acceso al enlace privado de su nodo para insertar y vaciar; los demás usuarios usan las consultas públicas.

La clase impide copias para no duplicar propietarios. Permite movimiento porque transferir la cadena no necesita duplicar los nodos. `vaciar()` retira un nodo por vez, evitando una destrucción recursiva larga; la asignación por movimiento vacía primero el contenido anterior y protege contra moverse sobre sí misma. El total usa `long long` y comprueba el desbordamiento. Estas decisiones mantienen coherente la propiedad, no cambian el objetivo del ejercicio.

Las funciones están definidas dentro de la clase y son `inline`; incluir este header no necesita un `Estante.cpp` adicional. Las funciones de `Producto` están definidas en `Producto.cpp`, que sí debemos compilar y enlazar. El comando completo está en los comentarios de cada programa.

## 9. ¿Qué pasa al guardar estas clases en un vector?

Ahora `vector<Estante>` contiene objetos que a su vez poseen nodos con productos. Al realocar, el vector mueve los estantes. Un `Estante*` a una casilla anterior se invalida. El puntero a un nodo administrado conserva su destino porque el nodo no se reubicó: solo cambió de ubicación su propietario.

El ejemplo retira el puntero al estante antes de forzar la realocación y consulta nuevamente el estante mediante `at(0)`. Conserva un `const Nodo*` para demostrar que el nodo sigue en el mismo lugar. Antes de vaciar esa lista retira también ese observador. Una referencia no evita estos problemas: también necesita que su objeto siga vivo y en el mismo lugar.

## Integrador: ordenar la vista, conservar el inventario

El [main.cpp de esta carpeta](main.cpp) combina la cadena completa. Primero construye los propietarios; después recorre sus nodos y presta las direcciones a un vector. Ordena ese vector por precio y coloca algunas direcciones en una matriz. Las listas conservan su orden y sus productos: se ordenaron tarjetas, no objetos.

El resultado ordenado es `Lapiz: 100`, `Cuaderno: 300`, `Libro: 500`. El inventario suma 900 centavos. La matriz tiene tres casillas ocupadas, pero solo muestra dos productos distintos, porque repite el lápiz. La comprobación del integrador revisa esos datos y el orden de los enlaces originales.

```text
propietarios: vector<Estante> -> Estante -> Nodo -> Producto
                                           ^
vista: vector<const Nodo*> -----------------|
matriz: array<array<const Nodo*, 2>, 2> -----|
```

Una vista puede conservarse mientras los nodos estén vivos; borrar un nodo exige retirar sus observadores antes de volver a usarlos. Un `nullptr` en otra tarjeta no repara una dirección colgante. La matriz se destruye antes que los estantes porque fue declarada después en el mismo bloque.

## Cómo decidir la combinación

Parte de las operaciones: ¿quiero guardar datos, agrupar datos que cambian juntos, seleccionar objetos existentes, ordenar una vista o enlazar un recorrido? Elige después quién administra la vida de los objetos y quién solo observa. Por último decide qué puede cambiar cada función: un valor, el objeto original, el destino de un puntero o solo una consulta.

No se necesitan todas estas capas para todos los problemas. Una lista enlazada aquí sirve para estudiar nodos y propiedad; un inventario sencillo suele resolverse con un vector de registros. La lógica de combinar conceptos consiste en justificar cada capa y poder dibujar dónde está el dato, cómo llegas a él y cuándo deja de existir.
