# DAO: separating data access

## In-memory DAO and CRUD

We will bring storing, finding, updating and removing books together in BookDAO. We can picture a catalog keeper: we request a book by its id, a number identifying it. DAO is the usual name for a class dedicated to data access. Here we keep books in a vector, so they disappear when the program ends. find lends a pointer to a book, or returns nullptr if it is missing. We check before reading it; after changing the catalog we find it again because the vector may move its books.

[Commented program](01_In_Memory_DAO/main.cpp).

## Persisting a DAO in a file

We will save the catalog in a file so we can retrieve it later. First we ask the DAO to write its books and then read them into another catalog. Each run writes the current catalog to the file again. If data is invalid, we report it without replacing the catalog with incomplete data. To try that case we use istringstream from <sstream>: it reads text held in memory as if it came from a file. This lets us test damaged input without damaging the real file.

We can picture the file as a notebook. First we write how many books we have; then we use one line for each book's number and another for its title. If we save one book with id 7, the notebook looks like this:

```text
1
7
C++ step by step
```

When we read those lines, we fill another catalog. Because the title uses its whole line, it can contain spaces and quotation marks.

[Commented program](02_File_DAO/main.cpp).

## DAO: separating data access

We will follow the catalog's whole workflow: create books, change a title, remove a book and restore saved data. Here we use stringstream from <sstream> as a temporary notebook in memory: we can write into it and read back without creating a disk file. We then try input with repeated ids. Our rule is simple: if we cannot restore every record correctly, we keep the catalog we already had.

[Commented program](main.cpp).

**Practice.** Write an integrated program that manages and restores books.

- Create three books, change a title and remove one.
- Save the result and load it into a second catalog.
- Compare restored books with the originals.
- Try a duplicate id and incomplete input.
- Keep previous data if loading fails.

[Back to the general guide](../../README.md).
