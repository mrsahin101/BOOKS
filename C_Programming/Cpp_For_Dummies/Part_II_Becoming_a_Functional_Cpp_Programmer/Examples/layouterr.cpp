// LayoutError - demonstrate the results of a messing up a pointer usage
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    int upper = 0;
    int n = 0;
    int lower = 0;

    // output the values of the three variables before
    cout << "the initial values are" << endl;
    cout << "upper = " << upper << endl;
    cout << "n = " << n << endl;
    cout << "lower = " << lower << endl;

    // now store a double into the space allocated for an int
    cout << "\nString 13.0 into the location &n" << endl;
    double *pD = (double*)&n;
    *pD = 13.0;

    // display the results
    cout << "\nThe final results are : " << endl;
    cout << "upper = " << upper << endl;
    cout << "n = " << n << endl;
    cout << "lower = " << lower << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}