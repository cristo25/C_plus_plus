# Const, headers y compilación de varios archivos

Vamos a separar una clase para poder usarla desde varios programas. Podemos imaginar Producto.h como una carta que dice qué ofrece una tienda, y Producto.cpp como el lugar donde se hacen esas tareas. Desde main creamos un Producto con nombre y precio. Guardamos el precio en centavos enteros para evitar pequeñas diferencias de los decimales. Con const protegemos el objeto y sus consultas. Si intentamos poner un precio negativo, el constructor rechaza el producto con un error de <stdexcept>; <string> nos permite guardar su nombre. Para ejecutar necesitamos compilar main.cpp junto con Producto.cpp: incluir el .h solo anuncia las funciones.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa con una clase Producto separada en archivos.

- Guardar nombre y precio privado en centavos.
- Declarar la clase en Producto.h y sus funciones en Producto.cpp.
- Consultar ambos datos mediante métodos const.
- Crear dos productos desde main y mostrar sus datos.
- Rechazar un precio negativo.

[Volvemos a la guía general](../../README.md).
