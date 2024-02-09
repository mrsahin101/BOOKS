// Concatenate - concatenate two strings with a " - " in the middle (This version crashes)
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <strings.h>

using namespace std;

void stringEmUp(char* szTarget, char* szSource1, char* szSource2);

int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "This program concatenates two strings\n"
         << "(This version shouldn't crash.)" << endl;
    
    char szStrBuffer[256];

    // define two strings...
    char szString1[] = "This is a string";
    char szString2[] = "THIS IS A STRING";

    // ...now string them together
    stringEmUp(szStrBuffer, szString1, szString2);

    // output the result
    cout << "<" << szStrBuffer << ">" << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}
void stringEmUp(char* szTarget, char* szSource1, char* szSource2)
{
    strcpy(szTarget, szSource1);
    strcat(szTarget, " - ");
    strcat(szTarget, szSource2);
}