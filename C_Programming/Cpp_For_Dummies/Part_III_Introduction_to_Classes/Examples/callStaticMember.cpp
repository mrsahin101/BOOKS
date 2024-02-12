// CallStaticMember - demonstrate two ways to call a static member function
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    public:
        Student(char* pN = "no name")
        {
            pName = new char[strlen(pN) + 1];
            if(pName)
            {
                strcpy(pName, pN);
            }
            noOfStudents++;
        }
        ~Student()
        {
            noOfStudents--;
        }
        static int number()
        {
            return noOfStudents;
        }
    protected:
        char* pName;
        static int noOfStudents;
};

int Student::noOfStudents = 0;

int main(int argcs, char* pArgs[])
{
    Student s1("Chester");
    Student s2("Scooter");

    cout << "Number of student is " << s1.number() << endl;
    cout << "Number of students is " << Student::number() << endl;

    // Wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}