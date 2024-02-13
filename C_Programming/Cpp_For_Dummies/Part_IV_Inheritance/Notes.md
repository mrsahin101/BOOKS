# INHERITANCE
- In real world, Object Oriented philosophy provides interface for control. User don't care about implementatation details.
## Chapter 20 -> Inheriting a Class
- Inheritance : The ability of one class to inherit capabilites or properties from another class.
- Object-oriented languages express this inheritance relationship by allowing one class to inherit from another.
``` cpp
class GraduateStudent : public Student
{
    // GraduateStudent inherits all the members of Student. Thus GraduateStudent is Student.
    // Student is baseclass, GraduateStudent is sub-class
    // Or Student is parent class, GraduateStudent is child class
    // Or Graduate Student extends Student class. This all 3 are same thing with different phrasing.
};
```
- Each subclass is responsible for initializing itself.
- There are two types of inheritance. IS_A and HAS_A.

## Chapter 21 -> Examining Virtual Member Functions : Are They for Real?
- The number and type of function arguments are included in its full or extended name. This allows you to give two functions same name.
``` cpp
void someFn(int);
void someFn(char*);
void someFn(char*, double);
```
- C++(compiler) left to figure out which function is meant by the arguments during the call. The return type is not part of the extended name.
- The capability of deciding at runtime which of several overloaded member function to call based on runtime type is called **polymorphism** or **late binding**. Deciding which overloaded to call at compile time is called **early binding** because that sounds like the opposite of late binding.
- Overloading base class function polymorphically is called **overriding the base class function**.
- C++ is supporting early binding by default.
- To make a member function **polymorphic**, the programmer must flag the function with C++ keyword **virtual**.
- If member function with same arguments doesnt declared with same arguments in sub classes, member functions are not overriden **polymorphically**, wheter or not they are declared virtual.
- Static member functions cannot be declared  **virtual**. 
- Specifying the class name in the call forces a call to bind early, whether or not the function is virtual.
- Constructors cannot be virtual because there is no object to use to determine the type.
- The destructor should almost alwas be declared virtual.