#include <stdio.h>

struct _fl
{
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
}flags;

int main()
{
    flags.is_extern = 0x1;

    printf("%d", flags.is_extern);
}