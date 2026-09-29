# Learn C++ / Aprende C++

Elige el idioma / Choose your language:

- [Español](Español/README.md): guía general de Estructurada, POO y EDD con explicaciones y bloques de código.
- [English](English/README.md): the same structured programming, OOP and DSA guide, with explanations and code examples.

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

Cada idioma tiene una guía general y 73 programas con explicaciones, analogías, instrucciones de ejecución y ejercicios en los comentarios de sus archivos `.cpp` y `.h`. Las guías adicionales de POO y EDD comparan temas y variantes. Los programas por subtema y sus integradores conservan el orden numerado. Los tres bloques enseñan headers; DAO se estudia en POO. El proyecto final queda para después.

Each language has one general guide and 73 programs with explanations, analogies, run instructions and exercises in `.cpp` and `.h` comments. Additional OOP and DSA guides compare topics and variants. Numbered subtopic programs and their integration examples preserve the learning sequence. All three blocks teach headers; OOP introduces DAO. The final project remains reserved for later.

## Revisión / Review

Consulta las [buenas prácticas](Español/BUENAS_PRACTICAS.md) o su [versión inglesa](English/GOOD_PRACTICES.md). Los ejemplos usan `using namespace std;`; los headers contienen esa directiva dentro del namespace del curso.

## Compilar / Compile

Necesitas un compilador de C++17, como `g++`. Cada ejemplo se compila desde su propia carpeta; sus comentarios iniciales indican el comando y los archivos `.cpp` adicionales cuando corresponda.

Use a C++17 compiler such as `g++`. Compile each example from its own folder; its opening comments provide the command and any additional `.cpp` files required.

## Estilo / Style

Los ejemplos usan bloques con llaves, instrucciones en líneas separadas y const cuando el dato no cambia. Cada bloque muestra cómo dividir programas en headers e implementación. Las lecciones individuales no usan assert; las comprobaciones de algoritmos se concentran en sus integradores.

Examples use braces, separate statement lines and const values where appropriate. Each block shows header/implementation separation. Individual lessons have no assertions; algorithm checks are concentrated in integration programs.
