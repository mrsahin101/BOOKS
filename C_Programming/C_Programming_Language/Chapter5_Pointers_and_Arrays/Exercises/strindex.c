#include <stdio.h>
#include <string.h>

int strindex(const char *string, char c)
{
    for(int i = 0; i < strlen(string); i++)
    {
        if(*(string + i) == c)
            return i;
    }
    return EOF;
}
int main()
{
    const char *string = "Hello World\n";
    char ch = 'z';

    if(strindex(string, ch) >= 0)
        printf("%c occured at %d digit index.\n", ch, strindex(string, ch));
    else
        printf("Couldn't find %c characters\n", ch);

    return 0;
}