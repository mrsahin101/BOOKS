#include <stdio.h>

#define WORD_STATUS_OPEN        1
#define WORD_STATUS_CLOSE       0

int main()
{
    int c;
    int status = 0;
    int current_word_counter = 1;
    int lengthArray[10] = {0};
    status = WORD_STATUS_CLOSE;

    for(int i = 0; i < 10; i++)
        lengthArray[i] = 0;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            if(status == WORD_STATUS_OPEN)
            {
                status = WORD_STATUS_CLOSE;
                lengthArray[current_word_counter - 1] += 1;
                current_word_counter = 0;
            }
        }
        else 
        {
            if(status == WORD_STATUS_OPEN)
            {
                current_word_counter++;
            }
            if(status == WORD_STATUS_CLOSE)
            {
                status = WORD_STATUS_OPEN;
                current_word_counter = 1;
            }
        }
    }

    /* Draw histogram */
    for(int i = 0; i < 10; i++)
    {
        printf("%d : ", i + 1);
        for(int j = 0; j < lengthArray[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}