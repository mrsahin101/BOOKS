#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

class Student
{
    public:
        // grade - return the current grade point average
        float grade()
        {
            return gpa;
        }
        // hours - return the number of semester hours
        int hours()
        {
            return semesterHours;
        }
        // addCourse - add another course to the student's record
        float addCourse(int hours, float grade);

        // The following members are off-limits to others
    protected:
        int semesterHours;      // hours earned toward graduation
        float gpa;              // grade point average
};
Student s;
int main(int argcs, char* pArgs[])
{
    // raise my grade(don't make it too high; otherwise no one would believe it)
    s.gpa = 3.5;            // <- generates compiler error
    float gpa = s.grade();  // <- this public function reads a copy of the value, but you can't change it from here
    return 0;
}