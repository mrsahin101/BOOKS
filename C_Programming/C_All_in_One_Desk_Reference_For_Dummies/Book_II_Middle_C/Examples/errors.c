#include <stdio.h>

int main()
{
    int code;

    printf("Enter the error code number\n");
    printf("Range 1 through 5: ");
    scanf("%d", &code);

    if(code == 1)
    {
        puts("San Andreas Fault");
        puts("Solution: Move your house.");
    }
    else if(code == 2)
    {
        puts("Illegal Operation");
        puts("Solution: Find another doctor.");
    }
    else if(code == 3)
    {
        puts("Bad Filename");
        puts("Solution: Spank the filename and put it bed without any supper.");
    }
    else if(code == 4)
    {
        puts("Missing Socket");
        puts("Solution: Look in the dryer");
    }
    else if(code == 5)
    {
        puts("Divide by Zero");
        puts("Solution: Mess with the numbers until it works.");
    }
    else
    {
        puts("Error code value out of range");
        puts("Solution: Read the directions next time.");
    }
    return(0);
}