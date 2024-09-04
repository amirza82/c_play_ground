#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
#define FBUFSIZE 100
char fbuf[FBUFSIZE];
int fbufp = 0;

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)    /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int fgetch(FILE *fp)
{
    return (fbufp > 0) ? fbuf[--fbufp] : getc(fp);
}

void fungetch(char c, FILE *fp)
{
    if (fbufp >= FBUFSIZE)
        printf("ungetch: too many characters\n");
    else
        fbuf[fbufp++] = c;
}
