// ConstructArray - example that invokes a constructor on an array of objects
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student
{
    public:
        Student()
        {
            cout << "constructing student" << endl;
            semesterHours = 0;
            gpa = 0.0;
        }
    protected:
        int semesterHours;
        float gpa;
};

int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "Creating an array of 5 Student objects" << endl;
    Student s[5];

    // wait until user is ready before terminating programt o allow the user to see the program results
    system("PAUSE");
    return 0;
}