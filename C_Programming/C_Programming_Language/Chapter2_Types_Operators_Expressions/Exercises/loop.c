#include <stdio.h>

int main()
{
    int limit = 10;
    char c;
    char s[10];
    int i;
    
    for(i = 0; i < limit - 1; i++)
    {
        c = getchar();
        if(c == '\n')
            break;
        if(c == EOF)
            break;
        s[i] = c;    
    }
    s[i] = '\0';
    printf("%s", s); 
}