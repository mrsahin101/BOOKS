// InheritanceExample - demonstrate an inheritance relationship in which the subclass constructor passes argument 
// information to the constructor in the base class
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

// Advisor - empty Class
class Advisor
{

};

const int MAXNAMESIZE = 40;

class Student
{
    public:
        Student(char* pName = "no name") : average(0.0), semesterHours(0)
        {
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE - 1] = '\0';
            cout << "constructing student " << name << endl;
        }
        void addCourse(int hours, float grade)
        {
            cout << "adding grade to " << name << endl;
            average = (semesterHours * average + grade);
            semesterHours += hours;
            average = average / semesterHours;
        }
        int hours()
        {
            return semesterHours;
        }
        float gpa()
        {
            return average;
        }
    protected:
        char name[MAXNAMESIZE];
        int semesterHours;
        float average;
};
class GraduateStudent : public Student
{
    public:
        GraduateStudent(char* pName, Advisor& adv, float qG = 0.0): Student(pName), advisor(adv), qualifierGrade(qG)
        {
            cout << "constructing graduate student " << pName << endl;
        }
        float qualifier()
        {
            return qualifierGrade;
        }
    protected:
        Advisor advisor;
        float qualifierGrade;
};

int main(int nNumberofArgs, char* pszArgs[])
{
    Advisor advisor;

    // Create two Student types
    Student llu("Cy N Sense");
    GraduateStudent gs("Matt Madox", advisor, 1.5);

    // now add a grade to their grade point average
    llu.addCourse(3, 2.5);
    gs.addCourse(3, 3.0);
    
    // Display the graduate student's qualifier grade
    cout << "Matt's qualifier grade = " << gs.qualifier() << endl;

    // wait until user is ready before termimnating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
