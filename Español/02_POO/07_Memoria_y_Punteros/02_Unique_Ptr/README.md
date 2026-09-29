# Propiedad con unique_ptr

## Qué aprenderás

`unique_ptr` tiene un propietario y libera el objeto automáticamente. `make_unique` lo construye. `move` transfiere la propiedad; no copies un `unique_ptr`. Usa punteros crudos cuando solo observes un objeto y su vida esté garantizada.

## Analogía

Una llave única administra el casillero. Cuando entregas la llave, el dueño anterior deja de tenerla.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `42`. `shared_ptr` existe para propiedad realmente compartida; no es necesario para este ejemplo.

## Practica

Usa `reset()` y comprueba que el propietario queda vacío. No uses el observador después.
