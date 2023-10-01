#include <stdio.h>
#include <ctype.h>

int main()
{
    for(int i = 0; i < 128; i++)
    {
        if(isgraph(i) == 0)
        {
            printf("0x%X\n", i);
        }
    }
}