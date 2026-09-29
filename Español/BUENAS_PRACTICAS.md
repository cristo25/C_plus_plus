# Buenas prácticas en C++

Cuando escribes un programa, piensa también en quien tendrá que leerlo después. En un proyecto de trabajo puede ser un compañero que corrige un error o agrega una función; también puedes ser tú al volver al código meses más tarde. Por eso te recomiendo acostumbrarte desde el principio a escribir código que se pueda entender, revisar y modificar con facilidad.

## Pon nombres que expliquen lo que guardas

Un nombre debe ayudar a entender el dato sin tener que buscar dónde se declaró. `saldoCentavos`, `cantidadProductos` y `precioUnitario` dicen más que `x`, `dato` o `valor2`. También conviene nombrar las funciones según lo que hacen: `calcularPromedio`, `buscarLibro` o `registrarAlumno`.

```cpp
const int cantidadProductos = 3;
const int precioUnitarioCentavos = 1250;
const int totalCentavos = cantidadProductos * precioUnitarioCentavos;
```

En este ejemplo, los nombres permiten reconocer la operación y la unidad del dinero. En un equipo, usar un mismo criterio para nombrar evita que cada archivo parezca pertenecer a un proyecto distinto.

## Haz que los bloques se puedan seguir a simple vista

Usa una sangría consistente y separa las decisiones, los ciclos y las funciones en bloques claros. Las llaves ayudan a ver qué instrucciones dependen de una condición. También facilitan agregar una instrucción sin dejarla por accidente fuera del bloque.

La razón es práctica: durante una revisión, alguien debe poder seguir el flujo del programa y detectar un error sin tener que descifrar primero su formato.

## Inicializa los datos y usa const cuando corresponda

Una variable numérica local necesita un valor antes de que puedas leerla. Declárala cerca de donde la uses y dale un valor inicial. Así reduces la posibilidad de utilizarla antes de haberle asignado un dato válido.

Si un dato no debería cambiar después de su declaración, usa `const`. Además de protegerlo, deja clara tu intención para quien lee el código. Para consultar un vector o una cadena sin copiarlos, puedes recibirlos mediante `const vector<int>&` o `const string&`. Una función que sí necesita modificar esos datos debe permitirlo en su firma.

## Revisa los datos antes de usarlos

Un usuario puede escribir texto donde esperas un número, dejar un nombre vacío o pedir una operación que no tiene sentido. Un archivo puede faltar o contener datos incompletos. Comprueba esas situaciones antes de hacer cálculos o cambiar el estado del programa.

Por ejemplo, un retiro debe comprobar que la cantidad sea positiva y que exista saldo suficiente. Si una operación falla, informa qué ocurrió y conserva los datos anteriores cuando sea posible. En una aplicación real, una entrada equivocada debe tener una respuesta prevista.

## Divide el trabajo en funciones con una tarea clara

Leer datos, calcular un resultado y guardarlo son responsabilidades diferentes. Separarlas permite cambiar una parte sin tener que revisar todo el programa. También facilita probar un cálculo con otros datos o reutilizarlo desde otra pantalla.

El nombre de una función debería describir su tarea. Si cuesta explicar qué hace, revisa si está acumulando demasiadas responsabilidades. Evita también crear clases y capas que todavía no resuelven una necesidad concreta.

## Protege el estado de las clases

Cuando una clase controla datos como un saldo o un inventario, conviene mantenerlos privados y ofrecer operaciones que comprueben las reglas antes de modificarlos. Esto ayuda a conservar un estado válido aunque distintas partes de la aplicación usen el mismo objeto.

Los métodos de consulta pueden ser `const`. Para relacionar clases, considera primero la composición: una biblioteca tiene un catálogo. Usa herencia cuando la relación entre los tipos lo justifique y tenga sentido utilizar un objeto derivado mediante la interfaz de su base.

## Separa las declaraciones de la implementación

Un header permite consultar qué operaciones ofrece una clase o un grupo de funciones. El archivo `.cpp` contiene sus definiciones. En proyectos con varios archivos, esta separación ayuda a trabajar sobre una implementación sin obligar al lector a recorrerla para conocer su interfaz.

Incluye el `.h` y compila los `.cpp` que correspondan. Usa guardas de inclusión y declara los nombres dentro de un namespace cuando necesites agruparlos. Evita colocar `using namespace std;` en el ámbito global de un header: afectaría también a todos los archivos que lo incluyan. En archivos `.cpp`, sigue la convención del proyecto y presta atención a posibles nombres que coincidan.

## Deja clara la propiedad de la memoria

Antes de reservar memoria, pregúntate si basta con una variable normal o un contenedor como `vector`. Esas opciones ya administran la vida de sus datos. Si necesitas un objeto dinámico con un único propietario, `unique_ptr` ayuda a liberarlo automáticamente cuando termina su vida.

Aprender `new` y `delete` sirve para entender cómo funciona la memoria, pero administrarla manualmente obliga a cuidar cada salida de una función. Con RAII, un objeto administra el recurso y su destructor lo libera, incluso cuando se sale por una excepción. Esto reduce los caminos en los que podrías olvidar la liberación.

Un puntero que solo consulta un objeto no se encarga de destruirlo. Comprueba que el objeto siga vivo antes de usar ese puntero; liberar al propietario deja inválidos a sus observadores.

## Elige estructuras según las operaciones que necesitas

Si necesitas guardar datos y recorrerlos, un vector suele ser un buen punto de partida. Si el trabajo se atiende por llegada, una cola expresa ese orden. Para recuperar información por una clave, puede convenir una tabla hash. La elección depende de cómo vas a insertar, buscar, recorrer y eliminar.

En un proyecto real también importan la cantidad de datos y la memoria disponible. Un algoritmo cómodo para diez elementos puede resultar costoso para un millón. Aprende a implementar listas y ordenamientos para entender sus mecanismos; cuando la biblioteca estándar cubra el requisito, puedes aprovechar sus implementaciones.

## Escribe comentarios que expliquen una decisión

Un comentario ayuda cuando cuenta por qué se eligió algo, qué condición debe respetarse o qué detalle podría causar un error. Repetir con palabras la instrucción que está justo debajo aporta poco.

```cpp
// Guardamos el precio en centavos enteros para evitar errores de redondeo.
const int precioCentavos = 1250;
```

Revisa los comentarios cuando cambies el código. Una explicación desactualizada puede confundir a quien intenta corregirlo.

## Comprueba más que el caso esperado

Antes de dar por terminado un programa, prueba también datos vacíos, valores repetidos, entradas incorrectas y límites permitidos, según corresponda. Una lista debe contemplar qué pasa al quitar su único nodo; una búsqueda debe poder indicar que no encontró el valor.

Compila con advertencias y revisa sus mensajes. En trabajo de equipo, comprobar los cambios y pedir una revisión ayuda a encontrar errores antes de que otra persona dependa de ese código.

Para profundizar en inicialización, uso de `const`, organización de headers y administración de recursos, puedes consultar las [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
