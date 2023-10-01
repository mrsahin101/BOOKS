#include <stdio.h>
#include <string.h>

int main()
{
    char *message = "Hello World\n";
    for(int i = 0; i < strlen(message); i++)
        putc((message[i]), stdout);
}