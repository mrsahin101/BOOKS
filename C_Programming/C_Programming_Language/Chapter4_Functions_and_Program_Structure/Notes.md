# Functions and Program Structure

- Functions break large computing tasks into **smaller** ones, and enable people to build on what others have done instead of starting over from scratch

### Basic of Functions
- Syntax :
``` C
return-type function-name(argument declarations)
{
    declerations and statements
}
```

### Functions Returning Non-Integers
- Functions can return any type : Float, int, void, pointers, structures, etc...

### External Variables
- Function can use external variables. Automatic variables are internal to function and they dissapear when function left.

### Scope Rules
- The functions and external variables that make up a C program not need to all be compiled at the <code>same time</code>.

- <code>extern</code> keyword used for declaration variables from different files.

- Definition and Declaration
``` C
/* Definition, its need to be done only 1 time */
int sp;
double val[MAXVAL];

/* Declaration in other files, Could be done many times in different files */
extern int sp;
extern double val[];

```

- Array sizes must be **specified** with the definition, but are optional with an extern declaration.


### Header Files
- Header files allows us to separate code between file, it helps us with modularity but it makes it harder to maintain the code between many header files.

### Static Variables
- **Static** declaration, applied to external variable or function, limits the scope of that object to rest of thee source file being compiled. This also allow us with not conflict names with other files.

- Normally function names are global and visible to any part of the entire program. If a function declared **static**, however its name is invisible outside of the file in which its declared.

- **Static** declaration can also be appleid to internal variables. They are local to particular function, but they also <code>remain in existence</code> rather than coming and going each time the function is activated.

### Register Variables
- A register declaration advises the compiler that the variable in question will be heavily used. Compiler is free to ignore the advice