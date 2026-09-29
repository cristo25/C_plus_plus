# Árboles

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Árbol binario: raíces, hijos y hojas

Vamos a unir nodos formando ramas. En un árbol binario cada nodo puede tener como máximo un hijo izquierdo y uno derecho. Al primer nodo lo llamamos raíz; a uno sin hijos lo llamamos hoja. Aquí solo estamos construyendo la forma: tener dos ramas no obliga a ordenar los números. Para contar, sumamos el nodo actual y los de sus dos ramas mediante recursión. Usamos unique_ptr para que cada rama libere sus nodos al terminar.

[Programa comentado](01_Arbol_Binario/main.cpp).

## Árbol binario de búsqueda (ABB)

Vamos a añadir una regla al árbol: los números menores van a la izquierda y los mayores a la derecha. Así, al buscar elegimos una rama y descartamos la otra. Llamamos a esta organización árbol binario de búsqueda, o ABB. Aquí no guardamos repetidos. Al borrar un nodo con dos hijos buscamos un reemplazo que conserve el orden. Si el árbol queda como una cadena, tendremos que recorrer muchos nodos; no basta con llamarlo árbol para que siempre busque rápido.

[Programa comentado](02_Binario_de_Busqueda/main.cpp).

## Recorridos de un árbol

Vamos a visitar el mismo árbol en tres órdenes. En preorden leemos primero el nodo y después sus ramas; en inorden leemos izquierda, nodo y derecha; en postorden dejamos el nodo para el final. En un árbol de búsqueda, inorden nos muestra los números ordenados. Podemos imaginar que recorremos las mismas habitaciones pero anotamos su nombre al entrar, a mitad de la visita o al salir. En todos los casos visitamos los n nodos (O(n)).

[Programa comentado](03_Recorridos/main.cpp).

## Árboles

Vamos a integrar las operaciones del árbol: insertar, buscar, recorrer y eliminar. Usamos Arbol.h para seguir los mismos enlaces en cada caso. Primero comprobamos el árbol vacío, agregamos datos, comparamos sus recorridos y al final retiramos todos los nodos. Podemos pensar en cuidar un árbol de carpetas: cada cambio debe conservar el acceso a las ramas que todavía existen.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa integrador para administrar números en un árbol.

- Agregar y buscar números sin permitir repetidos.
- Ofrecer los tres recorridos.
- Eliminar la raíz sin perder los otros datos.
- Vaciar el árbol y volver a insertar.
- Mostrar un mensaje cuando una búsqueda no encuentre el número.

[Volvemos a la guía general](../../README.md).
