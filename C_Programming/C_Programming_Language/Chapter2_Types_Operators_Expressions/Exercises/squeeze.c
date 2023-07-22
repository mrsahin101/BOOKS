#include <stdio.h>


void squeeze(char s[], int c)
{
    int i, j;


    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main()
{
    char name[10] = "Elemek";

    squeeze(name, 'e');
    printf("%s", name);
}