# REFERENCE MANUAL

### Introduction
- This manual describes the draft submitted to ANSI on 31 October 1988.
- ANSI Standart Link : https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub160.pdf
- This manual is interpretation, not the standart itself.


### Lexical Conventions
- A program consists of one or more translations units stored in files. Translated in several phases. First, do low-level lexical transformations.(Preprocessing) When preprocessing done, the program has been reduced to sequences of **tokens**.

#### Tokens
- There are six class of tokens.
    1. **Identifiers**
    2. **Keywords** 
    3. **Constants**
    4. **String Literals** 
    5. **Operators**
    6. **Other separators** 

#### Comments
- The characters /* introduce a comment, which terminates with */. Comments **dont** nest, and they **dont** occur within **string** or **character literals**

#### Identifiers
- Identifier is sequence of letters and digits. The first character must be letter(underscore(**_**) counts as letter). 
- Identifiers with external linkage are more restricted, implementations may make as few as first six characters as significant, and may ignore case distinction.

#### Keywords
- Keywords are listed below
    | **auto**     	| **double** 	| **int**      	| **struct**   	|
    |----------	    |--------	    |----------	    |----------	    |
    | **break**    	| **else**   	| **long**     	| **switch**   	|
    | **case**     	| **enum**   	| **register** 	| **typedef**  	|
    | **char**     	| **extern** 	| **return**  	| **union**    	|
    | **const**    	| **float**  	| **short**    	| **unsigned** 	|
    | **continue** 	| **for**    	| **signed**   	| **void**     	|
    | **default**  	| **goto**   	| **sizeof**   	| **volatile** 	|
    | **do**       	| **if**     	| **static**   	| **while**    	|

#### Constants
- There are several kinds of constants.
    1. **Integer** constant
    2. **Character** constant
    3. **Floating** constant
    4. **Enumeration** constant

- Float constants type is determined by the suffix, **F** or **f** makes it float, **L** or **l** makes it long double, otherwise its double.


### Syntax Notation
- Not much here to take note of.

### Meaning of Identifiers
- Identifiers and names refers to variety of things.
    1. Functions
    2. Tags of Structures
    3. Unions
    4. Enumerations
    5. Members of structures or unions
    6. Enumerations constants
    7. Typedef names
    8. Objects

- Object is something stored in memory. Its Interpretation depends on two main attributes. Its storage class and its type.

#### Storage Class
- There are 2 types of classes.
    1. **automatic** : This are local to block, and discarded on exit. Objects declared **register** are automatic.
    2. **static** : Maybe be local, or external to all blocks but in either case retain their values across exit from and reentry to function blocks. The objects declared outside of all blocks, at same level as functions definitions, are always static.With extern gives them external linkage.

#### Basic Types
- char, int(short int, int, long int), float(float, double, long double)

#### Derived Types
- Basically infinitely derived types from basic types could be derived.

#### Type Qualifiers
- Objects may have additional qualifiers.
    1. **const** : Declaring object will not change.
    2. **volatile** : Declaring object will have some special properties relevant to optimization.

### Objects and Lvalues
- Object : is named region of storage.
- lvalue : is an expression referring to an object

### Conversions 
- Some operators may, depending on operands, cause conversion of value of operand to another type.

#### Integral Promotion
- If an int can represent all the values of the original type, then the value is converted to int, otherwise the value is converted to **unsigned int**. This called integral promotion.

#### Integral Conversions
- When any integer is converted to a signed type, the value is unchaged if it can be represented in the new type and is implemented defined otherwise.

#### Integer and Floating
- When converting from integer to float, if result in rage, either conversion works or rounded to next close one. 
- When converting from float to integer behavior is undefined. Some mistakes could occur. with negative floats behaviour is undefined.

#### Floating Types
- When a less precise floating value converted to an equally or more precise floating type, the value is **unchanged**. 
- When a more precise floating value converted to a less precise floating type, and the value is within representable range, the result may be either the next higher or next lower representable number. If result is out of range, the behavior is undefined.

#### Arithmetic Conversions
- Many operators cause conversions and yield result types in similiar way. This called **usual arithmetic conversions**
    1. If either operands is **long double**, the other is converted to **long double**.
    2. If either operands is **double**, the other converted to **double**.
    3. If either operands is **float**, the other converted to **float**.
    4. If either operands is **unsigned long int**, the other is converted to **unsigned long int**.
    5. If either operands is **long int**, the other is converted to **long int**
    6. If either operands is **unsigned int**, the other is converted to **unsigned int**

#### Pointers and Integers
- Null Pointer is 0. Or by other saying, casting 0 by any pointer type gives null pointer.
- A pointer to one type may be converted to a pointer to another type.

#### Void
- **Void** denotes a non-existent value.

#### Pointers to Void
- Any pointer to an object may be converted to <code>void *</code> without loss of information.
- This plays role of generic role.

### Expressions
- The precedence of expression operators is the same as the order of the major subsections.

#### Pointer Generation
- Not much usefull info here.

#### Primary Expressions
- Primary expressions are identifiers, constants, strings, or expressions in parentheses.

#### Postfix Expressions
- The operators in postfix expressions group left-to-right.
    1. **Array References** : Postfix expression followed by expression in square brackets is postfix expression denoting array reference. Expression E1[E2] is identical by *((E1) + E2)
    2. **Function Calls** : A function call is postfix expression, called the function designator, followed by parentheses containing a possibly empy, comma-separated list of assignment expressions. 
    3. **Structure References** : . is used to access structure members, -> is used to with pointers. E1->MOS is same as (*E1).MOS
    4. **Postfix Incrementation** : A ++ or -- operator is postfix expression. Operand must be lvalue.

#### Unary Operators
- Unary operators group right-to-left
    1. **Prefix Incrementation Operators** : Unary expression preceded bby <code>++</code> or <code>--</code> is a unary expression. Operand must be lvalue.
    2. **Address Operator** : The unary <code>&</code> operator takes the address of its operand.
    3. **Indirection Operator** : The unary <code>*</code> operator denotes indirection, and returns the object or function to which its operand points.
    4. **Unary Plus Operator** : The operand of the unary <code>+</code> operator must habe arithmetic type, and the result is the value of the operand.
    5. **Unary Minus Operator** : The operand of the unary <code>-</code> operator must habe arithmetic type, and the result is the negative value of the operand.
    6. **Ones Complement Operator** : The operand of the <code>~</code> operator must be integer, and the result is the ones complement of its operand.
    7. **Logical Negation Operator** : The operand of the <code>!</code> operator must have arithmetic type or be a pointer. It negates the result. 1 if 0 or 0 if 1.
    8. **Sizeof Operator** : The sizeof operator yields the number of bytes required to store an object of the type of its operand.

#### Casts
- A Unary expression preceded by the parenthesized name of a type causes conversion of the value of the expression. <code>(type-name) cast-expression</code>.

#### Multiplicative Operators
- The multiplicative operators <code>*, /, %</code> group left-to-right.

#### Additive Operators
- The additive operators <code>+</code> and <code>-</code> group left-to-right.

#### Shift Operators
- The shift operators <code><<</code> and <code>>></code> group left-to-right.

#### Relational Operators
- Relational operators group left-to-right, but in fact this is not usefull. <code> <, >, <=, >=</code> all yield 0 if the specified relation is false and 1 if it is true.

#### Equality Operators
- <code>==(equal to)</code> and <code>!=(not equal to)</code> operators are analogous to the relational operators except for their lower precedence.

#### Bitwise AND Operator
- The usual arithmetic conversions are performed, the result is the bitwise AND function of the operands.

#### Bitwise Exclusive OR Operator
- The usual arithmetic conversions are performed, the result is the bitwise exclusive OR function of the operands.

#### Bitwise Inclusive OR Operator
- The usual arithmetic conversions are performed, the result is the bitwise inclusive(just or) OR function of its operands.

#### Logical AND Operator
- The && operator groups left-to-right. Returns one when both operands compare equal, 0 if not.

#### Logical OR Operator
- The <code>||</code> operator groups left-to-right. It returns 1 if either of its operands compares equal, else 0

#### Conditional Operator
- Syntax : <code> logical-OR-expression ? expression : conditional expression</code>

#### Assignment Expressions
- Assignment operators all group right-to-left. Assignment operators : <code>=, *=, /=, %=, +=, -=, <<=, >>=, &=, ^=, |=</code>

#### Comma Operator
- Comma is evaluated left-to-right and the value of the left expression is discarded. Value of the left expression is discarded. The type and value of the result are the type and value of the right operand.

#### Constant Expressions 
- Syntactically a constant expression is an expression restricted to a subset of operators.

### Declarations
- Declarations specify the interpretation given each identifier.

#### Storage Class Specifiers
- Storage class specifiers : 
    1. **auto**
    2. **register**
    3. **static**
    4. **extern**
    5. **typedef**

#### Type Specifiers
- Type specifiers are : <code>void</code>, <code>char</code>, <code>short</code>, <code>int</code>, <code>long</code>,<code>float</code>, <code>double</code>, <code>signed</code>, <code>unsigned</code>, <code>struct-or-union-specifier</code>, <code>enum-specifier</code>, <code>typedef-name</code>,
- Type qualifiers are : <code>const</code>, <code>volatile</code>.

#### Structure and Union Declarations
- A structure is object consisting of a sequence of named members of various types. A union is an object that contains, at different times, any one of several members of various types. Structure and union specifiers have the same form.
- Tags allow definition of self-referential structures, a structure or union may contain a pointer to an instance.
- Since padding used with structure members, there could be some holes between members.
- We can fit couple structure inside union and use them and their members. But only one a time a structure is valid.

#### Enumerations
- Enumerations are unique types with values ranging over set of named constants.
- If no = sign appear, values starts from 0. 

#### Declarators
- The structure of declarators resembles that of indirection, function and array expressions the grouping is the same.

#### Meaning of Declarators
- A list of declarators appears after a sequence of type and storage class specifiers.
- A declarator is read as an assertion that when its indetifier appears in an expression of the same form

##### Pointer Declarators
- Example :  int i, *pi, *const cpi;

##### Array Declarators
- Example : D1[constant-expression]
- An array may be constructed from an arithmetic type, from a pointer, from a structure or union or from another array.

##### Function Declarators
- Example D1(parameter-type-list)
- If parameter type list ends with and ellipsis,(",...") then the function may accept more arguments than the number of parameters explicitly described.
- The only storage class specifier permitted in a parameters declaration specifier is **register**, and this specifier is ignored unless the function declarator heads a function definition.

#### Initialization
- When an object is declared, its init-declarator may specify an initial value for the identifier being declared.
- A static object not explicitly initialized is initialized as if it(or its members) were assigned the constant 0. The initial value of an automatic object not explicitly initialized is undefined.

#### Type Names
- In several contexts, it is necessary to supply the name of a data type. This accomplished using a type name, which is syntactically a declaration for aan object of that type omitting the name of the object.

#### Typedef
- Declarations whose storage class specifier is **typedef** dont declare objects, instead they define identifiers that name types.
- Example : <code>typedef long Blockno, *Blockptr;</code>

#### Type Equivalence
- Two type specifier lists are equivalent if they contain the same set of type specifiers, taking into account that some specifiers can be implied by others.

### Statements
- Statements are executed in sequence. Statements are executed for their effect, and don not have values.

#### Labeled Statements
- The only use of an identifier label is as a target of **goto**
- Labels in themselves do not alter the flow of control

#### Expression Statement
Most statements assingments or functions calls.

#### Compound Statement
- Several statements can be used where one is expected, the compound statement is provided.

#### Selection Statements
- Selection statements choose one of several flows of control.
- In both form of the if statement, the expression, which must have arithmetic or pointer type.

#### Iteration Statements
- do-while, while, for statements are iteration statements, which specify looping.

#### Jump Statements
- goto, continue, break, return are identifiers for jump statements. Transfer control unconditionally

### External Declarations
- The unit of input called translation unit, which consist of sequence of external declarations, which are either declarations or function definitions

#### Function definitions
- extern or static are allowed.

#### External Declarations
- The term **external** refers to their locaation outside functions, and is not directly connected with the extern keyword, the storage class for an externally-declared object may be left empty, or it may be specfied as **extern** or **static**.

### Scope and Linkage
- A program need not all be compiled at one time, the source text may be kept in several files containing translation units, and precompiled routines may be loaded from libraries. 
- Communication among the functions of program may be carried out both through calls and through manipulation of external data.

#### Lexical Scope
- The lexical scope of an object or function identifier in an external declaration begins at the end of its declarator and persists to the end of the translation unit in which it appears.

#### Linkage
- Within a translation unit, all declarations of the same object or function identifier with internal linkage refer to the same thing, and the object or function is unique to that translation unit.

### Preprocessing
- A preprocessor performs macro substitution, conditional compilation, and inclusion of named files.
- Lines begin with <code>#</code>, perhaps preceded by whitespace, communicate with this preprocessor.
- Preprocessor takes several logically successive phases.

#### Trigraph Sequences
- The character set of C source programs countained within seven-bit ASCII. In order to enable programs to be represented in the reduced set, all ocurences of the following trigrap sequences are replaced by the corresponding single character.

#### Line Splicing
- Lines that end with the backslash character \ are folded by deleting the backslash and the following newline character.

#### Macro Definition and Expansion
- Example #define identifier token-sequence
- The preprocessor to replace subsequent instances of the identifier with the given sequence of tokens.
- #undef identifier causes the idenifiers preprocessor definition to be forgetten. It is not erroneous to apply #undef to an unknown identifier.

#### File Inclusion
- #include "filename" causes the replacement of that line by the entire contents of the file filename.
- #include files may be nested

#### Conditional Compilation
- Parts of a program may be compiled conditionally.

#### Line Control
- #line uses preprocessor for error diagnostic.

#### Error Generation
- A preprocessor line of the form **#error token-sequence** causes the processor to write a **diagnostic** message that includes the token sequence

#### Pragmas
- A control line of the form **#pragma token-sequence** causes the processor to perform an implemented dependent action.

#### Null Directive
- A preprocessor line of the form **#** has no effect

#### Predefined Names
- Several identifiers are predefined, and expand to produce special information
    1. __LINE__ : A decimal constant containing the current source line number
    2. __FILE__ : A string literal containing the name of the file being compiled
    3. __DATE__ : A string literal containing the date of compilation, in te form "Mmm dd yyyy"
    4. __TIME__ : A string literal containing the time of compilation, in the form "hh:mm:ss"
    5. __STDC__ : The constant 1. It is intended that this identifier be defined to be 1 only in standart-conforming implementations.

### Gramar
- C has small grammar.
