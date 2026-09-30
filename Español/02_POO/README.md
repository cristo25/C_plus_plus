# Programación orientada a objetos

## Clases y objetos

Vamos a reunir datos y acciones que pertenecen a una misma cosa. Podemos imaginar una clase como el molde de un bloque de Minecraft: indica qué datos tiene y qué puede hacer cada bloque creado con ese molde. Cada bloque concreto sería un objeto. En este programa usamos Bicicleta: guardamos color y velocidad, y con pedalear aumentamos la velocidad. Creamos roja y azul por separado; pedalear con roja no cambia azul. Llamamos atributos a esos datos y métodos a las funciones que escribimos dentro de la clase. Con public permitimos usarlos desde main.

[Programa comentado](01_Clases_y_Objetos/main.cpp).

## Encapsulamiento y const

Vamos a proteger el saldo de una alcancía. En lugar de permitir cualquier cambio desde main, lo guardamos dentro de la clase y ofrecemos depositar y retirar. Cada función comprueba sus reglas antes de cambiar el saldo. Llamamos encapsulamiento a reunir esos datos y sus reglas detrás de operaciones controladas. Dentro de class, los datos son privados si no escribimos public. Con consultar() const podemos leer el saldo sin cambiarlo: const al final de una función promete respetar los datos del objeto.

[Programa comentado](02_Encapsulamiento/main.cpp).

## Constructores, destructores

Vamos a observar cuándo empieza y termina un objeto. El constructor tiene el nombre de la clase y prepara sus datos; en Sesion guarda el usuario y anuncia su entrada. El destructor lleva ~ delante del nombre y se ejecuta cuando termina la vida del objeto. Podemos imaginar que abrimos una tienda y la cerramos al salir. En este ejemplo las llaves delimitan esa estancia: al llegar a su cierre aparece el mensaje de salida. Más adelante usaremos la misma idea para liberar memoria y cerrar archivos automáticamente.

[Programa comentado](03_Constructores_y_Destructores/main.cpp).

## Composición

Vamos a construir una cosa usando otra como parte. Un Auto tiene un Motor; por eso guardamos un objeto Motor dentro de Auto. A esta relación la llamamos composición. Desde main pedimos que arranque el auto, y el auto se encarga de encender su motor. Podemos imaginar un bloque que contiene un inventario: tener una parte no significa ser esa parte. Al terminar el auto también termina el motor que contiene.

[Programa comentado](04_Composicion/main.cpp).

## Herencia

Vamos a describir una versión más específica de algo que ya tenemos. Una BicicletaElectrica sigue siendo una Bicicleta, pero también tiene batería. Con : public Bicicleta conservamos las operaciones públicas de la bicicleta y agregamos las propias. Llamamos herencia a esta relación. En asistir revisamos la batería antes de gastarla y pedalear. Nos conviene cuando podemos decir «es una»; para decir «tiene una parte» usamos la composición del tema anterior.

[Programa comentado](05_Herencia/main.cpp).

## Polimorfismo y clases abstractas

Vamos a pedir la misma acción a objetos diferentes. Con tocar pedimos que suene un Instrumento, pero una Guitarra y un Tambor responden de forma distinta. A eso lo llamamos polimorfismo. Con virtual permitimos que cada instrumento tenga su propia respuesta; con = 0 dejamos esa respuesta pendiente en la clase general; con override comprobamos que la nueva función corresponde a la que queremos reemplazar. Pasamos una referencia para usar el instrumento original. El destructor virtual permite limpiar el objeto completo si después lo eliminamos mediante un puntero a Instrumento.

[Programa comentado](06_Polimorfismo/main.cpp).

## Memoria y punteros en POO

Imaginemos que Alumno es una caja con un nombre y consulta guarda la dirección de esa caja. Creamos al alumno con make_unique y pedimos su dirección prestada con get. Con consulta->consultarNombre() seguimos la dirección y leemos el nombre. Antes de llamar reset dejamos de usar la dirección prestada y ponemos consulta en nullptr. Después, reset libera al alumno. El puntero prestado nunca tiene que borrarlo.

[Programa comentado](07_Memoria_y_Punteros/main.cpp).

[Guía de memoria y punteros](07_Memoria_y_Punteros/README.md).

## Const, headers y compilación de varios archivos

Vamos a separar una clase para poder usarla desde varios programas. Podemos imaginar Producto.h como una carta que dice qué ofrece una tienda, y Producto.cpp como el lugar donde se hacen esas tareas. Desde main creamos un Producto con nombre y precio. Guardamos el precio en centavos enteros para evitar pequeñas diferencias de los decimales. Con const protegemos el objeto y sus consultas. Si intentamos poner un precio negativo, el constructor rechaza el producto con un error de <stdexcept>; <string> nos permite guardar su nombre. Para ejecutar necesitamos compilar main.cpp junto con Producto.cpp: incluir el .h solo anuncia las funciones.

[Programa comentado](08_Headers/main.cpp).

[Guía de headers](08_Headers/README.md).

## DAO: separar el acceso a datos

Vamos a recorrer todo el trabajo del catálogo: crear libros, cambiar un título, eliminar un libro y recuperar lo guardado. Aquí usamos stringstream, de <sstream>, como un cuaderno temporal en memoria: podemos escribir en él y volver a leer sin crear un archivo en disco. Después probamos una lectura con ids repetidos. La regla es sencilla: si no podemos recuperar todos los datos correctamente, conservamos el catálogo que ya teníamos.

[Programa comentado](09_DAO/main.cpp).

[Guía de DAO](09_DAO/README.md).

## Integrador: una biblioteca con objetos

Vamos a construir una pequeña biblioteca con varias clases que colaboran. Biblioteca contiene un DAO para guardar libros. Una Vista decide cómo mostrarlos: VistaDetalle escribe sus datos y VistaResumen muestra cuántos hay. Pedimos mostrar el catálogo de la misma manera aunque cambiemos de vista. Así reunimos composición, datos protegidos, consultas const y polimorfismo. Con unique_ptr dejamos claro quién se encarga de liberar la vista cuando ya no la usamos.

[Programa comentado](10_Integrador/main.cpp).

[Volvemos a la guía general](../README.md).
