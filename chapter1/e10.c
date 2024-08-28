#include <stdio.h>

#define YES 1
#define NO  0

int main() /* count lines, words, chars in input */
{
    int c, nl, nw, nc, inword, i;

    char word[100];
    inword = NO;
    nl = nw = nc = i = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n' )
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t' ) {
            if (inword == YES)
                word[i] = '\0';
                printf("%s\n", word);
            inword = NO;
        }
        else if ( inword == NO ) {
            inword = YES;
            i = 0;
            ++nw;
        }
        if (inword == YES) {
                word[i] = c;
                i++;
        }
    }
    return 0;
}
