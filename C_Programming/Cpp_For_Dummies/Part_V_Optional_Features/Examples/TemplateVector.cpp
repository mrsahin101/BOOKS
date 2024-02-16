// TemplateVector - implement a vector that uses a template type
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

// TemplateVector - a simple templatized array
template <class T>

class TemplateVector
{
    public:
        TemplateVector(int nArraySize)
        {
            // store off the number of elements
            nSize = nArraySize;
            array = new T[nArraySize];
            reset();
        }
        int size()
        {
            return nWriteIndex;
        }
        void reset()
        {
            nWriteIndex = 0;
            nReadIndex = 0;
        }
        void add(T object)
        {
            if(nWriteIndex < nSize)
            {
                array[nWriteIndex++] = object;
            }
        }
        T get()
        {
            return array[nReadIndex++];
        }
    protected:
        int nSize;
        int nWriteIndex;
        int nReadIndex;
        T* array;
};

// exercise two vectors, one of integers and another of names
void intFn();
void nameFn();

int main(int argc, char* pszArgs[])
{
    intFn();
    nameFn();

    system("PAUSE");
    return 0;
}

// Integers - manipulate a collection of integers
void intFn()
{
    // create a vector
    TemplateVector<int> integers(10);

    // add values to the vector
    cout << "Give me a series integer values to add to a vector\n" << "(Enter a negative number to terminate):" << endl;

    for(;;)
    {
        int n;
        cin >> n;
        if(n < 0)
        {
            break;
        }
        integers.add(n);
    }
    cout << "\nHere are the numbers you entered" << endl;
    for(int i = 0; i < integers.size(); i++)
    {
        cout << i << ":" << integers.get() << endl;
    }
}
// Names - create and manipulate a vector of names
class Name
{
    public:
        Name(char* n = "") : name(n)
        {

        }
        string display()
        {
            return name;
        }
    protected:
        string name;
};
void nameFn()
{
    // create a vector
    TemplateVector<Name> names(10);

    // add values to the vector
    cout << "Enter names\n" << "(Enter an 'x' to quit):" << endl;
    for(;;)
    {
        char buffer[20];
        do
        {
            cin.getline(buffer, 80);
        } while (strlen(buffer)== 0);
        if(stricmp(buffer, "x") == 0)
        {
            break;
        }
        names.add(Name(buffer));
    }
    cout << "\nHere are the names you entered" << endl;
    for(int i = 0; i < names.size(); i++)
    {
        Name name = names.get();
        cout << i << ":" << name.display() << endl;
    }
}