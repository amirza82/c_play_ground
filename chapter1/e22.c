/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

#include <stdio.h>

#define LINE_LEN_CAP 10
#define MAX_IN_LEN 1000
#define MAX_WORD_LEN LINE_LEN_CAP

// Functions
int get_line(char line[]);
void parse_line(char line[]);
void print_range(char line[], int from, int to);

// Main
int main ()
{
    char line[MAX_IN_LEN];
    while (get_line(line) != EOF) {
        parse_line(line);
    }
    return 0;
}

// Return 0 if EOF
// else return 1
int get_line(char line[]) {
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && (c != '\n') && (i < MAX_IN_LEN)) {
            line[i] = c;
            ++i;
    }

    line[i] = '\0';

    if (c == '\n')
        return 1;
    else
        return EOF;
}

// Ptint each line in the correct form
void parse_line(char line[])
{
    int from, to, i;
    from = to = i = 0;
    for (i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ' '){
            to = i;
        }
        if (i % LINE_LEN_CAP >= LINE_LEN_CAP - 1) {
            print_range(line, from, to);
            from = ++to;
        }
    }
    to = --i;
    print_range(line, from, to);
}

// Print char array from index 'from' to index 'to'
void print_range (char line[], int from, int to)
{
    for (int i = from; i <= to; ++i)
        putchar (line[i]);
    putchar('\n');
}
