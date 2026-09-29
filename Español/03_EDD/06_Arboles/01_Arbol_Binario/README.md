# Árbol binario: raíces, hijos y hojas

## Qué aprenderás

Un árbol conecta nodos sin ciclos. La raíz no tiene padre; una hoja no tiene hijos. Un árbol binario admite como máximo dos hijos por nodo. No todo árbol binario ordena sus valores.

## Analogía

Un organigrama empieza en un responsable y se divide en ramas. En este ejemplo cada responsable tiene como máximo dos subordinados.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Nodos: 3`. Los `unique_ptr` liberan los hijos junto con la raíz.

## Practica

Dibuja el árbol, identifica sus hojas y agrega un nieto.
