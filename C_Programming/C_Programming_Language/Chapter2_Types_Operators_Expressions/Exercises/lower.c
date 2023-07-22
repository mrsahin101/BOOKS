#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define ASCII_a         0x61
#define ASCII_z         0x7A

void my_lower(char string[])
{
    int i = 0;

    while(string[i] != '\0')
    {
        //string[i] = tolower(string[i]);
        if(string[i] >= ASCII_a && string[i] <= ASCII_z)
        {
            string[i] -= 32;   
        }
        i++;
    }
}
int main()
{
    char name[10] = "TESTaaa";
    my_lower(name);
    printf("%s", name);
}