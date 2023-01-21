# NOTES

- History of computation goes to Charles Babbage and his analytical engine.(1822)

- Then U.S goverment used concept from analytical engine and created for modern computer ENIAC!

- Then John Von Neuman developed subroutines and make repeating loops, if then structure. Which lead to Short code binary programming language.

- This lead to first major programming language FORTRAN. 

- Then this lead to COBOL -> first programming language turlly English-like!

- Same time COBOL developed, Algol was developed. This programming language introduced many programming techniques still being used today!

- Then Pascal was developed in order to use structured programming.

- Meanwhile over at AT&T Bell Labs in 1972 Dennis Ritchie was working on two languages : B(for Bell) and BCPL(Basic Combined Programming Language)

- Inspired by Pascal, Mr.Ritchie developed the C Programming language.

- In 1983, C programmer Bjarne Stoustroup developed object-oriented programming(OOP) extensions to the C language and created C++ programming language.

- C++ is %95 original C.

- All C language programs must have a **main()** function!


### C language Source code syntax
-   #include <something.h>
    int main()
    {
        statement;
        statement;
        return(0);
    }

### Tools Needed to Programming(Communicate) with Computer
1. A Programming Language   -> Translate human intentions to computer instructions!
2. An editor, to create source code files
3. A compiler and linker, to create program files

### C Programming Language
- Consist of the major parts!
    1. Keywords
    2. Functions
    3. Operators

- Basically programming with C is, mix and match those items together to make computer obey your intentions!

- C language has 32 keywords.

![Keywords in C](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/C_Keywords.PNG) 

- Functions are small routines or software machines that do specific tasks.

- In C *precompiler* directives are which those starts with **#** symbol.

- When we create source code, compiler goes a head and convert it to **object** file. Then all object files linked together via linker and used C library to create executable binary

- For example in FreeBSD to link math functions : **gcc -lm math_program.c -o math_program**

- Avoid nested comments in C.

#### Errors in C
- There are generally 4 types of erros in C
    1. Compiler errors          -> Usually syntax errors 
    2. Linker errros            -> Missing module or function errors
    3. Runtime errors           -> Flaw in your program flow or thinking.
    4. Bugs                     -> Unexpected behavior when program runing. Hardest one to deal with it.
