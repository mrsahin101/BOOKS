// CustomExceptionClass - demonstrate exceptions using a factorial function
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

// Exception - Generic exception handling class
class Exception
{
    public:
        Exception(char* pMsg, int n, char* pFile, int nLine) : msg(pMsg), errorValue(n), file(pFile), lineNum(nLine)
        {

        }
        virtual string display()
        {
            ostringstream out;
            out << "Error <" << msg << " - value is " << errorValue << ">\n";
            out << " @" << file << "-" << lineNum << endl;
            return out.str();
        }
    protected:
        // Error message
        string msg;;
        int errorValue;
        // filename and line number where error occured
        string file;
        int lineNum;
};
// factorial - compute factorial
int factorial(int n)
{
    // you can't handle negative values of n;
    // better check for that condition first
    if(n < 0)
    {
        throw Exception("Argument for factorial negative ", n, __FILE__, __LINE__);
    }
    // go ahead and calculate factorial 
    int accum = 1;
    while(n > 0)
    {
        accum *= n;
        n--;
    }
    return accum;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    try
    {
        // this will work
        cout << "Factorial of 3 is " << factorial(3) << endl;
        // this will generate an exception
        cout << "Factorial of -1 is " << factorial(-1) << endl;
    }
    // control passes here
    catch(Exception e)
    {
        cout << "Error occured: \n" << e.display() << endl;
    }

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}