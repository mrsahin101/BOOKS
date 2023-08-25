#include <stdio.h>
#include <stdlib.h>
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

char *myitoa(int number, char *buffer)
{
    char *head = buffer;

    while(number > 0)
    {
        *buffer = (number % 10) + ('0');
        number /= 10;
        buffer++;

    }
    for(int i = 0; i < strlen(buffer); i++)
    {
        printf("%c", *(buffer + i));
    }
    *buffer = '\0';
    buffer = head;
    buffer = reverse(head);
    return buffer;
}
int main()
{
    int number = 122355;
    char str[25] = {0};
    printf("%s", myitoa(number, str));
}