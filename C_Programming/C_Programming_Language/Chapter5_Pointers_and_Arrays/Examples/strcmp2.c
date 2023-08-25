#include <stdio.h>

/* strcmp : return < 0 if s < t, 0 if s == t, > 0 if s > t*/
int mystrcmp(char *stringOne, char *stringTwo)
{
    int i;

    for(; *stringOne == *stringTwo; stringOne++, stringTwo++)
        if(*stringOne == '\0')
            return 0;;
    return *stringOne - *stringTwo;
}

int main()
{
    char msg[] = "test";
    char msg2[] = "test";

    if(mystrcmp(msg, msg2) == 0)
        printf("Strings are identical\n");
    else if(mystrcmp(msg, msg2) > 0)
        printf("String one is lexicographically bigger\n");
    else
        printf("String two is lexicographically bigger\n");
    
    return 0;
}