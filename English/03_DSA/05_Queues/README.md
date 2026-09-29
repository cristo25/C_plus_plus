# Queues

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## FIFO queue

We will serve a line in arrival order. With queue from <queue>, we add at the back using push, inspect the first using front and remove it using pop. We can picture people waiting at a service desk. Before serving we check empty. We also call “first in, first out” FIFO; those letters simply abbreviate the same rule.

[Commented program](01_With_Queue/main.cpp).

## Priority queues and heaps

We will serve by importance instead of arrival. priority_queue puts the highest-priority value at the top: for integers this is normally the largest. To choose the smallest, such as a cost, we use greater<int>, a comparison rule from <functional>. We can picture a hospital's urgent cases: arriving first does not always mean being served first. With top we inspect the next value and with pop we remove it; data must be present.

[Commented program](02_Priority_Queue/main.cpp).

## Queues

We will put the same values into a normal queue and a priority queue. After storing 2, 9 and 4, the first keeps that order; the second serves 9 first. This helps us decide which rule an application needs: respecting arrival or choosing by importance. Changing the structure changes the service rule even with identical data.

[Commented program](main.cpp).

**Practice.** Write an integrated request-service program.

- Store the same priority numbers in queue and priority_queue.
- Display each full service order.
- Add a new request after serving one.
- Explain which fits a ticket desk and which fits urgent cases.

[Back to the general guide](../../README.md).
