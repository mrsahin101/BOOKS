// StringConcatenate - concatenate two string type variables with a " - " in the middle
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // read first string...
    string string1;
    cout << "Enter string #1:";
    cin >> string1;

    // ...now the second string
    string string2;
    cout << "Enter string #2:";
    cin >> string2;

    // accumulate both strings into a single buffer
    string buffer;
    string divider = " - ";

    buffer = string1 + divider + string2;

    // ...and display the result
    cout << "\n" << buffer << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}