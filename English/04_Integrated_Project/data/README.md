# Catalog data

The program creates `catalog.txt` when the first change is committed. `.tmp` holds a candidate write and `.bak` retains the previous state during replacement. These generated files are excluded from Git.

Requests, history and the undo stack only live during the session. Use `--demo` to practice without writing data. See the [project guide](../README.md).
