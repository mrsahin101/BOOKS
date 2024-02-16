// MaxTemplate - create a template max() function that returns the greater of tw types
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// simplistic exception class for this example only
template <class T>
T maximum(T t1, T t2)
{
    if(t1 > t2)
    {
        return t1;
    }
    return t2;
};

int main(int argc, char* pszArgs[])
{
    // find the maximum of two int's
    cout << "The maximum of 1 and 2 is " << maximum(1, 2) << endl;

    // repeat for doubles
    cout << "The maximum of 1.5 and 2.5 is " << maximum(1.5, 2.5) << endl;

    system("PAUSE");
    return 0;
}