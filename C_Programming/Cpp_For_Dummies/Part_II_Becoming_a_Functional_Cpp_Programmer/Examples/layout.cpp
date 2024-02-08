// Layout - this program tries to give the reader an idea of the layout of local memory in her compiler
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    int end;
    int n;
    long l;
    float f;
    double d;

    // set output to hex mode
    cout.setf(ios::hex);
    cout.unsetf(ios::dec);

    // output the address of each variable in order to get an idea of how variables are laid out in memory
    cout << "&end = " << &end << "\n";
    cout << "&n = " << &n << "\n";
    cout << "&l = " << &l << "\n";
    cout << "&f = " << &f << "\n";
    cout << "&d = " << &d << "\n";

    // wait until user is ready before terminating program to allow the user to see the program resutls
    system("PAUSE");
    return 0; 
}