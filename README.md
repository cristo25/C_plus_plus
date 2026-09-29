# Learn C++ / Aprende C++

Elige el idioma / Choose your language:

- [Español](Español/README.md): 73 ejemplos, analogías, ejercicios e integradores.
- [English](English/README.md): the same 73 examples, analogies, exercises and integration programs.

```text
Learn C++/
├── Español/
│   ├── 01_Programacion_Estructurada/
│   ├── 02_POO/
│   ├── 03_EDD/
│   └── 04_Proyecto_Integrador/
└── English/
    ├── 01_Structured_Programming/
    ├── 02_OOP/
    ├── 03_DSA/
    └── 04_Integrated_Project/
```

Cada versión mantiene el mismo orden de aprendizaje, programas por subtema y un main.cpp integrador en los temas divididos. DAO y headers se estudian en POO. El proyecto final queda para después en ambos idiomas.

Both versions follow the same learning sequence, with individual subtopic programs and a parent-topic integration main.cpp. OOP introduces DAO and headers. The final project remains reserved for later in both languages.

## Revisión / Review

Consulta las [buenas prácticas](Español/BUENAS_PRACTICAS.md) o su [versión inglesa](English/GOOD_PRACTICES.md). Los ejemplos usan `using namespace std;`; los headers contienen esa directiva dentro del namespace del curso.

## Compilar / Compile

Necesitas un compilador de C++17, como `g++`. Cada ejemplo se compila desde su propia carpeta; sigue su README para incluir los archivos `.cpp` adicionales cuando corresponda.

Use a C++17 compiler such as `g++`. Compile each example from its own folder; follow its README to include additional `.cpp` files when required.

## Estilo / Style

Los ejemplos usan bloques con llaves, instrucciones en líneas separadas y const cuando el dato no cambia. Cada bloque muestra cómo dividir programas en headers e implementación. Las lecciones individuales no usan assert; las comprobaciones de algoritmos se concentran en sus integradores.

Examples use braces, separate statement lines and const values where appropriate. Each block shows header/implementation separation. Individual lessons have no assertions; algorithm checks are concentrated in integration programs.
