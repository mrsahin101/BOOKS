#include <stdio.h>

void my_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;

    while(s[i] != '\0')     /* find end of s */
        i++;
    
    while((s[i++] = t[j++]) != '\0' );     /* copy t*/
}

int main()
{
    char name[10] = "MR.";
    char surname[10] = "Sahin";

    my_strcat(name, surname);

    printf("%s", name);
}