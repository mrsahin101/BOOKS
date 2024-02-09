// PrintArgs - write the arguments to the program to the standart output
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // print a warning banner
    cout << "The arguments to " << pszArgs[0] << "are : \n";

    // now write out the remaining arguments
    for(int i = 1; i < nNumberofArgs; i++)
    {
        cout << i << ":" << pszArgs[i] << "\n";
    }
    // that's it 
    cout << "That's it\n";

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
