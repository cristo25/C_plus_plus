# Grafos

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Representar grafos

Vamos a dibujar lugares unidos por caminos. A cada lugar lo llamamos vértice y a cada conexión arista; al conjunto lo llamamos grafo. En conectar indicamos origen, destino y costo. Si queremos ida y vuelta agregamos ambas direcciones. Guardamos una lista de vecinos por lugar: la memoria crece con los lugares y caminos (O(V + E), donde V cuenta vértices y E aristas). Otra posibilidad es una tabla con una casilla por pareja de lugares: cinco lugares necesitan 25 casillas y diez necesitan 100 (O(V²), es decir, V multiplicado por V).

[Programa comentado](01_Representacion/main.cpp).

## BFS: búsqueda en anchura

Vamos a explorar un mapa por capas. Primero visitamos el inicio, después sus vecinos y después los vecinos de estos. Guardamos lo pendiente en una cola para respetar ese orden. A este recorrido lo llamamos BFS, o búsqueda en anchura. Marcamos cada lugar al agregarlo para no repetirlo, aunque haya caminos de regreso. Solo llegamos a lugares conectados con el inicio. Si recorremos todo el mapa, revisamos sus lugares y caminos (O(V + E), con V lugares y E conexiones).

[Programa comentado](02_BFS/main.cpp).

## DFS: búsqueda en profundidad

Vamos a seguir un camino hasta donde podamos y después regresar para probar otro. Podemos imaginar la exploración de un laberinto. A este recorrido lo llamamos DFS, o búsqueda en profundidad. Aquí usamos recursión para recordar por dónde volver. Marcamos los lugares visitados para no dar vueltas sin fin. El orden puede diferir del de BFS aunque ambos alcancen los mismos lugares. Si revisamos todo el mapa, el trabajo crece con sus V lugares y E caminos (O(V + E)).

[Programa comentado](03_DFS/main.cpp).

## Dijkstra: caminos de menor costo

Vamos a buscar el camino cuyo costo total sea menor. Podemos imaginar que cada carretera indica minutos: llegar con menos carreteras no siempre significa llegar antes. Con Dijkstra guardamos el mejor costo conocido y atendemos primero el candidato más barato mediante una cola de prioridad. Si encontramos una mejora, actualizamos el costo. Esta versión requiere costos no negativos. INFINITO es una marca para indicar que aún no encontramos una ruta; no representa minutos reales. dijkstra devuelve costos; en caminosMinimos también guardamos de dónde llegamos para reconstruir una ruta.

[Programa comentado](04_Dijkstra/main.cpp).

## Grafos

Vamos a usar un mismo mapa para contestar preguntas distintas. Con BFS exploramos por capas; con DFS seguimos una rama antes de volver; con Dijkstra buscamos el menor costo acumulado. Compartimos Grafo.h para no construir un mapa diferente en cada prueba. Podemos comparar los recorridos, pero no interpretamos el orden de BFS o DFS como una lista de costos: cada herramienta responde una pregunta diferente.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa integrador de rutas de una escuela.

- Guardar al menos cinco edificios y los minutos entre ellos.
- Mostrar BFS y DFS desde el mismo edificio.
- Calcular el menor costo con Dijkstra.
- Incluir un edificio sin conexión y avisar si no es alcanzable.
- Separar el grafo y sus operaciones en un header.

[Volvemos a la guía general](../../README.md).
