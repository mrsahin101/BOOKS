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