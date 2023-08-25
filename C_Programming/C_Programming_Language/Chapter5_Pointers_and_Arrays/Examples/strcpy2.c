#include <stdio.h>
 
/* strcpy : copy source to destination; pointer version 1*/
void mystrcpy(char* destination, char* source)
{
    char *ptr = destination;

    while((*destination++ = *source++) != '\0');
    destination = ptr;
}
 
// Implement `strcpy()` function in C
int main(void)
{
    char source[] = "Hello World";
    char destination[25];
    
    mystrcpy(destination, source);
    printf("%s", destination);

    return 0;
}