#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[])
{
    for(int i = 0, j = 0; i < strlen(s1); i++)
    {
        if(s1[i] == '-')
        {
            for(char c = s1[i - 1]; c <= s1[i + 1]; j++, c++)
            {
                if(s2[j - 1] != c )
                    s2[j] = c;
                else 
                    j--;    
            }
        }
    }
}

int main()
{
    char string[10] = "a-b-z";
    char string2[100] = "";
    expand(string, string2);

    printf("%s", string2);
}