#include <stdio.h>

/* strlen : return length of string s */
int mystrlen(char *s)
{
    char *p = s;
    
    while(*p != '\0')
        p++;
    return p - s;
}
int main()
{
    char *message = "Hello World\n";
    printf("Length of string is :%d", mystrlen(message));
    return 0;
}