// VariableSize - output the size of each type of variable

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    bool b;
    char c;
    int n;
    long l;
    float f;
    double d;

    cout << "sizeof a bool = " << sizeof b << endl;
    cout << "sizeof a char = " << sizeof c << endl;
    cout << "sizeof an int = " << sizeof n << endl;
    cout << "size of a long = " << sizeof l << endl;
    cout << "size of a float = " << sizeof f << endl;
    cout << "size of a double = " << sizeof d << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}