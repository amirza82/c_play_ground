/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define MAXLINE 1000

char *malline(size_t len);
size_t getlastn(char **lines, size_t n);
void printlines(char **lines, size_t n, size_t start);
int get_line(char *line, int maxline);

int main(int argc, char *argv[])
{
    // handle the flag
    size_t n, getint(int *);
    if (argc == 2)
        if (argv[1][0] == '-' && isdigit(argv[1][1])) {
            if ((n = atoi(argv[1]+1)) > MAXN) { // set n and check at the same time
                fprintf(stderr, "illigal line number: %zu", n);
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Unknown option %s", argv[1]);
            return EXIT_FAILURE;
        }
    else
        n = 10;

    // get the lines
    char *lines[n];

    printlines(lines, n, getlastn(lines, n));

    return EXIT_SUCCESS;
}

// malline: malloc string
char *malline(size_t len)
{
    return (char *) malloc(len);
}

// getlastn: stores the lest n line of input in "lines[]"
size_t getlastn(char **lines, size_t n)
{
    for (int i = n; i != 0; i--) // make all null
        lines[i] = NULL;
    if (!n)
        return 0;
    char line[MAXLINE];
    size_t len, start = 0;
    while ((len = get_line(line, MAXLINE)) != EOF) {
        if (!lines[start])
            free(lines[start]);
        lines[start] = malline(len);
        strcpy(lines[start], line);
        start = (start+1) % n;
    }
    return start;
}

// printlines: print n lines from "start"
void printlines(char **lines, size_t n, size_t start)
{
    for (size_t i = n; i != 0; --i) {
        if (!lines[start])
            start = (start+1) % n;
        else
            printf("%s\n", lines[start]), start = (start+1) % n;
    }
}

/* getline: read single input line */
int get_line(char *line, int maxline)
{
    short c;
    int n = 0;
    while (n++ < maxline && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    *line = '\0';
    if (c == EOF)
        return EOF;
    else
        return n;
}
