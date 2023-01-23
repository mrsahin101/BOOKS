#include <stdio.h>

int main()
{
    char a, b, c, d, e;
    
    for(a = 'A'; a <= 'Z'; a = a + 1)
        for(b = 'A'; b <= 'Z'; b = b + 1)
            for(c = 'A'; c <= 'Z'; c = c + 1)
                for (d = 'A'; d <= 'Z'; d = d + 1)
                    for(e = 'A'; e <= 'Z'; e = e + 1)
                        printf("%c%c%c%c%c\t", a, b, c, d, e);
    return(0);
}