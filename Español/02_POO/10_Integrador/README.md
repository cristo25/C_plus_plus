# Integrador: una biblioteca con objetos

## Qué aprenderás

Usa composición para encapsular un DAO y herencia con dos vistas para practicar polimorfismo. Reutiliza el header del tema anterior. `unique_ptr` administra la vista y el destructor virtual permite liberar su tipo concreto.

## Analogía

La biblioteca tiene un bibliotecario y puede mostrar el catálogo en dos ventanillas: una detallada y otra resumida.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `1: Aprender C++` y `Libros: 1`. Las dos vistas existen aquí para practicar despacho virtual; no hacen falta interfaces nuevas para cada clase.

## Practica

Agrega una vista que muestre solo los títulos y reutiliza el mismo DAO.

La creación y la carga respetan el mismo límite de 10 000 libros.
