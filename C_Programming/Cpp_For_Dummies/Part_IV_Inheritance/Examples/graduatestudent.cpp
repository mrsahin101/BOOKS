// GraduateStudent - a special type of Student
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "graduatestudent.h"

namespace Schools
{
    char* GraduateStudent::display()
    {
        // get description of basic student
        char* pFirst = Student::display();

        // we'll add this text
        char* pSecond = "-G";

        // get a new string and tack second onto first
        char* pName = new char[strlen(pFirst) + strlen(pSecond) + 1];

        strcpy(pName, pFirst);
        strcat(pName, pSecond);

        // don't forget to return the string returned by Student::display() to the heap before passing our new string to the caller
        delete pFirst;
        return pName;
    }
}