# Memory and pointers in OOP

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Manual dynamic memory

We will create a box while the program is running. With new int(42) we reserve space for an integer and receive its address. We store that address in number and read 42 through *number. The box does not disappear merely because we stop using the pointer variable: here we must release it exactly once with delete. We then set number to nullptr to avoid reusing the address. We never use delete on an ordinary local variable or follow a pointer after releasing its data.

[Commented program](01_New_and_Delete/main.cpp).

## Ownership with unique_ptr

We will give one tool responsibility for releasing the box. With unique_ptr from <memory>, we keep that responsibility alongside the address. make_unique creates the data; get lends us its address for reading. That borrowed pointer must not release it. With move from <utility>, we transfer responsibility to newOwner and leave the old owner empty. When the new owner ends, the integer is released automatically. This helps us avoid forgetting delete.

[Commented program](02_Unique_Ptr/main.cpp).

## Memory and pointers in OOP

We will apply pointers to a Student object. We create the student with make_unique and lend its address with get. With observer->getName() we follow that address and call a student function; -> means following the pointer and using the dot. Calling reset releases the student. The borrowed address then becomes unusable: we must stop using it and set it to nullptr. The borrowed pointer is never responsible for deleting the student.

[Commented program](main.cpp).

**Practice.** Write an integrated program with an object managed by unique_ptr.

- Create a class with a name and a const query.
- Create an object with make_unique and observe it with get.
- Display its name using ->.
- Clear the observer before calling reset.
- Explain which variable released the object.

[Back to the general guide](../../README.md).
