# Learn C++ / Aprende C++

Empezamos por elegir un idioma / We start by choosing a language:

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

In each language we find a general guide and 84 programs. Their `.cpp` and `.h` comments explain the ideas with analogies and give us exercises. The general guide shows us how to compile them. We follow the numbered lessons and then each topic's integration example. We learn headers in all three blocks and DAO in OOP. At the end, we bring the ideas together in a campus library and routes application.

We also combine arrays, pointers, references, classes, structs and nodes, from simple examples to an integration program: [English Combining Concepts](English/03_DSA/13_Combining_Concepts/README.md).

## Good Practices

We can read the [Good Practices Guide](English/GOOD_PRACTICES.md) to learn habits for sharing and maintaining code.

## Compilation & Execution

We use a C++17 compiler such as `g++`. In the [English guide](English/README.md#compile-and-run) we find the commands to compile each example from its own folder. When a lesson has another `.cpp` file, we include it in the same command.

If we use Visual Studio Code, we can also run single-file examples with the optional **Code Runner** extension:

1. **Installation:**
   * We can download it from the Marketplace: [Code Runner for VS Code](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
   * Or we can open the Command Palette in VS Code (`Ctrl + P`) and run:
     ```bash
     ext install formulahendry.code-runner
     ```

2. **Usage:**
   * We open a single-file `.cpp` example and press `Ctrl + Alt + N` (or click **Play**) to compile and run it.

> **Note:** For examples that use `cin`, we enable **Run in Terminal** in the extension settings (`Ctrl + ,` → search for `code-runner.runInTerminal`).

## Integrated Project

We build a campus library and routing system: [Integrated Project Guide](English/04_Integrated_Project/README.md).

---

# Español

En cada idioma encontramos una guía general y 84 programas. Sus comentarios en `.cpp` y `.h` explican las ideas con analogías y nos dejan ejercicios. En la guía general vemos cómo compilarlos. Seguimos las lecciones numeradas y luego el integrador de cada tema. Aprendemos headers en los tres bloques y DAO en POO. Al final reunimos las ideas en una aplicación de biblioteca y rutas de campus.

También combinamos arreglos, punteros, referencias, clases, structs y nodos, desde ejemplos sencillos hasta un integrador: [Combinación de Conceptos](Español/03_EDD/13_Combinacion_de_Conceptos/README.md).

## Buenas prácticas

Podemos leer la [guía de buenas prácticas](Español/BUENAS_PRACTICAS.md) para aprender hábitos que facilitan compartir y mantener el código.

## Compilación y ejecución

Usamos un compilador de C++17, como `g++`. En la [guía en español](Español/README.md#compilar-y-ejecutar) encontramos los comandos para compilar cada ejemplo desde su carpeta. Cuando una lección tiene otro archivo `.cpp`, lo incluimos en el mismo comando.

Si usamos Visual Studio Code, también podemos ejecutar los ejemplos de un solo archivo con la extensión opcional **Code Runner**:

1. **Instalación:**
   * Podemos descargarla desde el Marketplace: [Code Runner para VS Code](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
   * O podemos abrir la paleta de comandos en VS Code (`Ctrl + P`) y ejecutar:
     ```bash
     ext install formulahendry.code-runner
     ```

2. **Uso:**
   * Abrimos un ejemplo `.cpp` de un solo archivo y presionamos `Ctrl + Alt + N` (o hacemos clic en **Play**) para compilarlo y ejecutarlo.

> **Nota:** Para ejemplos que usan `cin`, activamos **Run in Terminal** en la configuración de la extensión (`Ctrl + ,` → buscamos `code-runner.runInTerminal`).

## Proyecto integrador

Construimos un sistema de biblioteca y rutas de campus: [Guía del Proyecto Integrador](Español/04_Proyecto_Integrador/README.md).
