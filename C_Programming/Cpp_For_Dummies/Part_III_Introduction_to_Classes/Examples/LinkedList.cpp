// LinkedListData - store data in a linked list of objects
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

// NameDataSet - stores a person's name (these objects could easily store any other information desired)
class NameDataSet
{
    public:
        char szName[128];
        // the link to the next entry in the list
        NameDataSet *pNext;
};
// the pointer to the first entry in the list
NameDataSet* pHead = 0;

// add - add a new member to the linked list
void add(NameDataSet* pNDS)
{
    // point the current entry to the beginning of the list
    pNDS->pNext = pHead;
    // point the head pointer to the current entry
    pHead = pNDS;
}
// getData - read a name and social security number; return null if no more to read 
NameDataSet* getData()
{
    // read the first name
    char nameBuffer[128];
    cout << "\nEnter name:";
    cin >> nameBuffer;

    // if the name entered is 'exit'...
    if((stricmp(nameBuffer, "exit") == 0))
    {
        // ...return a null to terminate input
        return 0;
    }
    // get a new entry to fill
    NameDataSet* pNDS = new NameDataSet;

    // fill in the name and zero the link pointer
    strncpy(pNDS->szName, nameBuffer, 128);
    pNDS->szName[127] = '\0';   // ensure string is terminated
    pNDS->pNext = 0;
    
    // return the address of the object created
    return pNDS;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "Read names of people\n"
         << "Enter 'exit' for first name to exit\n";

    // create (another) NameDataSet object
    NameDataSet* pNDS;
    while(pNDS = getData())
    {
        // add it onto the end of the list of NameDataSet object
        add(pNDS);
    }
    // to display the objects, iterate through the list(stop when the next address is NULL)
    cout << "Entries: \n",
    pNDS = pHead;
    while(pNDS)
    {
        // display current entry
        cout << pNDS->szName << "\n";
        // get the next entry
        pNDS = pNDS->pNext;
    }
    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}