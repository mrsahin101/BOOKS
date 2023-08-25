#include <stdio.h>

/* strlen : return length of string s*/
int mystrlen(char *s)
{
    int n;

    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}
int main()
{
    char message[30] = "Embedded Systems";

    printf("Length : %d", mystrlen(message));
}