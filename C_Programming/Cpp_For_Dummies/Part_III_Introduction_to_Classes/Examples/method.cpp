// CallMemberFunction - define and invoke a function that's a member of the class Student
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student
{
    public: 
        int semeterHours;
        float gpa;
        // add a completed course to the record
        float addCourse(int hours, float grade)
        {
            // calculate the sum of all courses times the average grade
            float weightedGPA;
            weightedGPA = semeterHours * gpa;
            
            // now add in the new course 
            semeterHours += hours;
            weightedGPA += grade * hours;
            gpa = weightedGPA / semeterHours;

            // return the new gpa
            return gpa;
        }
};
int main(int nNumberofArgs, char* pszArgs[])
{
    Student s;
    s.semeterHours = 10;
    s.gpa = 3.0;

    // the valuese before the call
    cout << "Before : s = (" << s.semeterHours
         << ", " << s.gpa << ")" << endl;

    // the following subjects the data members of the s object to the member function addCourse()
    s.addCourse(3, 4.0);        // call the member function
    
    // the values are now changed
    cout << "After : s = (" << s.semeterHours 
         << ", " << s.gpa << ") " << endl;

    // access another object just for the heck of it
    Student t;
    t.semeterHours = 6;
    t.gpa = 1.0;        // not doing so good
    t.addCourse(3, 1.5);    // things aren't getting any better

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}