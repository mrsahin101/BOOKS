# NOTES

- Functions basically remove redundancy from programs.

## Functions
- Syntax for functions : 
    type name(arguments..)
    {
        statement(s);
    }

- When naming function; their name must start with letter, not a number.  Cant use space between the name. either use underline or write it all together.

- Function names must be descriptive.

- Some compilers may forbid you use function names starting with underline.

- Avoid naming function same as C **keywords**

- main() is reserved for first function(entry point.)

- When dividing 2 integer number, if we want accurate result; must cast one of number to float or double. otherwise computer does integer division.

- Return syntax : return(something); -> this returns value from function. Type of variable depends on function type.

- In C language main has to be defined as int type. Returnig **0** means that given task was completed succesfully. Any other than **0** value means some sort of error condition was happened!. Before ANSI standart main function was commonly decleared as void.

### include keyword
- Syntax : #include <filename> or when you make own header : #include "filename" -> When using this, compiler looks in same directory as your source code file.

- #define, #include are preprocessor directives.

- We include and write some defines and prototypes in header files. But actual instruction does the job are in .c files.

- #defines are very good way to make abstraction and make code more readable.

- #define TRUE 1 -> #define FALSE (!TRUE)   or #define FALSE 0 -> #define TRUE (!FALSE)     -> this both statment for bool operations are viable.

- Macros are for including some part of source code. With macros we can compile 2 different executable from same source code!
    1. #if
    2. #else
    3. #endif
    4. #ifdef
    5. #ifndef
    6. #line

#### printf Function
- It displays text. Displays escape sequences. Can display variables with % conversion character.
- Syntax : printf("text");
- For example in some console to clear screen escape sequence is : \x1b[2J
- printf formal syntax : printf("format_string",[var[,...]]);
- In case needing some more information about printf and its formatting, refer to compiler documentation.

#### printf Escape sequences. 

![ Escape Sequences](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_IV_C_Level/Images/printf_Escape_Sequences.PNG)
![  Escape Sequences](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_IV_C_Level/Images/printf_Escape_Sequences_2.PNG)

#### printf Conversion Characters
![ Conversion Characters](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_IV_C_Level/Images/printf_Conversion_Characters.PNG)


#### Math Library
- pow(n,p) function takes n to power p;
- sqrt(n) function takes square root of n;
- For more math function refer to math library and documentation of the compiler!

#### Small note about post increment & decrement
- when we do b = a++; we actualy first make b = a then a = a + 1; 

#### srand() syntax
- void srand((unsigned)seed);
- try avoid seeding srand with number 1. 
- modulus = big % little; -> basically gives us big / little calculation remainder.

## Order of Predence in C
1. Multiplication
2. Division
3. Modulus
4. Addition
5. Substraction
