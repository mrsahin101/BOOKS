// OverloadConstructor - provide the class multiple ways to create objects by overloading the constructor
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE = 40;

class Student
{
    public:
        Student()
        {
            cout << "Constructing student no name" << endl;
            semesterHours = 0;
            gpa = 0.0;
            name[0] = '\0';
        }
        Student(char* pName)
        {
            cout << "Constructing student " << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
            semesterHours = 0;
            gpa = 0;
        }
        Student(char* pName, int xfrHours, float xfrGPA)
        {
            cout << "Constructing student " << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
            semesterHours = xfrHours;
            gpa = xfrGPA; 
        }
        ~Student()
        {
            cout << "Destructing student" << endl;
        }
    protected:
        char name[40];
        int semesterHours;
        float gpa;
};
int main(int argcs, char* pszArgs[])
{
    // The following invokes three different constructors
    Student noName;
    Student freshman("Marian Haste");
    Student xferStudent("Pikumup Andropov", 80, 2.5);

    //wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}