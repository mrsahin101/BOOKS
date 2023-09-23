# Structures
- A structure is collection of **one** or **more** variables, possibly of different types, **grouped together** under a single name for convenient handling.
- Structures help to organize complicated data, particularly in **large programs**, because they **permit** a group of related variables to be treated as a **unit** instead of as separate entities.
- Structures could be **copied**, **assigned**, **passed to functions**, and **returned by functions**

## Basics of Structures
- The keyword <code>struct</code> introduces a structure declaration, which is list of declarations enclosed in braces. An optional name called a structure tag may follow the word struct. It could be used as a shorthand for the prt of the declaration in braces.
- A structure **member** and ordinary variable can have the **same name** without conflict, since they can always be distinguished by context.
- Furthermore the **same member names** may occur in different structures.
- Structure member could be referred in form : <code>structure-name.member</code>

## Structures and Functions
- Only legal operations on a structure are copying it or **assigning to it as a unit**, **taking its address with &**, and **accessing its members**.
- If a **large structure** is to be passed to a function, it is generally more efficent to pass a **pointer** than to copy the whole structure.
- When using pointers, It is necessary in to write (*pp).x because the precedence of structure member operator **.** is higher than *.

- There is also <code>p->member-of-structure</code> syntax could be used.

- Example : 
``` C
struct 
{
    int len;
    char *str;
}*p;

++p->len;       // increments len, not p
(+pp)->len      // increments p before accesing len    
```

## Arrays of Structures
- Array of structures could help us grouping items a like together.

- **sizeof** operator can't be used with pre-processor directive **#if**.

## Pointers to Structures
- Basically we can do operations with pointers to structures.

## Self-Referential Structures
- Structures can have pointer to same type of them.

## Table - Lookup
- Look up table basically means, Hash-Map.

## Typedef
- Typedef used to create new data type names.

## Unions
- Union may hold (at **different times**) objects of different types and sizes. 
- Union size will be large enough to hold largest of given types.

## Bit Fields
- To use Data efficently bit-fields are used.
- This kind of programs makes it hard to make it portable.