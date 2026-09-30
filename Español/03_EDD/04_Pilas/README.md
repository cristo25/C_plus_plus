# Pilas

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Una pila con vector

Vamos a usar un vector como una pila de platos: solo ponemos y quitamos por arriba. Con push_back agregamos, con back miramos el último dato y con pop_back lo retiramos. El último en entrar es el primero en salir. Antes de consultar o quitar revisamos que la pila no esté vacía. Si necesitamos el dato retirado, lo guardamos antes de llamar pop_back, porque esa operación no lo devuelve.

[Programa comentado](01_Con_Vector/main.cpp).

## El adaptador stack

Vamos a usar stack, la herramienta de <stack> que ofrece directamente las operaciones de una pila. push agrega arriba, top permite leer la cima y pop la retira. Podemos imaginar un historial para deshacer: la última acción que hicimos es la primera que revisamos. Aquí mostramos qué acción se desharía; retirarla del historial no modifica por sí sola un documento real.

[Programa comentado](02_Con_Stack/main.cpp).

## Pilas

Vamos a comparar una pila construida con vector con otra de tipo stack. Introducimos 1, 2 y 3 en ambas y retiramos por el extremo superior. En las dos debe salir primero el 3. La idea que estamos practicando es el orden de salida; una pila se reconoce por esa regla, aunque usemos herramientas distintas para guardarla.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa integrador que compare dos pilas.

- Agreguemos los mismos datos a un vector y a un stack.
- Consultemos las dos cimas antes de retirar.
- Comprobemos que sale el mismo dato en cada paso.
- Terminemos con ambas pilas vacías.

[Volvemos a la guía general](../../README.md).
