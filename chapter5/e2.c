/*Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
getfloat return as its function value?*/
#include <ctype.h>
#include <stdio.h>
#include "../chapter4/getch.c"
#include "../chapter4/calc.h"

int getfloat(double *);

int main (void)
{
    double i;
    printf("%d\n", getfloat(&i));
    printf("%lf\n", i);
}

int getfloat(double *pf)
{
    int c, sign;
    double i;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '+')
        c = getch();
    for (*pf = 0; isdigit(c); c = getch())
        *pf = *pf * 10 + (c - '0');
    if (c == '.')
        c = getch();
    for (*pf, i = 0.1; isdigit(c); c = getch(), i /= 10)
        *pf = *pf + i*(c - '0');
    if (c != EOF)
        ungetch(c);
    return c;
}
