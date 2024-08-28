/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/

#include <stdio.h>
#define EXIT_SUCCESS 0
void print_range(char from, char to);

int main(void)
{
    char str[] = "-ac-z0-9\n";
    char c;
    for (int i = 0; (c = str[i]) != '\0'; ++i) {
        if ((str[i+1] == '\0' || i == 0) && c == '-')
            putchar('-');
        else if (c == '-')
            print_range(str[i-1]+1, str[i+1]), ++i;
        else
            putchar(c);
    }
    return EXIT_SUCCESS;
}


void print_range(char from, char to)
{
    for (char c = from; c <= to; ++c)
        putchar(c);
}
