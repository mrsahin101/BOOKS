#include <stdio.h>

#define ENGLISH_ALPHABET_LETTER_COUNT       26

int main()
{
    int c;
    int array[ENGLISH_ALPHABET_LETTER_COUNT];

    for(int i = 0; i < ENGLISH_ALPHABET_LETTER_COUNT; i++)
        array[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c >= 'a' || c <= 'z')
            array[c - 'a']++;
    }
    for(int i = 0; i < ENGLISH_ALPHABET_LETTER_COUNT; i++)
    {
        printf("%c : ", i + 'a'); 
        printf("%d\n", array[i]);
    }
}