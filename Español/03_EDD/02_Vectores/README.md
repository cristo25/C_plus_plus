# Vectores

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Crear y recorrer un vector

Vamos a usar un cajón cuya cantidad de casillas puede crecer: vector<int>, de <vector>. Con push_back agregamos al final y con size consultamos cuántos datos hay. Recorremos los números para sumarlos. Cuando se llena el espacio reservado, el vector puede mudarse a otro bloque y llevarse sus datos; las direcciones anteriores ya no sirven. No tenemos que mudar el cajón cada vez que añadimos un dato; normalmente basta con ocupar la siguiente casilla.

[Programa comentado](01_Crear_y_Recorrer/main.cpp).

## Insertar y eliminar en vectores

Vamos a abrir y quitar espacios en medio de un vector. Con begin() obtenemos una posición que señala el inicio; begin() + 1 señala el segundo elemento. A esa forma de señalar una posición la llamamos iterador. insert coloca un dato y desplaza los siguientes; erase quita uno y cierra el hueco. Por eso puede tocar mover casi todos los elementos. Después del cambio volvemos a obtener las posiciones que necesitamos. Antes de pop_back comprobamos empty para no quitar algo de un vector vacío.

[Programa comentado](02_Insertar_y_Eliminar/main.cpp).

## Vectores de objetos

Vamos a guardar fichas completas dentro del vector. Con struct Alumno reunimos un nombre y una nota, como dos casillas de una misma ficha. vector<Alumno> guarda esas fichas y push_back agrega otra. Con const auto& leemos cada ficha sin copiarla: auto permite que C++ deduzca el tipo, & nos da otra etiqueta del mismo objeto y const impide cambiarlo mediante esa etiqueta. Usamos el punto para elegir un dato de la ficha.

[Programa comentado](03_Vector_de_Objetos/main.cpp).

## Vectores

Vamos a reunir creación, cambios y fichas de objetos en una lista de tareas. Cada Tarea guarda su nombre y si ya terminó. Insertamos una tarea, marcamos otra y quitamos una ficha. Podemos imaginar una libreta donde agregamos y retiramos renglones. El vector mantiene juntos los datos, pero sus posiciones pueden cambiar al insertar o borrar; por eso no confundimos el nombre de una tarea con su posición actual.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un programa integrador de tareas con vector.

- Guardemos nombre y estado de cada tarea en un struct.
- Agreguemos una tarea al final y otra en medio.
- Marquemos una tarea como terminada.
- Eliminemos una tarea y mostrar las restantes.
- Comprobemos las posiciones antes de usarlas.

[Volvemos a la guía general](../../README.md).
