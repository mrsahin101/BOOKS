#include <stdio.h>

int main()
{
    char key;

    puts("Type your favorite keyboard character : ");
    key = getchar();
    printf("Your favorite character is %c!\n",key);
    return(0);
}