# Const and headers in DSA

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Const and headers in DSA

We will query a collection without changing it. With const vector<int>& we receive another label for the same vector, but only for reading. In Queries.h we announce the function; in Queries.cpp we traverse the values and count those above a limit. We need neither copying nor sorting. Doubling the data doubles the visits. We add only a counter and a few variables.

[Commented program](main.cpp).

**Practice.** We will write a query program split across files.

- We will declare a function in a.h and write it in a.cpp.
- We will receive a vector through const vector<int>&.
- We will count values below a limit using a loop.
- We will return zero for an empty vector.
- We will check that the original data stayed unchanged.

[Back to the general guide](../../README.md).
