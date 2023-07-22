#include <stdio.h>
#include <limits.h>

int main()
{
    printf("signed char type sizes\n");
    printf("Byte size :%d, Minimum : %d, Maximum : %d\n\n", sizeof(char), SCHAR_MIN, SCHAR_MAX); 

    printf("unsigned char type sizes\n");
    printf("Byte size: %d, Minimum : %d, Maximum : %d\n\n", sizeof(unsigned char), 0, UCHAR_MAX);

    printf("int type sizes\n");
    printf("Byte size : %d, Minimum : %d, Maximum : %d\n\n", sizeof(int), INT_MIN, INT_MAX);

    printf("short int type sizes\n");
    printf("Byte size : %d, Minimum : %d, Maximum : %d\n\n", sizeof(short int), SHRT_MIN, SHRT_MAX);

    printf("long int type sizes\n");
    printf("Byte size : %ld, Minimum : %ld, Maximum : %ld\n\n", sizeof(long int), LONG_MIN, LONG_MAX);

    printf("unsigned long int type sizes\n");
    printf("Byte size : %lu, Minimum : %lu, Maximum : %lu\n\n", sizeof(unsigned long int), 0, ULONG_MAX);
}