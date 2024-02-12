// ConstructingMembers - a class may pass along arguments to the members constructors
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
const int MAXNAMESIZE = 40;

int nextStudentId = 0;

class StudentId
{
    public:
        StudentId()
        {
            value = ++nextStudentId;
            cout << "Assigning student id " << value << endl;
        }
    protected:
        int value;
};

class Student
{
    public:
        Student(char* pName)
        {
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE -1] = '\0';
            semesterHours = 0;
            gpa = 0.0;
        }
    protected:
        char name[MAXNAMESIZE];
        int semesterHours;
        float gpa;
        StudentId id;
};

int main(int argcs, char* pArgs[])
{
    Student s("Chester");

    // wait until  user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}