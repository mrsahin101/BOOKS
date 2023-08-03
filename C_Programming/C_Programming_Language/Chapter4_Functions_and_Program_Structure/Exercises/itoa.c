#include <stdio.h>
#include <string.h>

/* swap : interchange v[i] and v[j] */
void swap(char v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* reverse string s in place */
// Recursive function to reverse the string
void recursiveReverse(char str[], int i)
{
	int n = strlen(str);
	if (i == n / 2)
		return;
// Swap the i and n-i-1 character
	swap(str, i, n - i - 1);
// Call Recursive function after incrementing i.
	recursiveReverse(str, i + 1);
}

/* itoa : convert n to characters in s */
void itoa(int n, char s[])
{
    
    static int i = -1;
    s[++i] = n % 10 + '0';
    n = n / 10;
    if(n > 0)
        itoa(n, s);
    else
    {
        
        s[++i] = '\0';
        recursiveReverse(s, 0);
    }
}

int main()
{
    int number = 124112412;
    char strnumber[20];

    itoa(number, strnumber);

    printf("%s", strnumber);
}