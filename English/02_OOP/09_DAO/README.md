# DAO: separating data access

Study in-memory CRUD and persistence. The integration example combines CRUD and serialization using a string stream without writing files. Definitions inside classes are implicitly inline. This DAO uses linear queries and allows at most 10,000 books; a database is a later step when needed.

## Study order

1. [In-memory DAO and CRUD](01_In_Memory_DAO/main.cpp)
2. [Persisting a DAO in a file](02_File_DAO/main.cpp)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.
