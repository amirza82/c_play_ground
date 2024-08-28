#include <stdio.h>
int main() /* count lines in input */
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == ' ' || c == '\t')
            ++nl;
    printf("%d\n", nl);
    return 0;
}
