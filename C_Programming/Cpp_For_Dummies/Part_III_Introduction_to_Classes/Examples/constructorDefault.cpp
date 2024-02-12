// ConstructorWDefaults - multiple constructors can often be combined with the definition of default arguments
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE = 40;

class Student
{
    public:
        Student(char* pName = "no name", int xfrHours = 0, float xfrGPA = 0.0)
        {
            cout << "constructing student " << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
            semesterHours = xfrHours;
            gpa = xfrGPA;
        }
        ~Student()
        {
            cout << "destructing student" << endl;
        }
    protected:
        char name[MAXNAMESIZE];
        int semesterHours;
        float gpa;
};

int main(int argcs, char* pArgs[])
{
    // the following invokes three different constructors
    Student noName;
    Student freshman("Marian Haste");
    Student xferStudent("Pikumup Andropov", 80, 2.5);

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}