# Búsqueda

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Búsqueda lineal

Vamos a buscar como si revisáramos un cajón casilla por casilla. No necesitamos ordenar antes: avanzamos hasta encontrar el dato o llegar al final. Podemos visitar todos los elementos. Para devolver el resultado usamos optional: una cajita de <optional> que puede guardar una posición o estar vacía. Comprobamos si contiene algo antes de leer *posicion. Una posición cero es un resultado válido; no debemos confundirla con «no encontrado».

[Programa comentado](01_Lineal/main.cpp).

## Búsqueda binaria

Vamos a buscar en una lista ya ordenada. Miramos el centro y decidimos en qué mitad podría estar el número. Podemos imaginar una guía de páginas numeradas: si buscamos una página menor, descartamos la mitad derecha. Reducir 16 candidatos a 8, 4, 2 y 1 requiere cuatro divisiones; empezar con 32 agrega solo otra. Esta versión encuentra la primera coincidencia. Recibimos una posición o un resultado vacío y comprobamos cuál antes de leerlo.

[Programa comentado](02_Binaria/main.cpp).

## Búsqueda

Vamos a comparar la búsqueda uno por uno con la búsqueda por mitades. Primero buscamos en datos sin ordenar, después ordenamos y probamos ambas sobre el mismo vector. El número sigue siendo el mismo, pero su posición puede cambiar al ordenar. También contamos el trabajo previo: preparar una lista ordenada es una tarea adicional, aunque buscar dentro de ella después sea más rápido.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa integrador de búsquedas.

- Busquemos varios valores con búsqueda lineal.
- Creemos una copia ordenada para la búsqueda binaria.
- Comparemos si ambas encuentran o no cada valor.
- Mostremos cómo cambia la posición al ordenar.
- Probemos también un vector vacío.

[Volvemos a la guía general](../../README.md).
