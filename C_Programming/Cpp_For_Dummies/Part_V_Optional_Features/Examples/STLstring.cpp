// STLString - demonstrates just a few of the features of the string class which is part of the Standart Template Library
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

// concat - return the concatenation of two strings
string concat(string s1, string s2)
{
    return s1 + s2;
}
// removeSpaces - remove any spaces within a string
string removeSpaces(string s)
{
    // find the offset of the first space;
    // keep searching the string until no more spaces found
    size_t offset;
    while((offset = s.find(" ")) != -1)
    {
        // remove the space just discovered
        s.erase(offset, 1);
    }
    return s;
}
// insertPhrase - insert a phrase in the position of <ip> for insertion point
string insertPhrase(string source)
{
    size_t offset = source.find("<ip>");
    if(offset != -1)
    {
        source.erase(offset, 4);
        source.insert(offset, "Randall");
    }
    return source;
}

int main(int argc, char* pArgs[])
{
    // create a string that is the sum of two smaller strings
    cout << "string1 + string2 = " << concat("string1 ", "string2") << endl;

    // create a test string and then remove all spaces from it using simple string methods
    string s2("The phrase");
    cout << "<" << s2 << "> minus spaces = <" << removeSpaces(s2) << ">" << endl;

    // insert a phrase within the middle of an existing sentence (at the location of "<ip>")
    string s3 = "Stephen <ip> Davis";
    cout << s3 + " -> " + insertPhrase(s3) << endl;

    system("PAUSE");
    return 0;
}