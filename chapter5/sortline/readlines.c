#include <stdio.h>
#include <string.h>

#define MAXLINE 1000    /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], unsigned int nlines)
{
    int i;
    while (nlines-- != 0)
        printf("%s\n", *lineptr++);
}

/* getline: read single input line */
int get_line(char *line, int maxline)
{
    short c;
    int n = 0;
    while (n++ < maxline && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    if (c == EOF)
        return 0;
    *line = '\0';
    return n;
}
