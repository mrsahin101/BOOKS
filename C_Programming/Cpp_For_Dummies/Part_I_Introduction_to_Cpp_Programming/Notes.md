# INTRODUCTION TO C++ PROGRAMMING

## Chapter 1 -> Writing Your First C++ Program
- C++ consist of two basic elements : 
    1. **Semantics** : This is a vocabulary of commands that humans can understand and that can be converted into machine language, fairly easily.
    2. **Syntax** : This is a language structure(or grammar) that allows humans to combine these C++ commands into a program that actually does something.

- Semantics as building blocks of your C++ program and the syntax as the correct way to put them together.

- Template for your C++ Programs
``` cpp
// Template - provides a template to be used as the starting point

// The following include files define the majority of functions that any fiven program will need
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char * pszArgs[])
{
    // your C++ code starts here
    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
```
- All C++ programs are ased on what are known as C++ statements. A statement is **single set** of commands.
- C++ is case sensitive language.
- A variable must begin with the letters A through Z or a through z.
- Try to make variable names short but descriptive.

## Chapter 2 -> Declaring Variables Constantly
- The concept of variable is borrowed from mathematics.
- Lopping off the fractional part of a number is called truncation or rounding off.
- To declare real number in C++, we can use **float** for single precision, **double** for double precision
- Floating point numbers suffer from round-off error problems.
- When couting involved, C++ is avoid using floating-points.

- Variable Types : 
    1. **int** : A simple counting number, either positive or negative.
    2. **unsigned int** : A counting number thats only non negative
    3. **long** : A potentially larger version of int.
    4. **unsigned long** : A nonnegative long integer
    5. **float** : A single precision real number
    6. **double** : A standart floating point variable.
    7. **char** : A single character stores alphabetic or digital character.
    8. **string** : A string of characters forms a sentence or phrase
    9. **bool** : The logic value. Either true or false.

- An expression in which the two operands are not the same type is called a mixed-mode expression.
- Converting larger value type into a smaller value type is called **demotion**

- **Naming Conventions** : Each character prefixed with letter to show its variable type. 
    1. **n** : int
    2. **l** : long
    3. **f** : float
    4. **d** : double
    5. **c** : character
    6. **sz** : string

## Chapter 3 -> Performing Mathematical Operations
- Mathematical Operators : +, -, ++, --, *, /, %, +, -, =, *=, %=, +=, -=
- The expression is complete statement, Thus following is complete statement : 1;
- When operators of same precedence appears in the same expression, they are evaluated from left to right.

## Chapter 4 -> Performing Logical Operations
- C++ retains high degree of compatibility between bool and int in order to support the older programs.
- **&&** and **||** called short circuits.

## Chapter 5 -> Controlling Program Flow
- There are basically three types of flow control statements
    1. The Branch       -> If-else
    2. The Loop         -> for, while, do-while
    3. The Switch       -> switch-case

- Page 73. Nesting Control Commands

