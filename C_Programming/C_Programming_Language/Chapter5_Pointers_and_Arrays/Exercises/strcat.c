/* Q: Write a pointer version of the function strcat that,
 * we showed in Chapter 2: strcat(s,t), copies the string t to the end of s
 */
#include <stdio.h>

void mystrcat(char *head, char *tail)
{
    char *ptr = head;
    while(*head++);
    head--;
    while((*head++ = *tail++) != '\0');
    *head = '\0';
    head = ptr;
}

int main()
{
    char msg[50] = "Hello world.";
    char echo[] = "This is Mrsahin!\n";
    mystrcat(msg, echo);
    printf("%s", msg);
}