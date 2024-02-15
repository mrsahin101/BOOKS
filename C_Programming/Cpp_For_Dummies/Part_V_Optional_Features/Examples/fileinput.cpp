// FileInput - read blocks of data from a file
#include <fstream>
#include <iostream>

using namespace std;

ifstream* openFile(istream& input)
{
    for(;;)
    {
        // open the file specified by the user
        char fileName[80];
        cout << "Enter the name of a file" << endl;

        // read input from the user in such a way that the input can't overflow the buffer
        input.getline(fileName, 80);

        // open file for reading, don't create the file if it isn't there
        ifstream* pFileStream = new ifstream(fileName);
        if(pFileStream->good())
        {
            return pFileStream;
        }
        cerr << "Couldn't find " << fileName << endl;
    }
    return 0;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    // get a file stream
    ifstream* pFileStream = openFile(cin);

    // read blocks of data 80 bytes at a time
    char buffer[80];
    while(!pFileStream->eof() && pFileStream->good())
    {
        // read a block - 80 is the max but gcount() return the actual number of bytes read
        pFileStream->read(buffer, 80);
        int noBytes = pFileStream->gcount();

        // do something with the block
        for(int i = 0; i < noBytes; i++)
        {
            cout << buffer[i];
        }
    }
    system("PAUSE");
    return 0;
}