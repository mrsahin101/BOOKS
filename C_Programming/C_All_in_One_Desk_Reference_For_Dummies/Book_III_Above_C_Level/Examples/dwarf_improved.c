#include <stdio.h>
#include <string.h>

int main()
{
    char dwarf[7][2][8] = 
    {
        "bashful",  "?",
        "doc",      "?",
        "dopey",    "?",
        "grumpy",   "?",
        "happy",    "?",
        "sneezy",   "?",
        "sleepy",   "?"
    };
    char input[64];
    int named = 0;
    int x;
    
    puts("See if you can name all seven dwarfs:");
    while(named < 7)
    {
        if(named == 1)
            printf("\nSo far you've named %i dwarf.\n", named);
        else
            printf("\nSo far you've named %i dwarfs.\n", named);
        printf("Enter a name:");
        gets(input);
        /* check for no input */
        if(strcmp(input, "") == 0) // no input end
            break;
        for(x = 0; x < 7; x++)
        {
            if(strcmpi(input, dwarf[x][0]) == 0)
            {
                if(dwarf[x][1][0] == '!')
                    printf("You already named that dwarf!\n");
                else
                {
                    printf("Yes! %s is right.\n", input);
                    named++;
                    dwarf[x][1][0] = '!';
                }
            }
        }
        if(named == 7)
            puts("You got 'em all! Snow would be proud!");
        else
            puts("Try again:");
    }
    return(0);
}