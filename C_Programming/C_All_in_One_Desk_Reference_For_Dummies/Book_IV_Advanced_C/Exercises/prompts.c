#include <stdio.h>

int main()
{
    char *prompts[] = 
    {
        "Type something",
        "C:\\>",
        "."
    };

    for(int i = 0; i < 3; i++)
        puts(prompts[i]);

    return(0);
}