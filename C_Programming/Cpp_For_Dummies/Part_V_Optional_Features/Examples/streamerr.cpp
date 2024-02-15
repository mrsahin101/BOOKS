// StreamOutputWithErrorChecking - simple output to a file
#include <fstream>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    const static char fileName[] = "MyName.txt";
    ofstream my(fileName);
    if(my.bad())   //if the open didn't work
    {
        cerr << "Error opening file" << fileName << endl;
        return 0;       //... output error and quit
    }
    my << "Stephen Davis is suave and handsome\n" << "and definietly not balding prematurely" << endl;
    if(my.bad())
    {
        cerr << "Error writing to file " << fileName << endl;
    }
    system("PAUSE");
    return 0;
}