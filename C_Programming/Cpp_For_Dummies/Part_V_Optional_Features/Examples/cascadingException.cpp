// CascadingException - note that the following program may generate warnings because the variables f, i and pMsg are not used for anything
// The compiler is trying to give you a hint that maybe you don't need the arguments at all
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Obj
{
    public:
        Obj(char c)
        {
            label = c;
            cout << "Constructing object " << label << endl;
        }
        ~Obj()
        {
            cout << "Destructing object " << label << endl;
        }
    protected:
        char label;
};

void f1();
void f2();
int f3()
{
    Obj a('a');
    try
    {
        Obj b('b');
        f1();
    }
    catch(float f)
    {
        cout << "Float catch " << endl;
    }
    catch(int i)
    {
        cout << "Int catch " << endl;
    }
    catch(...)
    {
        cout << string("Generic catch") << endl;
    }
}
int main(int nNumberofArgs, char* pszArgs[])
{
    f3();

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
void f1()
{
    try
    {
        Obj c('c');
        f2();
    }
    catch(string msg)
    {
        cout << "String catch" << endl;
    }
}
void f2()
{
    Obj d('d');
    throw 10;
}