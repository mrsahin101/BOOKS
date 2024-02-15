// StreamInput - simple input from a file using fstream
#include <fstream>
#include <iostream>

using namespace std;

ifstream* openfile()
{
    ifstream* pFileStream = 0;
    for(;;)
    {
        // open the file specified by the user
        char fileName[80];
        cout << "Enter the name of a file with integers" << endl;
        cin >> fileName;

        // open file for reading; don't create the file, if it isn't there
        pFileStream = new ifstream(fileName);
        if(pFileStream->good())
        {
            break;
        }
        cerr << "Couldn't open " << fileName << endl;
        delete pFileStream;
    }
    return pFileStream;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    // get a file stream
    ifstream* pFileStream = openfile();

    // stop when no more data in file
    while(!pFileStream->eof())
    {
        // read a value
        int nValue = 0;
        (*pFileStream) >> nValue;
        // stop if the file read failed(probably because we ran upon something that's not an int or because we found a new
        // line with nothing after it)
        if(pFileStream->fail())
        {
            break;
        }
        // output the value just read
        cout << nValue << endl;
    }
    system("PAUSE");
    return 0;
}