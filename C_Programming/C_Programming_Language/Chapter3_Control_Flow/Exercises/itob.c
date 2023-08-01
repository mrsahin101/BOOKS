#include <stdio.h>

void itob(int n, char s[], int base)
{
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    s[0] = '0';
    s[1] = 'x';
    int i = 2, index = 0;
    

    while(n > 0)
    {
        for(int j = 2; j <= i; j++)
        {
            s[j + 1] = s[j];
        }
        s[2] = hexDigits[n % 16];
        n = (n - (n % 16)) / 16;
        i++;
    }
    s[i] = '\0';

}

int main()
{
    int n = 7;
    char string[20];

    itob(n, string, 16);

    printf("%s", string);
}