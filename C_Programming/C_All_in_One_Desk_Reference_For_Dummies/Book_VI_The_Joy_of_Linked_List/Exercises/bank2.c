#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearInput(void);
void addNewAccount(void);
void listAll(void);
void deleteAccount(void);
void modifyAccount(void);

struct account{
    int number;
    char lastname[15];
    char firstname[15];
    float balance;
    struct account *next;
};
struct account *firsta, *currenta, *newa;
int anum = 0;

int main()
{
    char ch;
    firsta = NULL;

    do
    {
        clearInput();
        puts("\nA- Add a new account");
        puts("D - Delete Account");
        puts("L - List all!");
        puts("M - Modify Account");
        puts("Q - Quit this program\n");
        printf("\tYour choice:");
        ch = getchar();
        ch = toupper(ch);

        switch(ch)
        {
            case 'A':
                puts("Add new account\n");
                clearInput();
                addNewAccount();
                break;
            case 'D':
                puts("Delete account");
                clearInput();
                deleteAccount();
            case 'L':
                puts("Listing all");
                clearInput();
                listAll();
                break;
            case 'M':
                puts("Modify account");
                clearInput();
                modifyAccount();
            case 'Q':
                puts("Quit\n");
            default:
                break;
        }
    }while (ch != 'Q');
    
    return(0);
}

/* This function clears any text from the input stream */
void clearInput(void)
{
    fflush(stdin);      /* fpurge(stdin) in Unix*/
}

void addNewAccount(void)
{
    newa = (struct account*)malloc(sizeof(struct account));
    /* Check to see if this is the first record
     * If so, then initialize all the pointers to this 
     * first structure in the database
     */
    if(firsta == NULL)
        firsta = currenta = newa;
    /* Otherwise, you must find the end of the structure list
     *(easily spotted by the NULL pointer) and add on the new 
     * structure you just allocated memory for
     */
    else
    {
        currenta = firsta;      /* make first record current*/
                                /*loop through all records; */
        while(currenta->next != NULL)
            currenta = currenta->next;
        /* the last record is found */
        currenta->next = newa;      /*save the address of new */
        currenta = newa;            /*make current record new */
    }

    /* Now you just fill in the new structure */
    anum++;
    printf("%27s: %5i\n", "Account number", anum);
    currenta->number = anum;

    printf("%27s: ", "Enter customer's last name");
    gets(currenta->lastname);

    printf("%27s: ", "Enter customer's first name");
    gets(currenta->firstname);

    printf("%27s: ", "Enter account balance");
    scanf("%f", &currenta->balance);

    /* Finally, cap the new record with a NULL pointer
     * so that you know it's last record:
     */
    currenta->next = NULL;
}

void listAll(void)
{
    currenta = firsta;

    while(currenta != NULL)
    {
        printf("****************************************\n");
        printf("Customer Number : %d\n", currenta->number);
        printf("Customer Name : %s %s\n", currenta->firstname, currenta->lastname);
        printf("Customer Balance : %f\n", currenta->balance);
        printf("****************************************\n\n");
        currenta = currenta->next;
    }
    currenta = firsta;
}
void deleteAccount(void)
{
    int record;
    struct account *previousa;

    if(firsta == NULL)
    {
        puts("There is no records to delete!");
        return;
    }

    listAll();      /* Show all records first */
    printf("Enter account number to delete : ");
    scanf("%d", &record);

    currenta = firsta;
    while(currenta != NULL)
    {
        if(currenta->number == record)
        {
            /*A special case is made for the first record. That’s because the first record
            has no previous record*/
            if(currenta == firsta)      /* special condition */ 
                firsta = currenta->next;
            else
                previousa->next = currenta->next;
            free(currenta);
            printf("Account %d deleted!\n", record);
            return;
        }
        else
        {
            previousa = currenta;
            currenta = currenta->next;
        }
    }
    printf("Account %d was not found!\n", record);
    puts("Nothing deleted.");
}

void modifyAccount(void)
{
    int record;

    if(firsta == NULL)
    {
        puts("There is no records to modify!");
        return;
    }

    listAll();      /* Show all records first */
    printf("Enter account number to modify : ");
    scanf("%d", &record);

    currenta = firsta;
    while(currenta != NULL)
    {
        if(currenta->number == record)
        {
            /*A special case is made for the first record. That’s because the first record
            has no previous record*/
            printf("Enter new number :");
            scanf("%d", &currenta->number);
            printf("Account %d modified! New account number is : %d\n", record, currenta->number);
            return;
        }
        else
            currenta = currenta->next;

    }
    printf("Account %d was not found!\n", record);
    puts("Nothing modified.");
}