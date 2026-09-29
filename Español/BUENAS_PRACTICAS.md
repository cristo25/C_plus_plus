# Buenas prácticas en C++

Cuando programamos, también escribimos para quien leerá el código después. En un trabajo compartimos proyectos con otras personas y podemos volver a ellos meses más tarde. Vamos a cuidar los nombres, las reglas y el orden para que podamos entenderlos sin adivinar.

## Elegimos nombres que expliquen los datos

Con `saldoCentavos` sabemos qué guardamos y en qué unidad. Con `x` tendríamos que buscar una explicación. También nombramos las funciones por su tarea: `calcularPromedio` o `buscarLibro`. En un equipo acordamos un criterio para reconocer los datos en todos los archivos.

```cpp
const int cantidadProductos = 3;
const int precioUnitarioCentavos = 1250;
const int totalCentavos = cantidadProductos * precioUnitarioCentavos;
```

Aquí guardamos dinero en centavos enteros para evitar pequeñas diferencias de redondeo al calcular con decimales.

## Dejamos visibles los bloques

Separamos las instrucciones en líneas y usamos sangría dentro de las llaves. Así vemos qué depende de una condición y qué se repite. Durante una revisión podemos detectar una instrucción fuera de lugar sin descifrar primero el formato.

```cpp
if (saldoCentavos >= precioCentavos) {
    saldoCentavos -= precioCentavos;
    cout << "Compra realizada\n";
}
```

## Damos un valor inicial y protegemos lo que no cambia

Antes de leer una variable le damos un valor, como `int cantidad = 0;`. Si un dato debe mantenerse igual, usamos `const`: dejamos escrita nuestra intención y C++ nos ayuda a respetarla.

Para consultar un vector sin copiarlo usamos `const vector<int>&`. Podemos imaginar que prestamos una etiqueta de lectura para el mismo cajón. Si necesitamos cambiarlo, recibimos una referencia que permita escribir y lo dejamos claro en el nombre de la función.

## Comprobamos los datos antes de usarlos

Podemos recibir letras donde esperamos un número, un nombre vacío o una solicitud de retirar más dinero del disponible. Un archivo también puede faltar. Revisamos estas situaciones antes de calcular o cambiar datos.

Si no podemos completar una operación, mostramos qué ocurrió y conservamos la información anterior cuando sea posible. En una aplicación de trabajo, esto evita que una entrada equivocada dañe datos válidos.

## Damos una tarea clara a cada función

Separamos leer, calcular y guardar. Así podemos cambiar una parte sin revisar todo el programa, o probar un cálculo sin abrir un menú completo. Creamos clases y funciones cuando ayudan a ordenar una responsabilidad concreta.

Si una clase controla una alcancía, guardamos su saldo como dato privado y ofrecemos operaciones para depositar o retirar. Cada operación comprueba sus reglas. Para reunir partes usamos composición: una biblioteca tiene un catálogo. Para describir una versión particular usamos herencia: una bicicleta eléctrica es una bicicleta.

## Repartimos el proyecto entre headers y archivos cpp

En el `.h` anunciamos qué funciones y clases podemos usar; en el `.cpp` escribimos sus pasos. Podemos imaginar el header como un menú y el cpp como la cocina. Esto permite que un compañero use una función sin leer todos sus detalles.

Incluimos el `.h` y compilamos juntos los `.cpp` necesarios. Con `#ifndef`, `#define` y `#endif` evitamos procesar dos veces un header al compilar un mismo archivo. Con `namespace` agrupamos nombres como en una carpeta.

En los `.cpp` del curso usamos `using namespace std;`. Dentro de los headers lo mantenemos en nuestro espacio de nombres, para no cambiar los nombres disponibles en todos los archivos que incluyan ese header.

## Dejamos claro quién libera cada objeto

Primero revisamos si basta una variable normal, un arreglo o un vector. Si necesitamos crear un objeto aparte durante la ejecución, podemos usar `unique_ptr` para darle un único responsable de liberarlo. Un puntero obtenido con `get()` solo presta su dirección; no recibe esa responsabilidad.

Aprendemos `new` y `delete` para entender cómo reservamos y liberamos memoria. Después podemos usar objetos que hagan la limpieza al terminar su vida. A esta idea la llamamos RAII: relacionamos la duración de algo que usamos, como un archivo abierto, con el objeto que lo administra. Así se realiza la limpieza incluso cuando salimos por un error.

Una dirección no mantiene vivo su destino. Si liberamos una caja, dejamos de usar todas las tarjetas que la señalaban; no se ponen en `nullptr` por sí solas.

## Elegimos una estructura según la tarea

Para guardar y recorrer datos podemos empezar con un vector. Para atender por llegada usamos una cola; para volver sobre lo último que hicimos, una pila. Para unir lugares mediante caminos usamos un grafo. Elegimos por las operaciones que necesitamos.

Primero construimos listas y ordenamientos para entender sus pasos. En una aplicación de trabajo también podemos usar las herramientas que ya ofrece C++ cuando resuelven la necesidad. Consideramos cuántos datos habrá: recorrer diez elementos y recorrer un millón requieren distinto trabajo.

## Explicamos las decisiones y probamos los límites

Un comentario nos ayuda a entender por qué elegimos algo o qué detalle debemos cuidar. En el curso también usamos analogías para conectar una instrucción nueva con una idea conocida. Actualizamos los comentarios cuando cambia el programa.

Probamos datos vacíos, números repetidos, entradas incorrectas y límites permitidos. Una lista debe quedar vacía al quitar su único nodo; una búsqueda debe avisar si no encuentra nada. Compilamos con advertencias y leemos sus mensajes. En un equipo también pedimos otra revisión: alguien puede notar un error que pasamos por alto.

Podemos profundizar con las [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
