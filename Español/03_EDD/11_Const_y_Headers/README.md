# Const y headers en EDD

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Const y headers en EDD

Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar nada. Si duplicamos la cantidad de datos hacemos el doble de visitas (O(n), con n elementos). Solo añadimos un contador y unas pocas variables (O(1) de memoria adicional).

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa de consultas separado en archivos.

- Declarar una función en un .h y escribirla en un .cpp.
- Recibir un vector mediante const vector<int>&.
- Contar valores menores que un límite usando un ciclo.
- Devolver cero para un vector vacío.
- Comprobar que los datos originales no cambiaron.

[Volvemos a la guía general](../../README.md).
