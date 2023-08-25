#include <stdio.h>
#include <string.h>

char *reverse(char *string)
{
    char *head = string;
    int len = strlen(string);

    for(int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        char temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
    }
    *(string + len) = '\0';
    return head;
}

int main()
{
    char msg[] = "Hello World";
    printf("reverse : %s", reverse(msg));
} 