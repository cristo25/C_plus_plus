# Const, headers y compilación de varios archivos

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Const, headers y compilación de varios archivos

Vamos a separar una clase para poder usarla desde varios programas. En Producto.h mostramos qué datos guarda y qué operaciones ofrece; en Producto.cpp escribimos cómo trabajan esas operaciones. Desde main creamos un Producto con nombre y precio. Guardamos el precio en centavos enteros para evitar pequeñas diferencias de los decimales. Con const protegemos el objeto y sus consultas. Para ejecutar necesitamos compilar main.cpp junto con Producto.cpp; incluir el .h solo anuncia las funciones, no añade sus pasos.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa con una clase Producto separada en archivos.

- Guardar nombre y precio privado en centavos.
- Declarar la clase en Producto.h y sus funciones en Producto.cpp.
- Consultar ambos datos mediante métodos const.
- Crear dos productos desde main y mostrar sus datos.
- Rechazar un precio negativo.

[Volvemos a la guía general](../../README.md).
