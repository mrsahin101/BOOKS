// BranchDemo - input two numbers. Go down one path of the program
// if the first argument is greater than the first or the other path if not

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // input the first argument...
    int arg1;
    cout << "Enter arg1: ";
    cin >> arg1;

    // ... and the second
    int arg2;
    cout << "Enter arg2: ";
    cin >> arg2;
    
    // now decide what to do
    if(arg1 > arg2)
    {
        cout << "Argument 1 is greater than argument 2" << endl;
    }
    else
    {
        cout << "Argument 1 is not greater than argument 2" << endl;
    }

    // Wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}