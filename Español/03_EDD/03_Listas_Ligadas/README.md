# Listas ligadas

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Lista simplemente ligada

Vamos a construir una cadena de cajas llamadas nodos. Cada nodo guarda un dato y un puntero al siguiente, como una nota que indica dónde está la próxima caja. La lista guarda la dirección del primero; el último señala nullptr. Para buscar seguimos las notas una a una: quizá debamos visitar todos los nodos. Al quitar un nodo unimos su vecino anterior con el siguiente antes de liberar la caja. Podemos ver esos pasos dentro de ListaSimple.h.

[Programa comentado](01_Simplemente_Ligada/main.cpp).

## Lista doblemente ligada

Vamos a añadir una segunda flecha a cada nodo: una hacia el siguiente y otra hacia el anterior. Así podemos recorrer la cadena en ambos sentidos. Conservamos también el principio y el final para agregar al final ajustando unas pocas flechas, sin recorrer toda la lista. Al borrar cuidamos ambas conexiones, como al retirar un vagón de un tren unido por delante y por detrás. Podemos seguir el ajuste de los punteros en ListaDoble.h.

[Programa comentado](02_Doblemente_Ligada/main.cpp).

## Lista circular

Vamos a cerrar la cadena formando un círculo: el último nodo vuelve al primero. Podemos imaginar turnos de jugadores que se repiten. Como no encontramos nullptr al dar la vuelta, detenemos el recorrido al regresar al inicio. Guardamos el último nodo para añadir otro con pocos cambios. Al quitar el único nodo dejamos la lista vacía; al quitar otro conservamos cerrado el círculo.

[Programa comentado](03_Circular/main.cpp).

## Listas ligadas

Vamos a comparar las tres listas usando los mismos números. En la simple seguimos una flecha, en la doble podemos regresar y en la circular volvemos al inicio. Insertamos 10, 20 y 30, quitamos 20 y revisamos qué queda. La diferencia principal está en cómo unimos los nodos y cuándo detenemos el recorrido. Podemos dibujar las mismas tres cajas y cambiar solo sus flechas para entenderlo.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa integrador que compare tres listas.

- Insertemos los mismos cinco datos en una lista simple, una doble y una circular.
- Eliminemos el mismo dato de las tres.
- Mostremos los recorridos normales y el recorrido inverso de la doble.
- Limitemos la circular a una vuelta.
- Probemos cada lista después de vaciarla.

[Volvemos a la guía general](../../README.md).
