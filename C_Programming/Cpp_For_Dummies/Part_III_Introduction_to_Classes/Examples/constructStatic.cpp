// ConstructStatic - demonstrate that statics are only constructed once
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class DoNothing
{
    public:
        DoNothing(int initial)
        {
            cout << "DoNothing constructed with a value of " << initial << endl;
        }
};

void fn(int i)
{
    cout << "Function fn passed a value of " << i << endl;
    static DoNothing dn(i);
}
int main(int argcs, char* pszArgs[])
{
    fn(10);
    fn(20);
    system("PAUSE");
    return 0;
}