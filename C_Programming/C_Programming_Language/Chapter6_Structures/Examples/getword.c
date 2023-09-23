#include  <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN      100
char *getword(char *buffer, int len)
{
    char ch;
    char *head = buffer;
    for ( int i = 0; ( i  < len ) && (( ch = getchar()) != EOF) && ( ch !='\n' ); ++i )
    {
        // if(!isspace(ch) && head != buffer)
        //     *buffer++ = ch;
        if(isspace(ch) && head != buffer)
            break;
        *buffer++ = ch;
    }
    *buffer++ = '\0';
    return head;

}
int main(void)
{
    char *name = malloc(sizeof(char) * MAXLEN);
    char *output = getword(name, MAXLEN);

    printf("%s", output);
}