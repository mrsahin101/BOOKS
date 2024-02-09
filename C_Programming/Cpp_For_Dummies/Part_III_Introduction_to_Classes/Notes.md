# INTRODUCTION TO CLASSES

## Chapter 11 -> Examining Object-Oriented Programming
- Object-Oriented Programming relies on two principles : 
    1. **Abstraction**
    2. **classification**

- In OOP the level of detail at which you working is called the **level of abstraction**

- Functional approach has some problems
    1. **Too Complex**
    2. **Not Flexible**
    3. **Not Reusable**

## Chapter 12 -> Adding Class to C++
- C++ calls the structure that combines multiple pieces of data into a single object a **class**
- We define class : then when we create object from that blue print, we can say thats **instance** of that class. To creating process, it called **instantiate**

## Chapter 13 -> Making Classes Work
- Class could have some active properties like functions. It's also called methods, or member functions.
- How method know which object called from : The answer is implicitly caller object adress passed to the method. This implicit naming also know as **this** keyword.
- the :: is called **scope resolution operator**.
- inline functions are executed without function jumps.
- The function is defined outside the class is said to be an outline function.
- Member functions can be overloaded in the same way that conventional functions are overloaded.

## Chapter 14 -> Point and Stare at Objects
- ps->gpa is equivalent to  (*ps).gpa
- To change object values from different function, it must be passed by reference or adress. Also some objects are large. Passing objects with value means copying whole thing once again.
- The area used to pass arguments to function is **stack**.
- if some variables are declared on stack,(in function) then when we return from function, they goes out of stack. Instead we should declare it on heap.

``` cpp
class LinkableClass
{
    public:
        LinkableClass* pNext;
        // other members of the class
};
```
page 197