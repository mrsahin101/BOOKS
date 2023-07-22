#include <stdio.h>
#include <string.h>

int my_strpbrk(char s1[], char s2[])
{
    for(int i = 0; i < strlen(s1); i++)
    {
        for(int j = 0; j < strlen(s2); j++)
        {
            if(s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}

int main()
{
    printf("%d", my_strpbrk("test", "asa"));
}