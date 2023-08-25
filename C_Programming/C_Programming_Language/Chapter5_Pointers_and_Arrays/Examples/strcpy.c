#include <stdio.h>

/* strcpy : copy t to s; array subscript version */
void mystrcpy(char *source, char *destination)
{
    int i;

    i = 0;
    while((destination[i] = source[i]) != '\0')
        i++;
    destination[i] = '\0';
}

int main()
{
    char msg[10] = "Hello";
    char echo[10] = "";
    mystrcpy(msg, echo);
    printf("%s", echo);
}   