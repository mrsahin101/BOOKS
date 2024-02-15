#include <iostream>
using namespace std;

void fn(ostream& out)
{
    out << "My name is Stephen\n";
}
int main(int nNumberofArgs, char* pszArgs[])
{
    fn(cout);
    system("PAUSE");
    return 0;
}