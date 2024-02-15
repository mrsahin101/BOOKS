// StreamOutput - simple output to a file
#include <fstream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    ofstream my("MyName.txt");
    my << "Stephen Davis is suave and handsome\n" << "and definitely not balding prematurely" << endl;
    system("PAUSE");
    return 0;
}