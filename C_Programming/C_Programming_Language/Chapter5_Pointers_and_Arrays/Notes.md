# Pointers and Arrays
- A pointer is a variable that contains the <code>address</code> of a variable. 


### Pointers and Addresses
- The unary operator <code>&</code> gives the address of an object. This operator can be applied to <code>variables and array elements</code>. Cannot be applied to <code>expressions, constants, or register variables</code>

- The unary operator <code>*</code> is the indirection or dereferencing operator, when applied to pointer it access content of address that pointer points to. 

- When doing pointer arithmetic, we should be carefull


### Pointers and Function Arguments
- Since C passes arguments to function by value, there is no direct way for the called function to alter a variable in the calling function. Workaround for this is pass variable by its address.


### Pointers and Arrays
- In C, anything done by arrays could also be done with pointers. Pointers is faster but harder to understand.

``` C
    int *pa;
    int array[10];
    pa = &array[0];

    /* *(pa + 1) is points to array[1]; Also pa[i] is identical to *(pa + i);
     * (*pa) + 1 increments content of array[0]
     */ 
```

### Address Arithmetic
- If p is a pointer to some element of an array, **p++**  increments p to point to the next element, and **p += i** increments it to point i elements beyond where it currently does.

- It's <code>not</code> legal to add two pointers, or to multiply or divide or shift or mask them or add **float** or **double** to them.Or assign them different type of pointer. Except void pointer.


### Character Pointers and Functions
- Strings are terminated with null character -> **'\0**.


### Pointer Arrays; Pointers to Pointers
- Since pointers are variables themselves, they can be stored in arrays just as other variables can.


### Multi-dimensional Arrays
- Arrays could be two dimensional or multi dimensional.

### Initialization of Pointer Arrays
- Multi-dimensional arrays and array of pointer sometimes confused with each other. But when creating multi-dimensional array, compiler creates memory for it in compile time, but when it comes to array of pointer, memory allocation doesnt perform in compile time.


### Command-Line Arguments
- We can pass command-line arguments to C program. Conventionally called <code>argc</code> for argument count, <code>argv</code> for array of character strings that contain the arguments one per string.

### Pointers to Functions
- In C, a function itself is not a variable, but it is possible to define pointers to functions. Function pointers, can be assigned, placed in arrays, passed to functions, and returned by functions and so on.

### Complicated Declarations
- C syntax can be cryptic sometimes. For example,
``` C
int *f();       /* f: function returning pointer to int */
int (*pf)();    /* pf : pointer to function returning int */
```
- dcl : converts C declaration into a word description.
- Some examples : 
``` C
/* argv : pointer to pointer to char */
char **argv; 

/* daytab : pointer to array[13] of int */
int (*daytab)[13];    

/* daytab : array[13] of pointer to int */
int *daytab[13]; 

/* comp : function returning pointer to void */
void *comp();     

/* comp : pointer to function returning void */
void (*comp)();            

/*x : function returning pointer to array[] of pointer to function returning char */
char (*(*x())[])();

```