#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* atof : convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exponent = 1;

    for(i = 0; isspace(s[i]); i++);      /* skip white space */

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    exponent = (s[i] == '-') ? 0 : 1;
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e')
        i++;
    if(s[i] == '-' || s[i] == '+')
    {
        if(s[i] == '-')
            exponent = 0;
        if((s[i]) == '+')
            exponent = 1;
        i++;
    }
    double engexponent = 0;
    for(;isdigit(s[i]); i++)
    {
        engexponent = 10.0 * engexponent + (s[i] - '0'); 
    }
    if(exponent)
        return sign * val / power * pow(10, engexponent);
    else
    {
        engexponent *= -1;
        return sign * val / power * pow(10, engexponent);
    }
        
}

int main()
{
    char string[10] = "3.4511e+6";
    printf("Double pi = %lf", atof(string));
}