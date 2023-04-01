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

