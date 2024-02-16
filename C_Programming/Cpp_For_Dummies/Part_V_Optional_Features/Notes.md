# OPTIONAL FEATURES
- C++ is feature rich language.

## Chapter 23 -> A New Assignment Operator, Should you Decide to Accept It
- C++ enables the programmer to define the operators for classes that the programmer has created in addition to these intrinsic operators. This called **operator overloading**.
- The programmer cannot overload the ., ::, *(derefrence) and & operators
- The programmer cannot invent new operators. You cannot invent the x $ y.
- The format of the operators cannot be changed. Thus, you cannot define an operation %i because % is binary operator
- The operator precedence cannot change. A program cannot force operator+ to be evaluated before operator*.
- The operators cannot be redefined when applied to intrinsic types
- Generally operators overloading introduces more problems than it solves.
- The insertion and extraction operators << and >> are nothing more than the left and right shift operators overloaded for a set of input/output classes.
- Unlike other operators, the assignment operator cannot be overloaded with a nonmember function.

## Chapter 24 -> Using Stream I/O
- Stream I/O is based on overloaded versions of **operator>>()** -> called **extractor** and **operator<<()** -> called inserter
- **cin** : istream -> Standart input
- **cout** : ostream -> Standart output
- **cerr** : ostream -> Standart error output
- **clog** : ostream -> Standart printer output

- endl object automatically flushes the output buffer.

## Chapter 25 -> Handling Errors - Exceptions
- Sometimes functions dont work properly. We need some kind of error reporting. This is called exceptions.
- A functions **try** to get through piece of code. If the code detects a problem, it **throws** an error indication that the calling function must **catch**.
- When the **throw** occurs, C++ first copies the thrown object tosome neutral place. It then begings looking for the end of the current try block. If a try block is not found in the current function, controll passes to the calling function. A search is then made of that function. This goes until exception found. This process called **unwinding** the stack. Objects goes out of scope destructed.
- **throw** can handle any type of object.

## Chapter 26 -> Inheriting Multiple Inheritance
- Some classes, represent the blending of two classes into one. C++ allows a derived class to inherit from more than one base class. This called **multiple inheritance**.
- When variable names collide, they inherit both. And it should be accessed via :: notation. But it is undesirable to use it like this. Rather try to factor the problem.
- Some object-oriented practitioners don't multiple inheritance is good idea. Some languages, doesn't even support it

## Chapter 27 -> Tempting C++ Templates
- T is unknown type. Syntax : maximum<T>(T, T);
- Creating a function from a template is called **instantiating** the template.
- Arguments must match.
- No code is generated for a template. Code is generated after the template is converted into a concrete class or function.
- A template class cannot be compiled and checked for errors until it is converted into a real class.