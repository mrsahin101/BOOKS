// Constructor - example that invokes a constructor
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student
{
    public:
        Student();
    protected:  
        int semesterHours;
        float gpa;
};
Student::Student()
{
    cout << "constructing student" << endl;
    semesterHours = 0;
    gpa = 0.0;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "Creating a new Student object" << endl;
    Student s;

    cout << "Creating a new object of the heap" << endl;
    Student* pS = new Student;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}