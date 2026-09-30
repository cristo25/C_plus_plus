# Const y headers en EDD

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Const y headers en EDD

Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar nada. Si duplicamos la cantidad de datos hacemos el doble de visitas. Solo añadimos un contador y unas pocas variables.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa de consultas separado en archivos.

- Declaremos una función en un.h y escribirla en un.cpp.
- Recibamos un vector mediante const vector<int>&.
- Contemos valores menores que un límite usando un ciclo.
- Devolvamos cero para un vector vacío.
- Comprobemos que los datos originales no cambiaron.

[Volvemos a la guía general](../../README.md).
