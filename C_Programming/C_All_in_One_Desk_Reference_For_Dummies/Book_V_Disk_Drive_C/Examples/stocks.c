#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

struct stock_data{
    char name[50];
    float buy_prince;
    float current_place;
};

void write_info(void);
void read_info(void);

int main()
{
    char c;
    int done = FALSE;

    while(!done)
    {
        puts("\nStock Portfolio Thing\n");      
        puts("A - Add new stock\n");
        puts("L - List stocks\n");
        puts("Q - Quit\n");
        printf("Your choice: ");
        
        c = getchar();
        fflush(stdin);          /* fpurge(stdin) for Unix */
        c = toupper(c);
        
        switch(c)
        {
            case('A'):
                puts("Add new stock\n");
                write_info();
                break;
            case('L'):
                puts("List stocks");
                read_info();
                break;
            case('Q'):
                puts("Quit\n");
                done = TRUE;
                break;
            default:
                puts("?");
                break;

        }
    }

    return(0);
}

void write_info(void)
{

}

void read_info(void)
{

}
