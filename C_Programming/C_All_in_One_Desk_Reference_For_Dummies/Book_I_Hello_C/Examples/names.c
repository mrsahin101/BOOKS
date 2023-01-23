#include <stdio.h>

int main()
{
    char a, b, c;
    
    for(a = 'A'; a <= 'Z'; a = a + 1)
        for(b = 'A'; b <= 'Z'; b = b + 1)
            for(c = 'A'; c <= 'Z'; c = c + 1)
                printf("%c%c%c\t", a, b, c);
    return(0);
}