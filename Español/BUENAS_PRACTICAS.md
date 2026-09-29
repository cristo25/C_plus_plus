# Revisión de buenas prácticas

## Correcciones aplicadas

- **Operaciones fuera de assert.** Crear, guardar, cargar, eliminar, insertar, depositar y retirar se ejecutan en condiciones normales. `assert` queda para comprobar invariantes; desactivarlo no elimina operaciones del ejemplo.
- **Validación completa de entrada.** Se rechazan nombres vacíos o compuestos solo por espacios, edades fuera de 0 a 130 y líneas como `20abc`. Los errores de usuario se manejan con condiciones y mensajes, no con assert.
- **Límite coherente del DAO.** Una sola constante establece el máximo de 10 000 libros en creación y carga. Una carga inválida conserva el catálogo anterior. Se rechazan IDs inválidos o duplicados y títulos vacíos o con saltos de línea.
- **Namespaces en headers.** Cada header contiene sus declaraciones dentro de `namespace curso`. `using namespace std;` queda dentro de él, después de los includes. Los ejemplos `.cpp` importan los namespaces que usan.

## Prácticas comprobadas

- Estado privado donde corresponde, consultas `const`, composición y herencia con una relación adecuada.
- Destructor virtual en bases polimórficas y `override` en sus implementaciones.
- RAII con `unique_ptr`, objetos por valor y archivos administrados por sus flujos.
- Listas con destructor y copia deshabilitada, evitando compartir accidentalmente la propiedad de nodos. Sus recorridos y eliminaciones contemplan lista vacía, inicio, final y único nodo.
- Headers con guardas, includes fuera del namespace y funciones libres `inline` cuando se definen en headers.
- Comprobación de apertura, escritura, cierre y lectura de archivos; demostraciones por anexado que conservan el contenido anterior.
- Comprobación de contenedores vacíos antes de acceder a pila o cola; documentación de iteradores invalidados y precondiciones de búsqueda binaria.
- Ordenamientos probados con vacíos, repetidos, negativos y entradas ordenadas; grafos con ciclos, vértices aislados y rechazo de pesos negativos.

## Decisiones didácticas y límites

`using namespace std;` simplifica los ejemplos por preferencia del curso. En programas grandes puede producir colisiones: limita sus imports a un scope concreto cuando sea necesario. Los headers de este curso evitan poner esa directiva en el namespace global.

Los atributos públicos de la primera clase permiten presentar objetos antes de enseñar encapsulamiento. `new/delete` se conserva solo para estudiar memoria manual y enlaces. No representa la recomendación habitual para aplicaciones; usa contenedores estándar y RAII cuando cubran la necesidad.

Los cálculos numéricos de las primeras lecciones trabajan con los datos pequeños indicados; no son utilidades generales para todos los valores de int. ABB y DFS recursivos pueden agotar la pila en grandes profundidades. Quick sort usa un pivote didáctico con peor caso O(n²). El DAO tiene consultas lineales y un diario que crece por anexado; no ofrece concurrencia ni garantías de recuperación ante fallos de almacenamiento.

## Legibilidad del curso

Los controles if, else, for, while y do while usan llaves y bloques multilínea; cada instrucción ocupa su propia línea. Las funciones también tienen sus cuerpos separados.

Las lecciones individuales y la programación estructurada no usan assert. Se conserva únicamente en los integradores de comprobación de EDD y en el integrador del DAO. Los errores de entrada se validan con condiciones normales. Los tres bloques enseñan const y headers explícitamente; las variables que cambian conservan su mutabilidad.
