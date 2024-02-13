// Student - implement the methods of the Student class
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "student.h"

namespace Schools
{
    Student::Student(char* pszNameArg, int nIDArg) : nID(nIDArg)
    {
        pszName = new char[strlen(pszNameArg) + 1];
        strcpy(pszName, pszNameArg);
    }
    // display - return a description of student
    char* Student::display()
    {
        // copy the student's name into a block of heap memory that we can return to the caller.
        char* pReturn = new char[strlen(pszName) + 1];
        strcpy(pReturn, pszName);
        return pReturn;
    }
}