// ConstructorWArg - provide a constructor with arguments
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE = 40;

class Student
{
    public:
        Student(char* pName)
        {
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
            semesterHours = 0;
            gpa = 0.0;
        }
    protected:
        char name[MAXNAMESIZE];
        int semesterHours;
        float gpa;
};

int main(int argcs, char* pszArgs[])
{
    Student s("0. Danny Boy");
    Student* pS = new Student("E. Z. Rider");

    // Wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}