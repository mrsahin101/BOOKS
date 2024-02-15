// StringStream - read and parse the contents of a file
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// parseAccountInfo - read a passed buffer as if it were an actual file - read the following format: name, account balance
// return true if all worked well
bool parseString(char* pString, char* pName, int arraySize, long& accountNum, double& balance)
{
    // associate an istrstream object with the input character string
    istringstream inp(pString);

    // read up to the comma separator
    inp.getline(pName, arraySize, ',');

    // now the account number
    inp >> accountNum;

    // and the balance
    inp >> balance;

    // return the error status
    return !inp.fail();
}
int main(int nNumberofArgs, char* pszArgs[])
{
    // get a file stream
    ifstream* pFileStream = new ifstream("Accounts.txt");
    if(!pFileStream->good())
    {
        cout << "Can't open Accounts.txt" << endl;
        return 0;
    }

    // read a line out of file, parse it and display results
    for(;;)
    {
        // add a divider
        cout << "===========================" << endl;
        // read a buffer
        char buffer[256];
        pFileStream->getline(buffer, 256);
        if(pFileStream->fail())
        {
            break;
        }
        // parse the individual fields
        char name[80];
        long accountNum;
        double balance;
        bool result = parseString(buffer, name, 80, accountNum, balance);

        // output the result
        cout << buffer << "\n";
        if(result == false)
        {
            cout << "Error parsing string\n";
            continue;
        }
        cout << "name = " << name << ", " << "account = " << accountNum << ", " << "balance = " << balance << endl;

        // put the fields back together in a different order(inserting the 'ends' makes sure the buffer is null terminated)
        ostringstream out;
        out << name << ", " << balance << " " << accountNum << ends;

        // output the result - istringstream also works with the string class but I have been staying with character arrays until the
        // discussion of the templates
        string oString = out.str();
        cout << oString << "\n" << endl;
    }
    system("PAUSE");
    return 0;
}