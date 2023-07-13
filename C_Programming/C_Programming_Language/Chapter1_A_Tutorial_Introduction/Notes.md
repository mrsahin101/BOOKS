# A Tutorial Introduction
- C language is general purpose language.
- Closely associated with Unix.
- C language is relatively **low level** language.
- In this revision of C(ANSI C), multi-programming not supported, only **single-thread** control flow is supported.
- c language retains this basic philosophy, **programmers know what they are doing, it only requires that they state their intentions explicitly**

- **Symbolic Constants**
``` C
#define name replacement_text
```
- In C all functions arguments are passed **by value**. But doesn't work for arrays. Arrays are passed by reference.

- Each local variable comes to existence only when function is called, and disappears when function is exited. This is knowns as <code>automatic variables</code>

- It is good practice to collect all variables with extern in same header file and include that header file where its needed.

- <code>Definitions</code> refers to the place where the variable created or assigned storage. <code>Declaration</code> refers to places where the nature of the variable is stated but no storage is allocated.