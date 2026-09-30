# Memory and pointers in OOP

## Manual dynamic memory

We will create a box while the program is running. With new int(42) we reserve space for an integer and receive its address. We store that address in number and read 42 through *number. The box does not disappear merely because we stop using the pointer variable: here we must release it exactly once with delete. We then set number to nullptr to avoid reusing the address. We never use delete on an ordinary local variable or follow a pointer after releasing its data.

[Commented program](01_New_and_Delete/main.cpp).

## Ownership with unique_ptr

We will give one tool responsibility for releasing the box. With unique_ptr from <memory>, we keep that responsibility alongside the address. make_unique creates the data; get lends us its address for reading. That borrowed pointer must not release it. When the program ends, owner releases the integer automatically. This helps us avoid forgetting delete.

[Commented program](02_Unique_Ptr/main.cpp).

## Memory and pointers in OOP

We can picture Student as a box holding a name and observer as the address of that box. We create the student with make_unique and borrow its address with get. With observer->getName() we follow that address to read the name. Before calling reset we stop using the borrowed address and set observer to nullptr. Then reset releases the student. The borrowed pointer never deletes it.

[Commented program](main.cpp).

**Practice.** Write an integrated program with an object managed by unique_ptr.

- Create a class with a name and a const query.
- Create an object with make_unique and observe it with get.
- Display its name using ->.
- Clear the observer before calling reset.
- Explain which variable released the object.

[Back to the general guide](../../README.md).
