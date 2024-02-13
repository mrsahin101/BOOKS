// SeparatedMain - demonstrated an application separated into two parts- the main() part
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "graduatestudent.h"
#include "student.h"

using namespace std;
// using namepsace schools
using Schools::GraduateStudent;

int main(int nArgc, char* pszArgs[])
{
    Schools::Student s("Sophie Moore", 1234);
    cout << "Student = " << s.display() << endl;

    GraduateStudent gs("Greg U. Waite", 5678);
    cout << "Student = " << gs.display() << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}