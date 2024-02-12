#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

class Student
{
    friend void initialize(Student*);
    public:
        // same public members as before
    protected:
        int semesterHours;      // hours earned toward graduation
        float gpa;
};

// the following function is a friend of Student so it can access the protected members
void initialize(Student *pS)
{
    pS->gpa = 0;        // This is now legal
    pS->semesterHours = 0;  // when it wasn't before
}
int main()
{
    return 0;
}