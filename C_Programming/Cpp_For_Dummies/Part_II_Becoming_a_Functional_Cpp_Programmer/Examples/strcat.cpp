// Concatenate - concatenate two strings with a " - " in the middle(this version crashes)
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <strings.h>

using namespace std;

void stringEmUp(char* szTarget, char* szSource1, char* szSource2, int nLength);

int main(int nNumberofArgs, char* pszArgs[])
{
	cout << "This program concatenates two strings\n" 
		 << "(This version may crash.)" << endl;
		 
	char szStrBuffer[256];
	// Create two strings of equal length...
	char szString1[16];
	strncpy(szString1, "This is a string", 16);
	char szString2[16];
	strncpy(szString2, "THIS IS A STRING", 16);
	
	// ... now string them together
	stringEmUp(szStrBuffer, szString1, szString2, 16);
	
	// output the result
	cout << "<" << szStrBuffer << ">" << endl;
	
	// wait until user is ready before terminating program to allow the user to see
	// the program results
	system("PAUSE");
	return 0;
}

void stringEmUp(char* szTarget, char* szSource1, char* szSource2, int nLength)
{
	strncpy(szTarget, szSource1, nLength);
	strcat(szTarget, " - ");
	strcat(szTarget, szSource2);
}
