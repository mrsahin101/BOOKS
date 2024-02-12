// DefaultCopyConstructor -> demonstrate that the default copy constructor invokes the copy constructor for any member
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE = 40;

class Student
{
    public:
        // Conventional constructor
        Student(char* pName = "no name", int ssId = 0)
        {
            strcpy(name, pName);
            id = ssId;
            cout << "constructed " << name << endl;
        }
        ~Student()
        {
            cout << "destructing " << name << endl;
        }
    protected:
        char name[MAXNAMESIZE];
        int id;
};

class Tutor
{
    public:
        Tutor(Student& s) : student(s) //invoke copy
        {
            cout << "Constructing Tutor object" << endl;
            id = 0;
        }
    protected:
        Student student;
        int id;
};

void fn(Tutor tutor)
{
    cout << "In function fn()" << endl;
}

int main(int argcs, char* pArgs[])
{
    Student chester("Chester");
    
    Tutor tutor(chester);
    cout << "Calling fn()" << endl;
    fn(tutor);
    cout << "Returned from fn()" << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0; 
}