# Searching

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Linear search

We will search by checking a drawer one slot at a time. We do not need to sort first: we move until we find the value or reach the end. We may visit all n elements (O(n)). To return the result we use optional: a small box from <optional> that either holds a position or is empty. We check that it holds something before reading *position. Position zero is valid and must not be confused with “not found”.

[Commented program](01_Linear_Search/main.cpp).

## Binary search

We will search an already sorted list. We look at the middle and decide which half could contain the number. We can picture numbered pages: for a smaller page, we discard the right half. Reducing 16 candidates to 8, 4, 2 and 1 takes four divisions; starting with 32 adds just one (O(log n), where n counts candidates and log n describes the divisions). This version finds the first match. We receive a position or an empty result and check which before reading it.

[Commented program](02_Binary_Search/main.cpp).

## Searching

We will compare one-by-one search with halving search. First we search unsorted data, then sort and try both methods on the same vector. The number stays the same, but sorting can change its position. We also count the preparation: building a sorted list is extra work, even if searching within it afterward is faster.

[Commented program](main.cpp).

**Practice.** Write an integrated searching program.

- Search several values with linear search.
- Create a sorted copy for binary search.
- Compare whether both find each value.
- Show how sorting changes positions.
- Also try an empty vector.

[Back to the general guide](../../README.md).
