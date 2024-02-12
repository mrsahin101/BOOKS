// ConstructDataMember - construct a data member to a value other than the default
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE = 40;

class StudentId
{
    public:
        StudentId(int id = 0)
        {
            value = id;
            cout << "assigning student id " << value << endl;
        }
    protected:
        int value;
};

class Student
{
    public:
        Student(char* pName = "no name", int ssId = 0) : id(ssId)
        {
            cout << "constructing student " << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
        }
    protected:
        char name[40];
        StudentId id;
};

int main(int argcs, char* pArgs[])
{
    Student s("Chester", 1234);
    cout << "This message from main" << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
