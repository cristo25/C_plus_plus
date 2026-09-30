# Algoritmos de ordenamiento

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Burbuja

Vamos a ordenar comparando vecinos. Si el de la izquierda es mayor, cambiamos sus posiciones; repetimos una pasada y el mayor pendiente acaba al final. Podemos imaginar burbujas grandes que van subiendo. Si una pasada no hace cambios, ya terminamos. Si los datos están al revés, hacemos muchas comparaciones; al duplicar la cantidad, estas pueden crecer hasta casi cuatro veces. Si ya están ordenados, basta una pasada. La función completa está en Ordenamientos.h.

[Programa comentado](01_Burbuja/main.cpp).

## Selección

Vamos a buscar el menor dato pendiente y colocarlo al principio de la zona sin ordenar. Después repetimos con el resto. Podemos imaginar que elegimos el libro más pequeño de un montón y lo ponemos en una fila. Aunque los números ya estén ordenados, seguimos buscando el menor de cada grupo. Con diez números hacemos muchas comparaciones; con veinte, cerca de cuatro veces más. Al intercambiar posiciones lejanas podemos cambiar el orden de elementos que empatan.

[Programa comentado](02_Seleccion/main.cpp).

## Inserción

Vamos a ordenar como una mano de cartas. Tomamos un dato nuevo y desplazamos los anteriores que sean mayores hasta abrirle un lugar. Así mantenemos ordenada la parte izquierda. Si los datos ya están ordenados basta con recorrerlos una vez. Si vienen al revés, desplazamos muchos datos y repetimos más trabajo. Al no adelantar un dato sobre otro igual conservamos el orden de los empates.

[Programa comentado](03_Insercion/main.cpp).

## Merge sort

Vamos a dividir un montón en mitades hasta tener grupos pequeños y después reunirlos en orden. Podemos imaginar dos ayudantes que ordenan sus hojas: al juntarlas elegimos siempre la menor hoja disponible. Eso hace merge sort. Necesitamos otro espacio para la mezcla, que crece con la cantidad de datos. En cada nivel recorremos todos los datos y tenemos tantos niveles como divisiones por mitades. Ante un empate tomamos primero el dato de la izquierda para conservar su orden.

[Programa comentado](04_Merge_Sort/main.cpp).

## Quick sort

Vamos a elegir un dato como referencia para separar los demás; a ese dato lo llamamos pivote. Ponemos los menores de un lado y repetimos en cada grupo. Eso hace quick sort. Si los grupos quedan parejos, cada nivel revisa todos los datos y los niveles crecen por mitades. Aquí elegimos el último dato: con entradas ordenadas o iguales puede quedar casi todo de un lado y repetirse mucho trabajo. Esta elección nos ayuda a observar por qué importa el pivote.

[Programa comentado](05_Quick_Sort/main.cpp).

## Ordenar con la biblioteca estándar

Vamos a comparar lo aprendido con herramientas que C++ ya trae en <algorithm>. sort ordena un grupo entre begin() y end(); end() marca el lugar después del último dato. Para fichas de alumnos damos una función que decide cuál va primero. La función pequeña escrita con [] se llama lambda: aquí recibe dos alumnos y compara sus notas con <. stable_sort conserva el orden previo de quienes empatan. Primero entendemos los movimientos manuales y ahora podemos usar esta herramienta para resolver una tarea completa.

[Programa comentado](06_STD_Sort/main.cpp).

## Algoritmos de ordenamiento

Vamos a comprobar cinco maneras de ordenar usando las mismas entradas. Creamos una copia para cada algoritmo y comparamos su resultado con sort. Incluimos datos vacíos, negativos, repetidos y ya ordenados. Guardamos direcciones de funciones para poder llamar a cada algoritmo de la misma manera: igual que un puntero puede señalar una caja, un puntero a función puede señalar una tarea que podemos ejecutar. Si alguna comparación falla, mostramos el problema y terminamos.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa integrador de ordenamientos.

- Apliquemos burbuja, selección, inserción, merge sort y quick sort a copias de los mismos datos.
- Comparemos sus resultados.
- Probemos vacío, un elemento, negativos, repetidos y orden inverso.
- Contemos comparaciones en al menos dos algoritmos.
- Expliquemos por qué una misma salida puede requerir distinto trabajo.

[Volvemos a la guía general](../../README.md).
