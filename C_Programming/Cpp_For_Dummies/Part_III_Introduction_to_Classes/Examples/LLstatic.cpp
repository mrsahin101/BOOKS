#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    public:
        Student(char* name)
        {
            // ... construct the object and add it to a list of Student objects
            indexOfStudent = ++numberOfStudents;
            pName = new char[strlen(name) + 1];
            strcpy(pName, name);
            if(pHead == NULL)
            {
                pHead = this;
                pTail = this;
            }
            else
            {
                pTail->pNext = this;
                pTail = this;
            }
        }
        ~Student()
        {
            cout << "Destructing";
        }
        static Student *findName(char* pName)
        {
            Student* iterator = pHead;
            while(iterator != NULL)
            {
                if(strcmp(pName, iterator->pName) == 0)
                {
                    cout << "Found " << pName << " and its Index : " << iterator->indexOfStudent << endl; 
                }
                iterator = iterator->pNext;
            }
        }
    protected:
        static Student *pHead;
        static Student* pTail;
        Student* pNext;
        char* pName;
        int indexOfStudent;
        static int numberOfStudents;
};

Student* Student::pHead = NULL;
Student* Student::pTail = NULL;
int Student::numberOfStudents = 0;
int main(int argcs, char* pArgs[])
{
    Student s1("Randy");
    Student s2("Jenny");
    Student s3("Kinsey");
    Student* pS = Student::findName("Jenny");
    cout << "Hello World\n";
    return 0;
}