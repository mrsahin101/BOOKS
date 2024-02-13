// DemoAssignmentOperator - demonstrate the assignment operator on a user defined class
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

// Name - a generic class used to demonstrate the assignment and copy constructor operators
class Name
{
    public:
        Name(char* pszN = 0)
        {
            copyName(pszN, "");
        }
        Name(Name& s)
        {
            copyName(s.pszName, " (copy) ");
        }
        ~Name()
        {
            deleteName();
        }
        // Assignment operator
        Name& operator = (Name& s)
        {
            // Delete existing stuff
            deleteName();
            // ...before replacing with new stuff
            copyName(s.pszName, " (replaced) ");
            // return reference to existing object
            return *this;
        }
        // very simple acces function
        char* out()
        {
            return pszName;
        }
    protected:
        void copyName(char* pszN, char* pszAdd);
        void deleteName();
        char* pszName;
};
// copyName() - allocate the heap memory to store name
void Name::copyName(char* pszN, char* pszAdd)
{
    pszName = 0;
    if(pszName)
    {
        pszName = new char[strlen(pszN) + strlen(pszAdd) + 1];
        strcpy(pszName, pszN);
        strcat(pszName, pszAdd);
    }
}
// deleteName() - return heap memory
void Name::deleteName()
{
    if(pszName)
    {
        delete pszName;
        pszName = 0;
    }
}
int main(int nNumberofArgs, char* pszArgs[])
{
    // create two objects
    Name n1("Claudette");
    Name n2("Greg");
    cout << n1.out() << " and " << n2.out() << " are newly created objects" << endl;

    // now make a copy of an object
    Name n3(n1);
    cout << n3.out() << " is a copy of " << n1.out() << endl;

    // Create a new object using the " = " format for accesing the copy constructor
    Name n4 = n1;
    cout << n4.out() << " is also a copy of " << n1.out() << endl;

    // overwrite n2 with n1
    n2 = n1;
    cout << n1.out() << " was assigned to " << n2.out() << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}