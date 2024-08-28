/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/

#include <stdio.h>
#include <string.h>
#define EXIT_SUCCESS 0
int strindex(char s[], char t[]);

int main(void)
{
    char s[] = "el";
    char t[] = "hello";
    printf("%d\n", strindex(s, t));
    return EXIT_SUCCESS;
}

// A brok ass version of automata
int strindex(char s[], char t[])
{
    unsigned int s_len = strlen(s)-1;
    unsigned int t_len = strlen(t)-1;
    if (s_len > t_len)
        return -2;
    for (int i = 0; t[i+s_len] != '\0'; ++i) {
        if (t[i] == s[0])
            for(int j = s_len; j != -1; --j) {
                printf("i: %d\tj: %d\n", i, j);
                if (j == 0 && s[j] == t[j+i]) // found pattern
                    return i;
                else if (s[j] == t[j+i]) // next pattern mached
                    continue;
                else
                    break;
            }
        else
            continue;
    }
    return -1;
}
