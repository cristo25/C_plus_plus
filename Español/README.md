# Aprende C++ paso a paso

Una ruta en español con **73 programas ejecutables**. Los nombres de carpetas llevan números y no usan espacios ni acentos para facilitar su uso en la terminal.

## Comienza aquí

1. [Programación estructurada](01_Programacion_Estructurada/README.md): datos, decisiones, ciclos, funciones, arreglos, cadenas, punteros, archivos y recursión.
2. [POO](02_POO/README.md): clases, encapsulamiento, composición, herencia, polimorfismo, memoria, headers y DAO.
3. [EDD](03_EDD/README.md): complejidad, vectores, listas, pilas, colas, árboles, tablas hash, grafos, ordenamiento y búsqueda.
4. [Proyecto integrador](04_Proyecto_Integrador/README.md): estructura reservada para la aplicación conjunta que desarrollaremos después.

La programación estructurada y POO son formas de organizar programas; EDD estudia estructuras y algoritmos, y DAO es un patrón para acceder a los datos. Se complementan.

## Cómo estudiar cada tema

1. Lee su `README.md`: concepto, analogía, ejecución, resultado y práctica.
2. Abre `main.cpp` y predice qué aparecerá en la consola.
3. Compílalo y ejecútalo. Los ejemplos introductorios muestran resultados; los integradores de comprobación conservan assert.
4. Cambia los datos y realiza el ejercicio propuesto. Las lecciones individuales no usan assert. Las comprobaciones de los integradores no reemplazan la validación de entrada.
5. En temas con subcarpetas, ejecuta al final el `main.cpp` del tema. Después completa el integrador del bloque.

## Compilar

Necesitas un compilador de C++17 o posterior, por ejemplo GCC (`g++`). No se necesitan bibliotecas externas ni un sistema de construcción para empezar.

En PowerShell, desde la carpeta del ejemplo:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

En Linux o macOS puedes sustituir `programa.exe` por `programa`. Si usas Clang, sustituye `g++` por `clang++`.

El ejemplo [Headers](02_POO/08_Headers/README.md) tiene dos archivos de implementación y se compila así:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Producto.cpp -o programa.exe
./programa.exe
```

Cada ejemplo es un programa independiente. **No compiles todos los `main.cpp` juntos.** Los `#include` relativos de los ejemplos con headers funcionan desde la carpeta del ejemplo. Los archivos de demostración se crean en el directorio desde el que ejecutas el programa.

## Dónde van los punteros

Primero aprende dirección, contenido y vida del dato en [Punteros básicos](01_Programacion_Estructurada/09_Punteros_Basicos/README.md). Luego estudia propiedad manual y `unique_ptr` en [POO](02_POO/07_Memoria_y_Punteros/README.md). Finalmente aplica enlaces y liberación de nodos en [Listas ligadas](03_EDD/03_Listas_Ligadas/README.md), y propiedad con `unique_ptr` en árboles.

## Estructura

```text
Español/
├── 01_Programacion_Estructurada/
│   ├── 01_Hola_Mundo/
│   ├── 02_Variables_y_Tipos/
│   ├── 03_Entrada_y_Salida/
│   ├── 04_Condicionales/
│   │   ├── 01_If_Else/
│   │   └── 02_Switch/
│   ├── 05_Ciclos/
│   │   ├── 01_For/
│   │   ├── 02_While/
│   │   └── 03_Do_While/
│   ├── 06_Funciones/
│   │   ├── 01_Parametros_y_Retorno/
│   │   └── 02_Referencias/
│   ├── 07_Arreglos/
│   │   ├── 01_Unidimensionales/
│   │   └── 02_Matrices/
│   ├── 08_Cadenas/
│   ├── 09_Punteros_Basicos/
│   ├── 10_Archivos/
│   ├── 11_Recursion/
│   ├── 12_Const_y_Headers/
│   └── 13_Integrador/
├── 02_POO/
│   ├── 01_Clases_y_Objetos/
│   ├── 02_Encapsulamiento/
│   ├── 03_Constructores_y_Destructores/
│   ├── 04_Composicion/
│   ├── 05_Herencia/
│   ├── 06_Polimorfismo/
│   ├── 07_Memoria_y_Punteros/
│   │   ├── 01_New_y_Delete/
│   │   └── 02_Unique_Ptr/
│   ├── 08_Headers/
│   ├── 09_DAO/
│   │   ├── 01_DAO_en_Memoria/
│   │   └── 02_DAO_en_Archivo/
│   └── 10_Integrador/
├── 03_EDD/
│   ├── 01_Complejidad/
│   ├── 02_Vectores/
│   │   ├── 01_Crear_y_Recorrer/
│   │   ├── 02_Insertar_y_Eliminar/
│   │   └── 03_Vector_de_Objetos/
│   ├── 03_Listas_Ligadas/
│   │   ├── 01_Simplemente_Ligada/
│   │   ├── 02_Doblemente_Ligada/
│   │   └── 03_Circular/
│   ├── 04_Pilas/
│   │   ├── 01_Con_Vector/
│   │   └── 02_Con_Stack/
│   ├── 05_Colas/
│   │   ├── 01_Con_Queue/
│   │   └── 02_Cola_de_Prioridad/
│   ├── 06_Arboles/
│   │   ├── 01_Arbol_Binario/
│   │   ├── 02_Binario_de_Busqueda/
│   │   └── 03_Recorridos/
│   ├── 07_Tablas_Hash/
│   ├── 08_Grafos/
│   │   ├── 01_Representacion/
│   │   ├── 02_BFS/
│   │   ├── 03_DFS/
│   │   └── 04_Dijkstra/
│   ├── 09_Ordenamiento/
│   │   ├── 01_Burbuja/
│   │   ├── 02_Seleccion/
│   │   ├── 03_Insercion/
│   │   ├── 04_Merge_Sort/
│   │   ├── 05_Quick_Sort/
│   │   └── 06_STD_Sort/
│   ├── 10_Busqueda/
│   │   ├── 01_Lineal/
│   │   └── 02_Binaria/
│   ├── 11_Const_y_Headers/
│   └── 12_Integrador/
└── 04_Proyecto_Integrador/
    ├── datos/
    ├── include/
    └── src/
```

En las carpetas de temas simples hay `README.md` y `main.cpp`. En los temas divididos hay un `README.md`, subcarpetas con ejemplos y un `main.cpp` integrador junto a ellas. Los headers adicionales se incluyen donde se necesitan y se reutilizan en los integradores.

## Alcance de esta primera ruta

Los ejemplos manuales de listas y algoritmos existen para entender su funcionamiento. Para aplicaciones habituales, prefiere los contenedores y algoritmos estándar cuando cubran el requisito. Los árboles de esta ruta son binarios y ABB sin balanceo; el grafo trabaja con pesos no negativos; el DAO de archivo es una demostración de instantáneas, sin base de datos ni acceso concurrente. El cuarto bloque todavía no implementa la aplicación conjunta.


## Convenciones y revisión

Los ejemplos utilizan `using namespace std;`. Los headers limitan esa directiva a `namespace curso`, y los `.cpp` que los utilizan añaden `using namespace curso;`. Consulta la [revisión de buenas prácticas](BUENAS_PRACTICAS.md).

La [versión inglesa](../English/README.md) contiene la misma ruta, con nombres, mensajes, comentarios y guías traducidos.

## Const y headers por bloque

- [Funciones y constantes en programación estructurada](01_Programacion_Estructurada/12_Const_y_Headers/README.md).
- [Objetos y métodos const en POO](02_POO/08_Headers/README.md).
- [Consultas de estructuras de solo lectura en EDD](03_EDD/11_Const_y_Headers/README.md).
