# Estructuras de datos y algoritmos

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Complejidad: tiempo y espacio

Vamos a comparar cuánto trabajo hacemos cuando aumentan los datos. Llegar directamente a una casilla requiere una cantidad fija de pasos, aunque haya más casillas (O(1); no significa exactamente un paso). Revisar diez casillas implica diez visitas y revisar veinte implica veinte (O(n), donde n es la cantidad de casillas). Si vamos dividiendo por la mitad, de 8 a 1 hacemos tres divisiones y de 16 a 1 hacemos cuatro (O(log n), donde log n describe ese crecimiento por mitades). Llamamos notación O grande a estas abreviaturas: describen crecimiento, no segundos exactos. También podemos contar cuántos datos adicionales guardamos para hacer la tarea; a eso lo llamamos memoria auxiliar.

[Programa comentado](01_Complejidad/main.cpp).

## Vectores

Vamos a reunir creación, cambios y fichas de objetos en una lista de tareas. Cada Tarea guarda su nombre y si ya terminó. Insertamos una tarea, marcamos otra y quitamos una ficha. Podemos imaginar una libreta donde agregamos y retiramos renglones. El vector mantiene juntos los datos, pero sus posiciones pueden cambiar al insertar o borrar; por eso no confundimos el nombre de una tarea con su posición actual.

[Programa comentado](02_Vectores/main.cpp).

## Listas ligadas

Vamos a comparar las tres listas usando los mismos números. En la simple seguimos una flecha, en la doble podemos regresar y en la circular volvemos al inicio. Insertamos 10, 20 y 30, quitamos 20 y revisamos qué queda. La diferencia principal está en cómo unimos los nodos y cuándo detenemos el recorrido. Podemos dibujar las mismas tres cajas y cambiar solo sus flechas para entenderlo.

[Programa comentado](03_Listas_Ligadas/main.cpp).

## Pilas

Vamos a comparar una pila construida con vector con otra de tipo stack. Introducimos 1, 2 y 3 en ambas y retiramos por el extremo superior. En las dos debe salir primero el 3. La idea que estamos practicando es el orden de salida; una pila se reconoce por esa regla, aunque usemos herramientas distintas para guardarla.

[Programa comentado](04_Pilas/main.cpp).

## Colas

Vamos a poner los mismos datos en una fila normal y en una fila con prioridad. Al guardar 2, 9 y 4, la primera conserva ese orden; la segunda atiende primero el 9. Así podemos decidir qué regla necesita una aplicación: respetar la llegada o elegir por importancia. Cambiar la estructura cambia esa regla de atención, aunque los datos sean iguales.

[Programa comentado](05_Colas/main.cpp).

## Árboles

Vamos a integrar las operaciones del árbol: insertar, buscar, recorrer y eliminar. Usamos Arbol.h para seguir los mismos enlaces en cada caso. Primero comprobamos el árbol vacío, agregamos datos, comparamos sus recorridos y al final retiramos todos los nodos. Podemos pensar en cuidar un árbol de carpetas: cada cambio debe conservar el acceso a las ramas que todavía existen.

[Programa comentado](06_Arboles/main.cpp).

## Tablas hash con unordered_map

Vamos a buscar por una clave, como encontrar una ficha de alumno por su matrícula. unordered_map relaciona una clave con un dato; aquí un número con un nombre. Por dentro usa una función hash, que calcula en qué grupo buscar la clave. Con find buscamos sin crear una ficha; si obtenemos end(), no existe. En la ficha encontrada, first es la clave y second el dato. No esperamos que sus fichas aparezcan ordenadas. Habitualmente revisamos pocas entradas, pero si muchas claves caen juntas podemos tener que revisar muchas.

[Programa comentado](07_Tablas_Hash/main.cpp).

## Grafos

Vamos a usar un mismo mapa para contestar preguntas distintas. Con BFS exploramos por capas; con DFS seguimos una rama antes de volver; con Dijkstra buscamos el menor costo acumulado. Compartimos Grafo.h para no construir un mapa diferente en cada prueba. Podemos comparar los recorridos, pero no interpretamos el orden de BFS o DFS como una lista de costos: cada herramienta responde una pregunta diferente.

[Programa comentado](08_Grafos/main.cpp).

## Algoritmos de ordenamiento

Vamos a comprobar cinco maneras de ordenar usando las mismas entradas. Creamos una copia para cada algoritmo y comparamos su resultado con sort. Incluimos datos vacíos, negativos, repetidos y ya ordenados. Guardamos direcciones de funciones para poder llamar a cada algoritmo de la misma manera: igual que un puntero puede señalar una caja, un puntero a función puede señalar una tarea que podemos ejecutar. Si alguna comparación falla, mostramos el problema y terminamos.

[Programa comentado](09_Ordenamiento/main.cpp).

## Búsqueda

Vamos a comparar la búsqueda uno por uno con la búsqueda por mitades. Primero buscamos en datos sin ordenar, después ordenamos y probamos ambas sobre el mismo vector. El número sigue siendo el mismo, pero su posición puede cambiar al ordenar. También contamos el trabajo previo: preparar una lista ordenada es una tarea adicional, aunque buscar dentro de ella después sea más rápido.

[Programa comentado](10_Busqueda/main.cpp).

## Const y headers en EDD

Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar nada. Si duplicamos la cantidad de datos hacemos el doble de visitas. Solo añadimos un contador y unas pocas variables.

[Programa comentado](11_Const_y_Headers/main.cpp).

## Integrador: procesar tareas y consultar rutas

Vamos a reunir las estructuras en un taller de tareas y entregas. Guardamos tareas en un vector, atendemos por una cola y anotamos lo ocurrido en una lista. Con una pila consultamos cuál sería la última acción a deshacer. Usamos un árbol y una tabla por id para practicar consultas; ordenamos números antes de buscarlos por mitades. Finalmente usamos un grafo para calcular rutas. Cada estructura responde una necesidad distinta; este ejemplo las reúne para observar cómo se pasan los datos.

[Programa comentado](12_Integrador/main.cpp).

## Integrador: propietarios, vistas, matrices y ordenamiento

Vamos a combinar las capas para mostrar productos ordenados sin mover sus cajas originales. Guardamos estantes en un vector; cada estante contiene nodos y cada nodo contiene un producto. Reunimos direcciones de esos nodos en vista y ordenamos solo las tarjetas por precio. Después elegimos tarjetas para una matriz de exposición. Una misma tarjeta puede aparecer varias veces: contar casillas ocupadas no significa contar productos distintos. Calculamos el valor total desde los estantes para no sumar dos veces un producto repetido en la vitrina.

[Programa comentado](13_Combinacion_de_Conceptos/main.cpp).

[Volvemos a la guía general](../README.md).
