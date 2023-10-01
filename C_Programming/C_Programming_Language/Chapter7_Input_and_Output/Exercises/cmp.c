#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("ERROR! Not enough arguments\n");
        return 1;
    }
    else
    {
        char *firstFILE = argv[1], *secondFILE = argv[2];
        FILE *firstptr, *secondptr;
        if((firstptr = fopen(firstFILE, "r")) == NULL)
        {
            fprintf(stderr, "Unable to open first file\n");
            exit(1);
        }
        else
        {
            if((secondptr = fopen(secondFILE, "r")) == NULL)
            {
                fprintf(stderr, "Unable to open second file\n");
                exit(1);
            }
            else
            {
                char firstLine[255], secondLine[255];
                int lineNumber = 1;
                bool differenceFound = false;
                
                while((fgets(firstLine, sizeof(firstLine), firstptr) != NULL) && (fgets(secondLine, sizeof(secondLine), secondptr) != NULL))
                {
                    if(strstr(firstLine, secondLine) == NULL)
                    {
                        differenceFound = true;
                        break;
                    }
                    lineNumber++;
                }
                if(differenceFound == true)
                {
                    printf("Their difference begin from line : %d\n\n", lineNumber);
                    printf("In line %d first file -> %s",lineNumber, firstLine);
                    printf("In line %d second file -> %s",lineNumber, secondLine);
                }
                else
                {
                    printf("No difference found, it must be exact or shorter version of each other\n");
                }
                
            }
        }
    }
}