# Colas

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## Cola FIFO

Vamos a atender una fila por orden de llegada. Con queue, de <queue>, agregamos al final mediante push, consultamos al primero con front y lo retiramos con pop. Podemos imaginar una fila de personas esperando una ventanilla. Antes de atender revisamos empty. A la regla «primero en entrar, primero en salir» también la llamamos FIFO; las siglas solo abrevian esa misma idea.

[Programa comentado](01_Con_Queue/main.cpp).

## Cola de prioridad y heap

Vamos a atender según importancia en lugar de llegada. priority_queue coloca arriba el valor con mayor prioridad: con enteros, normalmente es el mayor. Si queremos el menor, como un costo, usamos greater<int>, una regla de comparación de <functional>. Podemos imaginar urgencias de un hospital: llegar antes no siempre significa pasar antes. Con top consultamos el siguiente y con pop lo retiramos; siempre necesitamos que haya datos.

[Programa comentado](02_Cola_de_Prioridad/main.cpp).

## Colas

Vamos a poner los mismos datos en una fila normal y en una fila con prioridad. Al guardar 2, 9 y 4, la primera conserva ese orden; la segunda atiende primero el 9. Así podemos decidir qué regla necesita una aplicación: respetar la llegada o elegir por importancia. Cambiar la estructura cambia esa regla de atención, aunque los datos sean iguales.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa integrador de atención de solicitudes.

- Guardar las mismas prioridades en queue y priority_queue.
- Mostrar el orden completo de atención de cada una.
- Agregar una solicitud nueva después de atender una.
- Explicar cuál usar para una taquilla y cuál para urgencias.

[Volvemos a la guía general](../../README.md).
