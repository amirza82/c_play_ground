/*
exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
#define ARRAY_MAX 1000
void scape(char s[], char t[]);
void unscape(char s[], char t[]);

int main(void)
{
    char s[] = "hel\\tlo\\n";
    char t[ARRAY_MAX];
    // scape(s, t);
    unscape(s, t);
    printf("%s", t);
    return EXIT_SUCCESS;
}

void scape(char s[], char t[])
{
    char c;
    int i, j;
    for (i = 0, j = 0; j < ARRAY_MAX-1 && (c = s[i]) != '\0'; ++i, ++j) {
        switch (c) {
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;

        case '\n':
            t[j] = '\\';
            t[++j] = 'n';
            break;

        default:
            t[j] = c;
            break;
        }
    }
    t[++j] = '\0';
}


void unscape(char s[], char t[])
{
    char c;
    int i, j;
    bool is_scape = 0;
    for (i = 0, j = 0; (c = s[i]) != '\0'; ++i, ++j) {
        // Used continue instead of break.
        switch (c) {
        case '\\':
            is_scape = 1;
            --j;
            continue;
        case 'n': 
            if (is_scape)
                t[j] = '\n';
                is_scape = false;
            continue;
        case 't':
            if (is_scape)
                t[j] = '\t';
                is_scape = false;
            continue;
        }
        t[j] = c;
    }
}
