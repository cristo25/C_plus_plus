# Insertar y eliminar en vectores

## Qué aprenderás

`insert` y `erase` reciben iteradores. `begin()` apunta al primer elemento y `end()` representa el límite posterior al último, que no se desreferencia. Insertar o borrar en medio desplaza elementos: O(n). Una realocación invalida todos los punteros, referencias e iteradores; un borrado invalida desde la posición eliminada.

## Analogía

Para abrir un hueco en medio del cajón debes mover las cosas de las secciones siguientes.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `20`. Comprueba que existe la posición antes de construir un iterador como `begin() + 1`.

## Practica

Elimina todos los elementos iguales a 20 con `remove` y `erase`. Consulta la diferencia entre mover al final y borrar.
