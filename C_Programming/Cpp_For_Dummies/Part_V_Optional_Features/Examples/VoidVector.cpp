// VoidVector - implement a vector that relies on void* as the storage element
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

typedef void* VoidPtr;

class VoidVector
{
    public:
        VoidVector(int nArraySize)
        {
            // store off the number of elements
            nSize = nArraySize;
            ptr = new VoidPtr[nArraySize];
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
        void add(void* pValue)
        {
            if(nWriteIndex < nSize)
            {
                ptr[nWriteIndex++] = pValue;
            }
        }
        VoidPtr get()
        {
            return ptr[nReadIndex++];
        }
    protected: 
        int nSize;
        int nWriteIndex;
        int nReadIndex;
        VoidPtr* ptr;
};

int main(int argc, char* pArgs[])
{
    // create a vector
    VoidVector vv(10);

    // add values to the vector
    cout << "Give me a series integer values to add a vector\n" << "(Enter a negative number to terminate):" << endl;
    for(;;)
    {
        int* p = new int;
        cin >> *p;
        
        if(*p < 0)
        {
            delete p;
            break;
        }
        vv.add((void *)p);
    }
    cout << "\nHere are the numbers you entered" << endl;
    for(int i = 0; i < vv.size(); i++)
    {
        int* p = (int*)vv.get();
        cout << i << ":" << *p << endl;
    }
    system("PAUSE");
    return 0;
}