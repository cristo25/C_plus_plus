# Memoria y punteros en POO

## Memoria dinámica manual

Vamos a crear una caja mientras el programa está funcionando. Con new int(42) reservamos espacio para un entero y recibimos su dirección. Guardamos esa dirección en numero y con *numero consultamos el 42. Esa caja no desaparece por dejar de usar la variable puntero: aquí debemos liberarla una sola vez con delete. Después ponemos numero en nullptr para no reutilizar esa dirección. Nunca usamos delete sobre una variable normal ni seguimos un puntero después de liberar su dato.

[Programa comentado](01_New_y_Delete/main.cpp).

## Propiedad con unique_ptr

Vamos a dar a una sola herramienta la responsabilidad de liberar la caja. Con unique_ptr, de <memory>, guardamos esa responsabilidad junto con la dirección. make_unique crea el dato; get nos presta su dirección para consultarlo. Ese puntero prestado no debe liberarlo. Al terminar el programa, propietario libera el entero automáticamente. Esta ayuda evita que olvidemos un delete.

[Programa comentado](02_Unique_Ptr/main.cpp).

## Memoria y punteros en POO

Imaginemos que Alumno es una caja con un nombre y consulta guarda la dirección de esa caja. Creamos al alumno con make_unique y pedimos su dirección prestada con get. Con consulta->consultarNombre() seguimos la dirección y leemos el nombre. Antes de llamar reset dejamos de usar la dirección prestada y ponemos consulta en nullptr. Después, reset libera al alumno. El puntero prestado nunca tiene que borrarlo.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa integrador con un objeto administrado por unique_ptr.

- Crear una clase con nombre y una consulta const.
- Crear un objeto con make_unique y observarlo mediante get.
- Mostrar su nombre usando ->.
- Retirar el observador antes de llamar reset.
- Explicar qué variable liberó el objeto.

[Volvemos a la guía general](../../README.md).
