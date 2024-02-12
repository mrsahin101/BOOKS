// CopyConstructor - demonstrate an example copy constructor
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
        // Copy constructor
        Student(Student& s)
        {
            strcpy(name, "Copy of ");
            strcat(name, s.name);
            id = s.id;
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
// fn - receives its argument by value
void fn(Student copy)
{
    cout << "In function fn()" << endl;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    Student chester("Chester", 1234);
    cout << "Calling fn()" << endl;
    fn(chester);
    cout << "Returned from fn()" << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}