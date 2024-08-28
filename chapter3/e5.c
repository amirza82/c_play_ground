/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/

#include <math.h>
#include <stdio.h>
#define EXIT_SUCCESS 0

// Integer n to base b character representation
int itob(int n, char s[], int b);
char itoc(int i);
int log_a_base_b(int a, int b);

int main(void)
{
    int n, b;
    n = 65, b = 16;
    char s[1000];
    itob(n, s, b);
    printf("%s\n", s);
    return EXIT_SUCCESS;
}

int itob(int n, char s[], int b)
{
    int buff;
    if (n < 0)
        s[0] = '-', n = -n;
    else if(n > 0)
        s[0] = '+';
    else {
        s[0] = '0';
        s[1] = '\0';
        return 0;
    }
    int i = log_a_base_b(n, b)+2;
    printf("%d\n", i);
    s[i] = '\0';
    do {
        --i;
        buff = n % b;
        n /= b;
        s[i] = itoc(buff);
        printf("in line 35: buff: %d\t i: %d\tn: %d\ts: %s\n", buff, i, n, s); // DEBUG
    }while (i != 1);
    return 0;
}

char itoc(int i)
{
    if (i >= 0 && i <= 9)
        return '0' + i;
    else if (i >= 10 && i <= 31)
        return 'a' - 10 + i;
    else
        return -1;
}

int log_a_base_b(int a, int b)
{
    if (a < 1)
        return 0;
    return (int) (log(a) / log(b));
}

