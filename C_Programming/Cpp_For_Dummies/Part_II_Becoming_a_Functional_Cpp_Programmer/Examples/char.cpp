// CharDisplay - output a character array to standart output, the MS-DOS window
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

// prototype declarations
void displayCharArray(char stringArray[], int sizeOfloatArray);

int main(int nArg, char* pszArgs[])
{
    char charMyName[] = {'S', 't', 'e', 'p', 'h', 'e', 'n'};
    displayCharArray(charMyName, 7);
    cout << "\n";
    return 0;
}
// displayCharArray - display an array of characters by outputing one character at a time
void displayCharArray(char stringArray[], int sizeOfloatArray)
{
    for(int i = 0; i < sizeOfloatArray; i++)
    {
        cout << stringArray[i];
    }
}