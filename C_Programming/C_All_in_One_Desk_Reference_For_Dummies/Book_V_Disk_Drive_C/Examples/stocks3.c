#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

struct stock_data{
    char name[50];
    float buy_prince;
    float current_price;
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
    FILE *stocks;
    struct stock_data stock;
    
    printf("Enter stock name:");
    gets(stock.name);
    printf("How much did you pay for it? $");
    scanf("%f", &stock.buy_prince);
    stock.current_price = stock.buy_prince / 11;

    stocks = fopen("stock.dat", "a");
    if(stocks == NULL)
    {
        puts("Error opening file");
        exit(1);
    }
    fwrite(&stock, sizeof(stock), 1, stocks);

    fclose(stocks);
    puts("Stock added");
    fflush(stdin);
}

void read_info(void)
{
    FILE *stocks;
    struct stock_data stock;
    int x;

    stocks = fopen("stock.dat", "r");
    if(stocks == NULL)
    {
        puts("No data in file");
        return;
    }

    while(TRUE)
    {
        x = fread(&stock, sizeof(stock), 1, stocks);
        if(x == 0)  break;

        printf("\nStock name: %s\n", stock.name);
        printf("Purchased for : $%.2f\n",stock.buy_prince);
        printf("Current prince: $%.2f\n", stock.current_price);
    }
    fclose(stocks);
}
