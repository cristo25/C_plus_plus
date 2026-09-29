# Proyecto integrador — lo desarrollaremos después

Aquí construiremos **un solo programa**, distribuido en headers y archivos de implementación, que aplique los conocimientos de los tres bloques anteriores. Por ahora dejamos su estructura y objetivos; todavía no hay `main.cpp` ni aplicación implementada.

```text
04_Proyecto_Integrador/
├── include/   Declaraciones (.h): modelos, estructuras y acceso a datos
├── src/       Implementaciones (.cpp) y futuro main.cpp
└── datos/     Archivos usados por el programa
```

## Qué aplicaremos

- Funciones, validación de entrada, archivos y manejo de errores.
- Clases, encapsulamiento, composición y propiedad de recursos con RAII.
- Herencia y polimorfismo cuando el problema tenga variantes reales.
- Vectores, listas, pilas, colas, árboles y grafos según las operaciones del proyecto.
- Ordenamiento, búsqueda y explicación del costo de las decisiones.
- DAO para concentrar la consulta y persistencia de datos.
- Separación entre headers, implementación y punto de entrada.

Cuando retomemos este bloque, elegiremos el problema concreto y construiremos el programa por etapas. Los integradores anteriores son ejercicios terminados de cada tema; este será la aplicación conjunta.

La creación y la carga respetan el mismo límite de 10 000 libros.
