#include <stdio.h>

int main () 
{
    int in;
    while ((in = getchar()) != EOF)
    {
        printf("%c", lower(in));
    }
}

lower(c)
int c;
{
    int diff = 'a' - 'A';
    if (c >= 'A' && c <= 'Z')
        c = c + diff;
    return c;
}
