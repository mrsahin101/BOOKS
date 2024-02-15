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