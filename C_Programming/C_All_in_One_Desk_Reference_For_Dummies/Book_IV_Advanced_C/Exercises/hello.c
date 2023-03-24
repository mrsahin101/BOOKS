#include <stdio.h>
#include <string.h>

int main()
{
    char array[] = "Hello!\n";
    char *a, *e;

    printf("%s", array);
    a = array;
    e = &array[1];
    
    printf("Array 'array' is %d bytes long and lives at %p address.\n", sizeof(array), a);

    puts("Array Elements!");
    for(int i = 0; i < strlen(array); i++)
    {
        printf("%d element of array is : %c and it's %d bytes long and it lives at address : %p\n", i + 1, array[i], sizeof(array[i]), &array[i]);
    }
    return(0);
}