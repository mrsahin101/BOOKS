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
