/* Q : Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s and zero otherwise*/
#include <stdio.h>
#include <string.h>

typedef enum{TRUE = 1, FALSE = 0} bool;

/* RetVal : True if snippet occurs at end of source string
 *          False if snippet doesnt occur at end of source string
*/
bool strend(char *string, char *mini)
{
    bool equal = FALSE;
    char *sptr = string;
    char *mptr = mini;
    string = (string + (strlen(string)));
    mini = (mini + (strlen(mini)));

    for(int i = 0; i < strlen(mptr) + 1; i++)
    {
        printf("\n%dth cycle ->  ", i + 1);
        printf("sptr : %c, mptr : %c,\n", *string, *mini);
        if((*string) == (*mini))
        {
            printf("Matched! Continuing\n");
        }
        else
        {
            printf("Unmatch Found!\n");
            return FALSE;
        }
        
        string--;
        mini--;
        
        
    }
    printf("Matching Done!\n");
    return TRUE;
    printf("%s", sptr);
    printf("%s", mptr);
}

int main()
{   
    char msg[] = "Hello";
    char mini[] = "lo";

    if(strend(msg,mini) == TRUE)
        printf("Correct\n");
    else
        printf("False");

    return 0;
}