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

- In practice <code>only a few</code> variables in each function may be kept in registers.


### Block Structure
- Variables could be declared in blocks. But functions are  not able to be defined. Static variable is initialized only the first time the block is entered

### Initialization
- **External** and **static** variables are <code>guaranteed</code> to be initialized to zero, **automatic** and **register** variables have undefined(garbage) initial values.

- When the size of the array is ommited,(during initialization) the compiler will compute the length by counting the initializers, of which there are 12 in this case.

### Recursion
- C functions may be used recursively, that is a function may call itself either directly or indirectly.


### The C Preprocessor
- C provides certain language facilities by means of a preprocessor, which is conceptually a separate first step in compilation. Mostly used directives are below
    1. #include
    2. #define

- include Syntax
``` C
#include "filename"             // compiler search for that file in current directory
#include <filename>             // compiler search this in include paths.
```

- define Syntax
``` C
#define name replacement text
```

- As long as the arguments are treated consistently, macros will serve for <code>any</code> data type.

- <code>#undef</code> is used to make sure that routine is function, but not a macro.
- <code>#</code> preprocessor operator provides a way to concatenate actual arguments during macro expansion


- Conditional Inclusion provides a way to include code selectively, depending on the value of conditions evaluated during compilation
    1. #if      -> evaluates a constant integer expression
    2. #else    -> comes after if 
    3. #elif    
    4. #endif
    5. #ifdef
    6. #ifndef
    