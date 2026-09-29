# Learn C++ / Aprende C++

Elige el idioma / Choose your language:

- [English](#english): General guide covering Structured Programming, OOP, and DSA with explanations and code examples.
- [Español](#español): Guía general de Programación Estructurada, POO y EDD con explicaciones y bloques de código.

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

---

# English

Each language has one general guide and 84 programs with explanations, analogies, run instructions, and exercises in `.cpp` and `.h` comments. Additional OOP and DSA guides compare topics and variants. Numbered subtopic programs and their integration examples preserve the learning sequence. All three blocks teach headers; OOP introduces DAO. The final project is a campus library and routes application with a persistent catalog and a guide organized by sections.

An additional learning route combines arrays, pointers, references, classes, structs, and nodes, from simple examples to an integration program: [English Combining Concepts](English/03_DSA/13_Combining_Concepts/README.md).

## Good Practices

Check the [Good Practices Guide](English/GOOD_PRACTICES.md) to learn habits that streamline team collaboration and project maintenance.

## Compilation & Execution

A C++17 compiler (such as `g++`) is required. Compile each example from its own folder; opening comments in each file specify the command and any additional `.cpp` files required.

To easily compile and run C++ programs directly from Visual Studio Code, using the **Code Runner** extension is recommended:

1. **Installation:**
   * Download it from the Marketplace: [Code Runner for VS Code](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
   * Or install it directly inside VS Code by opening the Command Palette (`Ctrl + P`) and running:
     ```bash
     ext install formulahendry.code-runner
     ```

2. **Usage:**
   * Open any `.cpp` file and press `Ctrl + Alt + N` (or click the **Play** button in the top right corner) to compile and run it instantly.

> **Note:** For interactive programs that use `cin` or require user input via the keyboard, make sure to enable the **Run in Terminal** option in the extension settings (`Ctrl + ,` -> search for `code-runner.runInTerminal` and check the box).

## Integrated Project

Campus library and routing system: [Integrated Project Guide](English/04_Integrated_Project/README.md).

---

# Español

Cada idioma tiene una guía general y 84 programas con explicaciones, analogías, instrucciones de ejecución y ejercicios en los comentarios de sus archivos `.cpp` y `.h`. Las guías adicionales de POO y EDD comparan temas y variantes. Los programas por subtema y sus integradores conservan el orden numerado. Los tres bloques enseñan headers; DAO se estudia en POO. El proyecto final es una aplicación de biblioteca y rutas de campus, con catálogo persistente y guía por secciones.

Una ruta adicional combina arreglos, punteros, referencias, clases, structs y nodos, desde ejemplos sencillos hasta un integrador: [Combinación de Conceptos](Español/03_EDD/13_Combinacion_de_Conceptos/README.md).

## Buenas prácticas

Consulta la [guía de buenas prácticas](Español/BUENAS_PRACTICAS.md) para aprender hábitos que facilitan trabajar en equipo y mantener proyectos.

## Compilación y ejecución

Necesitas un compilador de C++17, como `g++`. Cada ejemplo se compila desde su propia carpeta; sus comentarios iniciales indican el comando y los archivos `.cpp` adicionales cuando corresponda.

Para compilar y ejecutar fácilmente los programas de C++ desde Visual Studio Code, se recomienda usar la extensión **Code Runner**:

1. **Instalación:**
   * Descárgala desde el Marketplace: [Code Runner para VS Code](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
   * O instálala directamente en VS Code abriendo la paleta de comandos (`Ctrl + P`) y ejecutando:
     ```bash
     ext install formulahendry.code-runner
     ```

2. **Uso:**
   * Abre cualquier archivo `.cpp` y presiona `Ctrl + Alt + N` (o haz clic en el botón de **Play** arriba a la derecha) para compilarlo y ejecutarlo al instante.

> **Nota:** Para programas interactivos que usen `cin` o soliciten entrada por teclado, asegúrate de activar la opción **Run in Terminal** en la configuración de la extensión (`Ctrl + ,` -> busca `code-runner.runInTerminal` y márcala como activada).

## Proyecto integrador

Sistema de biblioteca y rutas de campus: [Guía del Proyecto Integrador](Español/04_Proyecto_Integrador/README.md).
