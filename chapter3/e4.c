/*exercise 3-4. in a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). explain why
not. modify it to print that value correctly, regardless of the machine on which it runs.*/

#include <limits.h>
#define exit_success 0
/* itoa: convert n to characters in s */
void itoa(int n, char s[]);

int main(void)
{
    return exit_success;
}



void itoa(int n, char s[])
{
    int i, sign;
    if (INT_MIN == n)
        s = "-2147483648", return;
    else if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
