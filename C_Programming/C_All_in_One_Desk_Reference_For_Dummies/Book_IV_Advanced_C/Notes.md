# NOTES

- Before using any variables, always remember initializing them.

- **sizeof** keyword returns size of given variable.How many bytes of that variable it returned.

## POINTERS

- & operator is used for getting adrres of variable. **%p** is pointer placeholder.

- Pointer variable holds memory address. Syntax : type* pointer_variable;

- Pointers work in chunks the same size as their variable type.

- When we doing pointer arithmetic what compiler sees :  pointer + (addition count * sizeof(variable type))

- Pointer variables must be assigned an address before they can be used. They must be initialized.

- *pointer notation we can dereference the pointer.

- When we increment pointer by some number, its address actually incremented by size of memory type of pointer.

## Binary And Operations
- Nibble is half-byte. (4-bit).

![Hex to Binary Conversion](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_IV_Advanced_C/Images/Hex_to_Binary.PNG) 

![Bitwise Operators](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_IV_Advanced_C/Images/Bitwise_Operators.PNG) 

- Shift right syntax : result = value >> steps;

- With Shifting to right or left 0 feeded from otherside, but with rotation shifted bit goes back to otherside of number.

![Pointer Shortcuts](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_IV_Advanced_C/Images/Pointer_Parentheses.PNG) 

![Array Notation](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_IV_Advanced_C/Images/Pointer_Array_Notation.PNG)

- Important Notes about Arrays and Pointers.
    1. Pointers are variables. You can change their content and change whatever lives at memory addresses they point to.
    2. Arrays are stuck in memory. You **can't** move them. You can **re-assign** them. You **can't** add more elements.
        What you can do is to change their variables, but that's about it.3


## Strings And Pointers
- There are no such a thing as string in C. It's all pointer.

- Strings aren't variables. They are single-character arrays.

- The last character in a string or array is the **NULL** character.

- If you declare string with this syntax : char *variable -> U shouldn't modify the string. Otherwise you get segmentation fault and program crashes. The right way to do this :
    const char *variable is the syntax.

- array[n] = *(pointer + n)     -> Both of this notations means same thing.

![Pointer Notation](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_IV_Advanced_C/Images/Pointer_Notation.PNG)


### Basic Rules of Pointers
- Initialize a pointer before you use it.
- Without the asterisk, the pointer is a memory address.
- With the asterisk, the pointer represent what lives at that address.
- Functions that accept pointers accept memory locations, not values.


### Memory Allocation
- Malloc syntax : pointer = (type *) malloc(size);
- Malloc creates memory for desired size and type.
- Realloc reallocates memory (previous created by malloc) for given size and type.
- free, frees allocated memory.

### Time in Computers
- Computer keeps time in UTC. 
- tm structure inside time.h
    struct tm {
        int tm_sec;     /* seconds      [0 - 60]                */ 
        int tm_min;     /* minutes      [0 - 59]                */
        int tm_hour;    /* hours        [0 - 23]                */
        int tm_mday;    /* day          [1 - 31]                */
        int tm_mon;     /* month        [0 - 11]                */
        int tm_year;    /* year         [year since 1900]       */
        int tm_wday;    /* weekday      [0 - 6]                 */
        int tm_yday;    /* day of year  [0 - 365]               */
        int tm_isdst;   /* DST          [-1, 0, 1]              */
        /* There may be another definitions here depending on compiler */
    };


- This snippet could be used for generating precise delays. In order of seconds

#define DELAY 0.1

void pause(void)
{
    time_t then;
    time(&then);
    
    while(difftime(time(NULL), then) < DELAY);
}


## Building Big Programs
- Creating small modules is best way to do it.

- **extern** keyword is used to share functions and variables between files.

- **gcc -c module.c** is used to to compile single file to its object file.

- **gcc moda.o modb.o modc.o ...** is used for linking all object files together. This creates a.out or a.exe file.

- **gcc moda.o modb.o modc.o ... -o prog** creates prog.exe 

- Sharing variables between modules done with **extern** keyword. Syntax : **extern type name**

- Write your project in modules. This way it will be more readable and easier to manage.

