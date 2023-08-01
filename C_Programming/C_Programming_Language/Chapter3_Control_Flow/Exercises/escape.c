#include <stdio.h>
#include <string.h>

void escape(char s[], char t[])
{
    int i, j;
    for(i = 0, j = 0; i < strlen(t); i++, j++)
    {
        switch(t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
            default:
                s[j] = t[i];
        }
    }
    s[j] = '\0';
}

int main()
{
    char s[100];
    char t[15] = "test\n\n";

    escape(s,t);
    printf("%s", s);
}