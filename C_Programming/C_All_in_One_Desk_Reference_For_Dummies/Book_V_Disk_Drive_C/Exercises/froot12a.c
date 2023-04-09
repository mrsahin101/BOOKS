#include <stdio.h>

#define RECSIZE 14

void readNthRecord(int recordNumber);

int main()
{
    for(int i = 0; i < RECSIZE; i++)
        readNthRecord(i);
    
    return(0);
}
void readNthRecord(int recordNumber)
{
    FILE *f;
    char froot[RECSIZE];
    int record, offset;

    if(!(f = fopen("froot.txt", "r")))
    {
        puts("Error opening file");
        return;
    }
    
    /* Get record 12, record size = RECSIZE */
    record = recordNumber;
    offset = record * RECSIZE;
    fseek(f, offset, SEEK_SET);
    fread(froot, RECSIZE, 1, f);
    printf("%2d: %s\n", record, froot);
    fclose(f);
}