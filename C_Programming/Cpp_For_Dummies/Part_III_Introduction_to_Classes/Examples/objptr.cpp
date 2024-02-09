// ObjPtr - define and use a pointer to a Student object
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student
{
    public:
        int semesterHours;
        float gpa;
        float addCourse(int hours, float grade) {return 0.0;};
};
int main(int argc, char* pArgs[])
{
    // create a Student object
    Student s;
    s.gpa = 3.0;

    // Now create a pointer to a Student object
    Student* pS;

    // make the student pointer point to our Student object
    pS = &s;
    cout << "s.gpa = " << s.gpa << "\n" << "pS->gpa = " << pS->gpa << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}