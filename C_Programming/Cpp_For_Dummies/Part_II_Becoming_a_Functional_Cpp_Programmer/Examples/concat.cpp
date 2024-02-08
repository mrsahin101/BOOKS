// Concatenate - concatenate two strings with a " - " in the middle
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// The following include file is deprecated; however it is required for the str functions
#include <strings.h>

int main(int nNumberofArgs, char* pszArgs[])
{
    // read first string ...
    char szString1[256];
    cout << "Enter string #1: ";
    cin >> szString1;
    // safer alternative
    // cin.getline(szString1, 128);

    // ... now the second string...
    char szString2[128];
    cout << "Enter string #2: ";
    cin >> szString2;
    
    // accumulate both strings into a single buffer
    char szString[260];

    // copy the first string into the buffer...
    strncpy(szString, szString1, 128);

    // ...concatenate a " - " on the first...
    strncat(szString, " - ", 4);

    // ... now add the second string...
    strncat(szString, szString2, 128);

    // ...and display the result
    cout << "\n" << szString << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;


}