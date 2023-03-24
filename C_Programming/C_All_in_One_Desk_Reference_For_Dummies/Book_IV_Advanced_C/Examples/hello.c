#include <stdio.h>

int main()
{
    char array[] = "Hello!\n";
    char *a;

    printf("%s", array);
    
    a = array;
    printf("Array 'array' is %d bytes long and lives at %p address.\n", sizeof(array), a);
    printf("Content of a : %s",a);
    return(0);
}