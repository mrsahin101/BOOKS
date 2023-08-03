#include <stdio.h>
#include <string.h>

int strindex(char s[], char t)
{
    int lastOccuredIndex = -1;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == t)
            lastOccuredIndex = i;
    }
    return lastOccuredIndex;
}
int main()
{
    char mystring[20] = "teletabi";
    char searchedChar = 'e';
    printf("Index of last %c : %d", searchedChar, strindex(mystring, searchedChar));
} 