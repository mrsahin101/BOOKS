/* Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value */
#include <stdio.h>
#include <ctype.h>

#define MAX         40


int getch(void);
void ungetch(int c);
/* Convert string into floating point number*/
int getfloat(float *buffer)
{
    char c;
    int sign, afterComma;
    //TODO : Read data from input stream
    while(isspace(c = getch()));
    // TODO : Control if input is appropriate
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') 
		return 0;
    
    sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
	}
    // TODO : parse input stream
    while (isdigit(c)) {
		*buffer = 10.0 * *buffer + (c - '0');
		c = getch();
	}
    afterComma = (c == '.') ? 1 : 0;
    float temp = 1.0f;
    while(isdigit(c = getch()) && afterComma == 1)
    {
        temp = temp / 10.0; 
        *buffer += temp * (c - '0');
    }
    // TODO : Convert input stream into floating point

    // return status via function, return converted float point number via pointer
    return 1;

}

int main()
{
    float buffer[MAX];
    float val;
    // TODO: Call get float, fill buffer
    // TODO: Print as floating point number
    // for (int i = 0; i < MAX && (val = getfloat(&buffer[i])) != EOF; i++)
	// 	printf("num[%d] = %f, \tvalue returned: %f (%s)\n", i, buffer[i], val, val != 0 ? "number" : "not a number");
    getfloat(buffer);
    printf("Item %f\n", buffer[0]);
    
}
int bufp = 0;
float buf[MAX];

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}