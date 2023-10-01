#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void getfileName(char *argv, char *output)
{
    int startIndex = 0;
    for(int i = strlen(argv); i >= 0; i--)
    {
        if(argv[i] == '\\')
        {
            startIndex = i + 1;
            break;
        }
    }

    for(int i = startIndex, j = 0; i < strlen(argv) + 1; i++, j++)
    {
        output[j] = argv[i];
        if(i == strlen(argv))
            output[j + 1] = '\0';
    }
}
enum _status
{
    LOWER = 0,
    UPPER = 1,
};
int main(int argc, char *argv[])
{
    char *filename = (char *)malloc(sizeof(char));
    getfileName(argv[0], filename);
    
    enum _status status;
    if(strcmp(filename, "upper.exe") == 0)
    {
        status = UPPER;
        printf("is Upper\n");
    }
    else if(strcmp(filename, "lower.exe") == 0)
    {
        printf("is Lower\n");
        status = LOWER;
    }
    char c;
    while((c = getchar()) != EOF)
    {
        if(status == 1)     // upper
            printf("%c", toupper(c));
        else if(status == 0)        // lower
            printf("%c", tolower(c));
    }

}