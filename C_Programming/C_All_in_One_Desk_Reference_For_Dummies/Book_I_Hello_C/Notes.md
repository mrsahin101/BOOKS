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


- Char size : -127 to 128 -> Or when unsigned : 0 to 255;

- When we taking input with getchar, we have to clean up input buffer. fflush(stdin); -> for Windows, fpurge(stdin) -> for Unix based machines!

- gets() doesnt considered as safe function. for demostration purposes it could be used but when it comes to using in serious programs, it could generates security flaws.

- When we getting input from keyboard we getting it like string. If we want to work with it(in-case of numbers), we should convert it to integer or float. 
    1. atoi() -> Converts string to integer ( ASCII to integer)
    2. atof() -> Converts string to float (ASCII to float)

#### C Language Text I/O Functions
-    ![Text I/O Functions](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/C_Text_IO_Functions.PNG) 
     ![Text I/O Functions](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/C_Text_IO_Functions_2.PNG) 

#### C Language Comparison Operators
-    ![C Comparison operators](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/C_Comparison_Operators.PNG) 

#### If else syntax
-   if(condition)
    {
        statements;
    }   
    else
    {
        statements;
    }

#### FOR loop
- It consist 3 parts.
1. A setup or initialization
2. The part that loops, which is the statements that are repeated
3. The condition on which the loop finishes

- forever loop syntax with for : for(;;);

- for(init[,...]; as_long_as; do_this[,...])

#### Which situation we should use constants! Author recommendations
1. The number of times certain loops need to repeat
2. The size of storage location or buffer
3. The maximum number of items a character in a game can carry
3. The maximum number of items a character in a game can carry
4. The number of tries some has to retype a password
5. The number of seconds of inactivity before the program hangs up the modem
6. The size of the screen. And so on...

- When defining constants we use big letters. So later in code its easier to identify them.

- **const** keyword is C++ convetion introduced at 1990s. In C rather use **#define** directive.

- Define directive is so flexiable we can define anything with it.

#### Math Operators
- ![Basic Math Operators](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/Basic_Math_Operators.PNG) 

- Order of predence :
    1. Multiplication
    2. Division
    3. Addition
    4. Subtraction

#### Unary Operators
- Plus(+) basically has no effec on variable or immediate value.
- Minus(-) basically multiples variable or immediate value with -1.

#### Pre-Post Increment/Decrement
- b = 5 icin
- Increment :   
    1. Pre-Increment : a = ++b;         -> a = 6, b = 5;
    2. Post-Increment : a = b++;        -> a = 5, b = 6;
- Decrement
    1. Pre-Decrement : a = --b;         -> a = 4, b = 4;
    2. Post-Decrement : a = b--;        -> a = 5, b = 4;

- Warning : ++a++ syntax not allowed!

#### C Cryptic Operators
- ![Basic Math Operators](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_I_Hello_C/Images/C_Cryptic_Operators.PNG) 