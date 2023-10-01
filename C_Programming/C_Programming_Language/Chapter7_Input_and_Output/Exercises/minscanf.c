#include <stdio.h>
#include <stdarg.h>

/* minscanf : minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    /* make argument list pointer*/
    va_list ap;             /* points to each unnamed arg in turn */
    // sval : pointer for string, p : scanf first argument
    char *p, *sval;
    int *intptr;
    double *doubleptr;
    va_start(ap, fmt);      /* make ap point to 1st unnamed arg*/
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch(*++p)
        {
            case 'd':
                intptr = va_arg(ap, int *);
                scanf("%d", intptr);
                break;
            case 'f':
                doubleptr = va_arg(ap, double *);
                scanf("%f", doubleptr);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            case 'o':
                intptr = va_arg(ap, int *);
                scanf("%o", intptr);
                break;
            case 'x':
                intptr = va_arg(ap, int *);
                scanf("%x", intptr);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
int main(int argc, char *argv[])
{
    int integer;
    float doubleNumber;
    char name[255];
    printf("Please Enter a integer number : ");
    minscanf("%d", &integer);
    printf("The number you have entered : %d\n\n", integer);

    printf("Please Enter a double number : ");
    minscanf("%f", &doubleNumber);
    printf("The double number you have entered : %f\n\n", doubleNumber);

    printf("Please Enter a name : ");
    minscanf("%s", &name);
    printf("The name you have entered : %s\n\n", name);

    printf("Please Enter a octal number : ");
    minscanf("%o", &integer);
    printf("The octal number you have entered : %o, and its integer corresponded number is : %d\n\n", integer, integer);

    printf("Please Enter a hexadecimal number : ");
    minscanf("%x", &integer);
    printf("The hexadecimal number  you have entered : %x, and its hexadecimal corresponded number is : %d\n\n", integer, integer);
}