#include <stdio.h>

int main() /* count lines in input */
{
    int c, nl;
    char str[100];
    int first_blank = 0;
    nl = 0;
    int str_iter = 0;
    for (c = getchar(); c != EOF; c = getchar())
    {
        if (c == ' ' && first_blank == 1)
            continue;
        else if (c != ' ')
            first_blank = 0;
        str[str_iter] = c;
        if (c == ' ')
            first_blank = 1;
        str_iter++;
    }
    printf("%s", str);
    return 0;
}
