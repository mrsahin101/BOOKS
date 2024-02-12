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
## Chapter 15 -> Protecting Members : Do Not Disturb
- The members of a class can be marked **protected**, which makes them inaccessible outside the class. Also **private** is same as protected.
- The members of a class can be marked **public**, makes them accessible outside of the class.
- Protected members are used for abstraction.(Just coder should be care about interface, not implementation details.)
- To use a class, all you need to know its **public members**, what they do, what their arguments are.
- As conditions change, or bugs are found, you can change internals of class without(most of the time) need to change external interface of class.
- To let non-member function to access protected area, you can declare function as **friend**
- A single function can be declared as friend of two classes at same time. But binding classes is normally considered bad because it makes one class dependent on the other.
- A member function of one class may be declared a friend of another class.
- An entire class can be named a friend of another.

## Chapter 16 -> Why Do you Build Me Up, Just to Tear Me Down, Baby=
- A class describes a type of thing. An object is one of those things. In another saying, An object is an instance of a class
- **constructor** is automatically called when object of given class is created. Constructor initialize the object to valid initial state.It carries the same name as the class to differentiate it from other members of class. Constructor cant be invoked manually. Constructor can access protected members of class.
- **destructor** : Handles destruction of the object. Its basically de-initialize all objects created. If memory allocated on heap, memory must be freed before objects goes away.
- Constructors can be written also as outline functions.
- If a class contains a data member that is an object of another class, the constructor for that class is called automatically as well.
- Each object within a class must construct itself efore the class constructor can be invoked.
- The destructor member has the same name as the class, but with a tilde(~) added at the front.

## Chapter 17 -> Making Constructive Arguments
- Sometimes we need to arguments to constructors.
- Constructors can be overloaded. C++ chooses the proper constructor based on the arguments in the declarations of object.
- C++ allows you specify default value for function argument in declaration to be used when argument is not present
- Every class must have a constructor, otherwise you cant create objects of that class. But C++ to provide compatability with C, C++ provides default constructors.
- When initializing const values via constructor, : -> colon syntax is used. 
- static objects are constructed only once.
- We can construct object with static, which means it will be constructed only once.
