# Stacks

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## A stack using vector

We will use a vector like a stack of plates: we add and remove only at the top. With push_back we add, with back we inspect the last value, and with pop_back we remove it. The last item in is the first out. Before reading or removing we check that the stack is not empty. If we need the removed value, we save it before pop_back because that operation does not return it.

[Commented program](01_With_Vector/main.cpp).

## The stack adapter

We will use stack, the <stack> tool that directly provides stack operations. push adds at the top, top reads the top, and pop removes it. We can picture an undo history: the last action we performed is the first one we examine. Here we show which action would be undone; removing it from history does not itself change a real document.

[Commented program](02_With_Stack/main.cpp).

## Stacks

We will compare a stack built with vector against one using stack. We put 1, 2 and 3 into both and remove from the top. In both, 3 must come out first. We are practicing the removal order: that rule defines a stack even when we use different storage tools.

[Commented program](main.cpp).

**Practice.** Write an integrated program comparing two stacks.

- Add the same values to a vector and a stack.
- Inspect both tops before removing.
- Check that each step removes the same value.
- Finish with both stacks empty.

[Back to the general guide](../../README.md).
