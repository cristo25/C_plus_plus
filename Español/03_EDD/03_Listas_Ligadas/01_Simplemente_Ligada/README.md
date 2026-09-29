# Lista simplemente ligada

## Qué aprenderás

Cada nodo guarda un dato y la dirección del siguiente. El último apunta a `nullptr`. No hay acceso directo por índice: recorrer y buscar cuestan O(n). El header implementa inserción al final, eliminación de la primera coincidencia y liberación de todos los nodos.

## Analogía

Una búsqueda del tesoro: cada tarjeta contiene un dato y la pista hacia la siguiente. La última dice «fin».

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `10 30`. La lista posee los nodos: no se permite copiarla. El destructor los libera.

## Practica

Dibuja los enlaces antes y después de eliminar el primer nodo. Agrega un método `contiene`.
