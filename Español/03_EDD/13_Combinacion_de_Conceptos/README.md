# Combinar conceptos: del cajón a un inventario con vistas

Vamos a relacionar las piezas de este tema antes de resolver su práctica integradora. En cada enlace encontramos el programa, sus comentarios y una práctica con requisitos.

## 1. Un arreglo que contiene objetos

Vamos a guardar objetos completos en un arreglo. En Producto productos[3] cada compartimento contiene un producto con su nombre y precio. Reutilizamos Producto.h, que ya estudiamos en POO. Podemos imaginar un cajón con tres bloques de Minecraft: cada bloque conserva sus propios datos, aunque todos tengan el mismo tipo. Recorremos los productos mediante const Producto& para leer el original sin copiarlo ni cambiarlo. Cuando termina el arreglo también terminan los objetos que contiene.

[Programa comentado](01_Arreglo_de_Clases/main.cpp).

**Práctica.** Vamos a realizar un programa con un arreglo de productos.

- Creemos tres objetos completos con nombre y precio.
- Recorrámoslos mediante referencias const.
- Sumemos sus precios en centavos.
- Mostremos cada producto y el total.
- Expliquemos qué contiene una casilla del arreglo.

## 2. Un struct contiene una clase; un arreglo contiene esos structs

Vamos a añadir la cantidad disponible a cada producto. Con struct Registro juntamos un Producto y un entero cantidad; después guardamos varias fichas Registro en un arreglo. Podemos imaginar un compartimento que contiene el producto y una etiqueta con sus existencias. Con registros[0].producto llegamos al objeto y con registros[0].cantidad al número. recibirUnidad recibe Registro& para cambiar la ficha original: si quitamos &, cambiaríamos solo una copia.

[Programa comentado](02_Arreglo_de_Structs_con_Clases/main.cpp).

**Práctica.** Vamos a realizar un programa que registre existencias por producto.

- Creemos un struct que contenga un Producto y una cantidad.
- Guardemos al menos dos registros en un arreglo.
- Recibamos unidades mediante una función con referencia.
- Rechacemos cantidades negativas y evitar superar el límite del entero.
- Mostremos las fichas después del cambio.

## 3. Un arreglo de tarjetas para enteros

Vamos a guardar direcciones en lugar de enteros. En int* direcciones[3] tenemos tres tarjetas: cada una puede señalar una caja que está fuera del arreglo. Con *direcciones[0] seguimos la primera tarjeta y cambiamos rojo; con direcciones[0] = &azul cambiamos únicamente la tarjeta. Podemos tener dos tarjetas para la misma caja, o nullptr cuando no elegimos ninguna. El arreglo guarda los punteros, pero no se encarga de borrar los enteros locales a los que apuntan.

[Programa comentado](03_Arreglo_de_Punteros/main.cpp).

**Práctica.** Vamos a realizar un programa con tres tarjetas para dos enteros.

- Guardemos direcciones en un arreglo int* tarjetas[3].
- Hagamos que dos tarjetas señalen el mismo entero.
- Cambiemos ese entero mediante una tarjeta y consultar desde la otra.
- Dejemos una tarjeta en nullptr y comprobarla antes de seguirla.
- Mostremos que cambiar una dirección no cambia el contenido anterior.

## 4. Un vector de punteros: una vista del inventario

Vamos a seleccionar productos sin copiarlos. Guardamos los productos en un arreglo y sus direcciones en vector<Producto*>. A esa selección la llamamos vista: puede crecer o mostrar un producto varias veces sin crear productos nuevos. Con Producto*& damos a seleccionar otra etiqueta del puntero original, por lo que puede cambiar su destino. Si recibiera solo Producto*, cambiaría una copia de la tarjeta. Aunque crezca el vector de direcciones, estos productos del arreglo permanecen en su lugar; deben seguir existiendo mientras los consultamos.

[Programa comentado](04_Vector_de_Punteros/main.cpp).

**Práctica.** Vamos a realizar un programa que muestre una selección de productos.

- Guardemos tres productos completos en un arreglo.
- Guardemos sus direcciones en un vector de punteros.
- Cambiemos una selección mediante una referencia a puntero.
- Mostremos un producto dos veces sin copiarlo.
- Comprobemos que los productos originales conservan su posición.

## 5. Un arreglo de arreglos de punteros

Vamos a organizar las tarjetas en filas y columnas. Producto* casillas[2][2] representa dos filas de dos direcciones. Con casillas[0][1] elegimos una tarjeta; si no es nullptr, podemos seguirla hasta el producto. Dos casillas pueden mostrar el mismo producto, como dos letreros que señalan la misma tienda. En este ejemplo añadimos const después de * para fijar las tarjetas; todavía podemos modificar los productos señalados. No confundimos una matriz con Producto**: la matriz contiene sus filas, mientras que el doble puntero guarda una dirección hacia otro puntero.

[Programa comentado](05_Matriz_de_Punteros/main.cpp).

**Práctica.** Vamos a realizar una vitrina de productos con una matriz de punteros.

- Creemos dos filas con dos casillas cada una.
- Incluyamos una casilla nullptr y dos que señalen el mismo producto.
- Mostremos un aviso en las casillas vacías.
- Cambiemos un producto y comprobar que ambas tarjetas muestran el cambio.
- Contemos casillas ocupadas sin confundirlas con productos distintos.

## 6. Nodos dentro de un arreglo, unidos por punteros

Vamos a guardar nodos completos dentro de un arreglo y unirlos con punteros. Cada Nodo contiene un Producto y siguiente, la dirección del próximo nodo. Las cajas están en las posiciones 0, 1 y 2, pero podemos recorrerlas en el orden 0, 2 y 1 siguiendo las flechas. El último enlace es nullptr. Como las cajas pertenecen al arreglo y no las creamos con new, no usamos delete. Limitamos las visitas a tres para detectar si por error cerramos un círculo. Al copiar manualmente estas fichas habría que reconstruir sus flechas para no seguir apuntando a las originales.

[Programa comentado](06_Arreglo_de_Nodos/main.cpp).

**Práctica.** Vamos a realizar un programa que enlace nodos dentro de un arreglo.

- Guardemos tres nodos con productos.
- Conectemos las posiciones en el orden 2, 0 y 1.
- Recorramos desde el nodo inicial siguiendo siguiente.
- Detengámonos en nullptr o avisar si se excede la cantidad de nodos.
- Dibujemos posiciones del arreglo y orden de visita por separado.

## 7. Un vector de propietarios y un puntero observador

Vamos a separar la ubicación de las tarjetas y la de los productos. En vector<unique_ptr<Producto>> cada tarjeta también tiene la responsabilidad de liberar su producto. Cuando el vector necesita más espacio puede mover las tarjetas; los productos creados aparte conservan sus direcciones. Con get prestamos una dirección, pero no la responsabilidad de borrar. Al eliminar la tarjeta responsable también se destruye el producto; antes dejamos de usar todos los punteros prestados. Esto es distinto de vector<Producto>, donde al crecer pueden mudarse los productos mismos.

[Programa comentado](07_Vector_de_Unique_Ptr/main.cpp).

**Práctica.** Vamos a realizar un programa con productos administrados por unique_ptr dentro de un vector.

- Creemos dos productos con make_unique.
- Obtengamos un puntero de consulta mediante get.
- Aumentemos la capacidad del vector y comprobar la dirección del producto.
- Retiremos todas las consultas antes de borrar a su propietario.
- Mostremos cuántos productos quedan.

## 8. Una clase administra nodos struct

Vamos a reunir la cadena y sus reglas dentro de Estante. Podemos imaginar un encargado de estantería que acomoda las cajas y nos presta sus etiquetas para leerlas. Cada nodo contiene un Producto y un unique_ptr al siguiente; el estante se encarga del primero. Al agregar usamos `swap` para intercambiar tarjetas: el nodo nuevo señala a la cadena anterior y el estante señala al nuevo. Desde fuera pedimos agregar o consultar, sin cambiar directamente los enlaces. primero() y siguienteNodo() prestan direcciones; consultarProducto() presta una referencia de lectura. Cuando vaciamos el estante, esas consultas dejan de servir porque sus cajas ya no existen.

[Programa comentado](08_Clase_con_Nodos/main.cpp).

**Práctica.** Vamos a realizar un programa con una clase que administre una lista de productos.

- Guardemos el primer nodo dentro de la clase.
- Agreguemos tres productos mediante una operación pública.
- Recorrámoslos usando consultas const.
- Calculemos el valor total.
- Vaciemos la lista sin volver a usar direcciones de nodos eliminados.

## 9. Un vector contiene clases que administran nodos

Vamos a guardar varios estantes en un vector. Dentro de cada estante hay nodos y dentro de cada nodo un producto: seguimos esas capas una a una. Al crecer el vector puede mudarse un estante, por lo que retiramos los punteros al propio estante antes de forzar ese cambio. Sus nodos se crearon aparte y no se mudan al transferir quién los administra. Por eso podemos conservar una consulta a un nodo mientras siga existiendo. Si vaciamos su estante, el nodo desaparece y debemos dejar de usar esa consulta.

[Programa comentado](09_Vector_de_Clases_con_Nodos/main.cpp).

**Práctica.** Vamos a realizar un programa con un vector de estantes que tengan nodos.

- Creemos dos estantes y agregar productos a sus listas.
- Distingamos un puntero al estante de otro a uno de sus nodos.
- Retiremos el puntero al estante antes de aumentar la capacidad del vector.
- Consultemos el nodo desde su nuevo propietario.
- Retiremos la consulta antes de vaciar su lista.

## Integrador: propietarios, vistas, matrices y ordenamiento

Vamos a combinar las capas para mostrar productos ordenados sin mover sus cajas originales. Guardamos estantes en un vector; cada estante contiene nodos y cada nodo contiene un producto. Reunimos direcciones de esos nodos en vista y ordenamos solo las tarjetas por precio. Después elegimos tarjetas para una matriz de exposición. Una misma tarjeta puede aparecer varias veces: contar casillas ocupadas no significa contar productos distintos. Calculamos el valor total desde los estantes para no sumar dos veces un producto repetido en la vitrina.

[Programa comentado](main.cpp).

**Práctica.** Vamos a realizar un inventario integrador con estantes, nodos y vistas.

- Guardemos varios estantes en un vector y sus productos en nodos struct.
- Creemos una vista de punteros de lectura sin copiar los productos.
- Ordenemos la vista por nombre o precio.
- Mostremos parte de la vista en una matriz de punteros con casillas vacías.
- Cambiemos una selección mediante una referencia a puntero.
- Comprobemos que el orden original y el total no cambian al ordenar la vista.
- Expliquemos qué estructura libera cada objeto.

[Volvemos a la guía general](../../README.md).
