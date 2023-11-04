#include <stdio.h>
#include <unistd.h>

int getchar(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}
int main()
{
    char ch;
    while((ch = getchar()) > 0)
        printf("%c", ch);
    return 0;
}