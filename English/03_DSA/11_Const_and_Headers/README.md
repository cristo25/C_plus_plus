# Const and headers in DSA

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Const and headers in DSA

We will query a collection without changing it. With const vector<int>& we receive another label for the same vector, but only for reading. In Queries.h we announce the function; in Queries.cpp we traverse the values and count those above a limit. We need neither copying nor sorting. Doubling the data doubles the visits (O(n), with n elements). We add only a counter and a few variables (O(1) additional memory).

[Commented program](main.cpp).

**Practice.** Write a query program split across files.

- Declare a function in a .h and write it in a .cpp.
- Receive a vector through const vector<int>&.
- Count values below a limit using a loop.
- Return zero for an empty vector.
- Check that the original data stayed unchanged.

[Back to the general guide](../../README.md).
