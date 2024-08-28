/*
Exercise 2-2. Write a loop equivalent to following the for loop without using && or ||.
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
*/
#include <stdio.h>

int main ()
{
    int lim = 100;
    char s[lim];
    int i, c;
    for (i = 0; (lim-1) == ((c=getchar()) != '\n') == (c != EOF) == 1; i++)
    {
        s[i] = c;
    }
}