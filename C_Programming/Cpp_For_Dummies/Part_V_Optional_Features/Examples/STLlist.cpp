// STLList - use the list container of the Standart Template Library to input and sort a string of names
#include <list>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

// declare a list of string objects
using namespace std;

list<string> names;

int main(int argc, char* pArgs[])
{
    // input a string of names
    cout << "Input a name (input a null to terminate list)" << endl;
    while(true)
    {
        string name;
        cin >> name;
        if((name.compare("x") == 0) || (name.compare("X") == 0))
        {
            break;
        }
        names.push_back(name);
    }
    // sort the list
    // (this works since String implements a comparison operator)
    names.sort();

    // display the sorted list keep displaying names until the collection is empty
    cout << "\nSorted output:" << endl;
    while(!names.empty())
    {
        // get the first name in the list
        string name = names.front();
        cout << name << endl;

        // remove that name from the list
        names.pop_front();
    }
    system("PAUSE");
    return 0;
}