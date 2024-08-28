/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/

// Functions
#include <stdio.h>
#include <limits.h>
char* rm_prefix(char str_in[]); // Remove 0x or 0X prefix if exists
int char_to_int(char c); // in: char 0 to f     out: int hex
long str_to_int(char str_in[]); // in: String of hex out: hex integer


int main(void)
{
    // char hex[] = "0Xf21";
    // char hex[] = "324";
    char hex[] = "0xfe1";
    long ans;
    ans = str_to_int(hex);
    printf("%ld", ans);
    return 0;
}

long str_to_int(char str_in[])
{
    long out = 0;
    int ci;
    char c;
    for (int i = 0; (c = str_in[i]) != '\0'; ++i) {
        if ((ci = char_to_int(c)) != -1)
            out = out * 0x10 + ci;
    }
    return out;
}

int char_to_int(char c)
{
    if (c >= '0' && c <= '9' || c >= 'a' && c <= 'f') {
        for (int i = '0'; i <= '9'; ++i) {
            if (c == i)
                return i - '0';
        }

        for (int i = 'a'; i <= 'f'; ++i) {
            if (c == i)
                return i - 'a' + 10;
        }
    }
    return -1;
}

char* rm_prefix(char str_in[])
{
    char str_out[(int) sizeof(int)/4];
    if (str_in[0] == '0')
        return str_in;
    else {
        for (int i = 2; (str_out[i-2] = str_in[i]) != '\0'; ++i)
            ;
    }
}
