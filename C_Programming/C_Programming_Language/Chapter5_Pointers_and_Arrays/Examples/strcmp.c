#include <stdio.h>

/* strcmp : return < 0 if s < t, 0 if s == t, > 0 if s > t*/
int mystrcmp(char *stringOne, char *stringTwo)
{
    int i;

    for(i = 0; stringOne[i] == stringTwo[i]; i++)
        if(stringOne[i] == '\0')
            return 0;;
    return stringOne[i] - stringTwo[i];
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