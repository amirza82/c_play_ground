/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/

#include <stdio.h>
#include <ctype.h>
#include "../chapter4/calc.h"
#include "../chapter4/getch.c"
int getint(int *);
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c1, c2, sign;
    while (isspace(c1 = getch()))    /* skip white space */
        ;
    if (!isdigit(c1) && c1 != EOF && c1 != '+' && c1 != '-') {
        ungetch(c1); /* it is not a number */
        return 0;
    }
    sign = (c1 == '-') ? -1 : 1;
    if (c1 == '+' || c1 == '-')
        if (isdigit(c2 = getch())) {
            c1 = c2;
        } else {
            ungetch(c2);
        }

    for (*pn = 0; isdigit(c1); c1 = getch())
       *pn = 10 * *pn + (c1 - '0');
    *pn *= sign;
    if (c1 != EOF)
        ungetch(c1);
    return (size_t) c1;
}
