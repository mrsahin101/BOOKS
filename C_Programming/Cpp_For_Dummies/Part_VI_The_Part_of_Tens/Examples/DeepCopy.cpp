// DeepCopy - provide a program to profile
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <profile.h>

using namespace std;

class Person
{
    public:
        Person(char* pN)
        {
            pName = new char[strlen(pN) + 1];
            if(pName != 0)
            {
                strcpy(pName, pN);
            }
        }
        Person(Person& p)
        {
            pName = new char[strlen(p.pName) + 1];
            if(pName != 0)
            {
                strcpy(pName, p.pName);
            }
        }
        ~Person()
        {
            if(pName != 0)
            {
                delete pName;
                pName = 0;
            }
        }
        char *pName;
};

void fn1(Person& p)
{
    // create a new object
    // Person* p1 = new Person(p.pName);
    Person p1(p);
}
void fn2(Person p)
{
    // create a new object
    Person* p1 = new Person(p);
    delete p1;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    Person p("This_is_a_very_long_name");
    for(int i = 0; i < 1000000; i++)
    {
        fn1(p);
        fn2(p);
    }
    return 0;
}