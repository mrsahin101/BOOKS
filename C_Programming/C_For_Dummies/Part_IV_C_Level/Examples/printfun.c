/*
 * printf() escape sequence demonstration program
 */
#include <stdio.h>

int main()
{
    printf("Here is the \\a sequence: \a");
    getchar();
    return(0);
}