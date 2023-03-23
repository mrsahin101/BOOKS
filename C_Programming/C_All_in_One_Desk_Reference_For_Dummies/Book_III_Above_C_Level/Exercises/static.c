#include <stdio.h>
#include <ctype.h>

void request(void);

int main()
{
    char ch;

    do
    {
        puts("\nMain Menu\n=========");
        printf("Press 1 enter new request, Q to quit:");
        ch = toupper(getchar());
        fflush(stdin);

        switch(ch)
        {
            case '1':
                request();
                break;
            case 'Q':
                puts("Quitting Now");
                return(0);
            default:
                puts("\nNaughty Input!");
        }
    }
    while(ch != 'Q');
}

void request(void)
{
    static int x = 0;

    puts("\New Request");
    printf("\tPrevious request was \"%d\"\n", x);
    printf("\tEnter new request: ");
    scanf("%d", &x);
    puts("\Thank you!");
}