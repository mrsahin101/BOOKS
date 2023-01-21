# NOTES

- Before C there was B language. C created after that.

- C is mid-level language. It get advantages of High level languages (readability) and also it get speed of low level languages. That's why C is really good language!

- C created in AT&T Bell Labs. By Dennis Ritchie.

#### C Development Cycle :)

1. Come up with an idea for a program.
2. Use an editor to write the source code.
3. Compile the source code and link the program by using the C compiler.
4. Weep bitterly over errors (optional).
5. Run the program and test it.
6. Pull out hair over bugs (optional).
7. Start over (required).

#### Source Code -> Executable:
- 
    1. Source code converted to object file(.obj or .o)
    2. Linker goes a head and link all those object files together to create executable file!
    3. Executable file is what processor can understand and work with!
    4. If any error occur during process compiling stops and user must fix errors first!

- Basicly there are 4 step for C program to work
    1. Write source code and save it
    2. Compile!(convert to object file)
    3. Link all object files with linker!
    4. Run the program!

- Funny phrase of programming : %10 writing code and algorithms, %90 finding errors and debugging :)

- C language has 2 types of errors : 
    1. Warnings -> this type of errors are not fatal and compiler will compile the code. But its good practice to fix warnings as well
    2. Errors   -> This types of errors are fatal errors and compiler will not compile the code!

- Another way of grouping error could be like this :
    1. Compiler errors  
    2. Linker errors
    3. Run-time errors
    4. Bugs

- Each program must have starting point(aka entry point!). In C language every program starting point is main function.

- C language has 32 keywords!
    1. auto     
    2. break
    3. case
    4. char
    5. const
    6. continue
    7. default
    8. do
    9. double
    10. else
    11. enum
    12. extern
    13. float
    14. for
    15. goto
    16. if
    17. int 
    18. long
    19. register
    20. return
    21. short
    22. signed
    23. sizeof
    24. static
    25. struct
    26. switch
    27. typedef
    28. union
    29. unsigned
    30. void 
    31. volatile
    32. while

- Also superset of C, there another language called C++, which has some keywords. For that case avoid using those 32 C keywords and those listed below which used by C++
    1. asm                  
    2. bool
    3. catch
    4. class
    5. const_cast
    6. delete
    7. dynamic_cast
    8. false
    9. friend
    10. inline
    11. mutable
    12. namespace
    13. new
    14. operator
    15. private
    16. protected
    17. public
    18. reinterpret_cast
    19. template
    20. this
    21. throw
    22. true
    23. try
    24. typeid
    25. using
    26. virtual

- also there are 2 keyword in C deprecated. Avoid using them
    1. fortran
    2. entry

- All keywords are lower case letters and C language is case sensitive. So gotta keep that in mind when coding! :)  

- Syntax of printf function is : **printf(“format_string”[,var[,...]]);**

- In C we can use /* */ for multiple line comments or // for single line comments

- Stay away from puts and always use printf function.