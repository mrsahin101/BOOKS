#include <stdio.h>
#include <string.h>

int main()
{
    struct date
    {
        int month;
        int day;
        int year;
    };

    struct family
    {
        char name[20];
        struct date birtday;
    }me;

    /* Fill in your own data here */
    strcpy(me.name, "Dan");
    me.birtday.month = 10;
    me.birtday.day = 19;
    me.birtday.year = 1960;

    printf("%s was born on %d/%d/%d\n", me.name, me.birtday.month, me.birtday.day, me.birtday.year);

    return(0);
}