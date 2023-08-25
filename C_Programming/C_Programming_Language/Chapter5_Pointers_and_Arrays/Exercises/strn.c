/* Q : Write version of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument
 * string. For example, strncpy(s, t, n) copies at most n characters of t to s. Full descriptions are below.
 * 
 * char *strncpy(s, ct, n) : Copy at most n characters of string ct to s; return s. Pad with '\0's if ct has fewer than n characters
 * 
 * char *strncat(s, ct, n) : Concatenate at most n characters of string ct to string s, terminate s with '\0'; return s.
 * 
 * char *strncmp(cs, ct, n) : Compare at most n characters of string cs to string ct; return < 0 if cs < ct, 0 if cs == ct, or > 0 if cs > ct.
 */
#include <stdio.h>
#include <string.h>

enum
{
    CMP_MATCH = 0,
    CMP_LOWER = -1,
    CMP_BIGGER = 1
}cmp_ret_status;

char *mystrncpy(char *string, char *concat, int n)
{
    char *str = string;
    int len = strlen(concat) - 1;
    for(int i = 0; i < n; i++)
    {
        if(i <= len)
        {
            *string= *concat++;
            string++;
        }
        if(i > len)
        {
            *string = '\0';
            string++;
        }
    }
    return str;
}

char *mystrncat(char *string, char *concat, int n)
{
    char *str = string;
    string += strlen(string);
    for(int i = 0; i < n; i++)
    {
        *string = *concat;
        string++;
        concat++;
    }
    *string = '\0';
    return str;
}

int mystrncmp(char *stringOne, char *stringTwo, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(*stringOne > *stringTwo)
            return CMP_BIGGER;
        if(*stringOne < *stringTwo)
            return CMP_LOWER;
        stringOne++;
        stringTwo++;
    }
    return CMP_MATCH;
}

int main()
{
    char string[] = "Hello World\n";
    char ct[] = "abcd";

    printf("%s\n\n", mystrncpy(string, ct, 4));

    char string2[] = "Hello Sailor!";
    char ct2[] = "azd";

    printf("%s\n\n", mystrncat(string2, ct2, 3));

    char string3[] = "mrSahin101";
    char ct3[] = "mrS";

    if(strncmp(string3, ct3, 3) == CMP_MATCH)
        printf("Matched!\n");
    else if(strncmp(string3, ct3, 3) == CMP_LOWER)
        printf("Lexicographically first string is lower than second string\n");
    else
        printf("Lexicographically first string is bigger than second string\n");

    return 0;
}