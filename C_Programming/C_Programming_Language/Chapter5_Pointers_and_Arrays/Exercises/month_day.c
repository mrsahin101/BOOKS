#include <stdio.h>
#include <assert.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year : set day of year from month & day*/
int day_of_year(int year, int month, int day)
{
    printf("%d\n", month);
    
    assert(month < 13 && month > 0);
    assert((day > 0) && (day < 32));
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month day : set month, day from day of the year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    assert(year <= 0);
    assert(yearday > 366 ||yearday < 1);
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
int main()
{
    printf("%d", day_of_year(2023, 3, 1));
}