#include <stdio.h>

void itoa (int, char *);
char str[100];
int index;

int main (void)
{
    itoa(1234, str);
    printf("%s\n", str);
    printf("%d\n", index);
    index = 0;
    itoa(-4235, str);
    printf("%s\n", str);
}

void itoa (int i, char *str)
{
    if (i < 0) {
        str[index++] = '-';
        i = -i;
    }
    if (i == 0) {
        ;
    } else {
        itoa(i/10, str);
        str[index++] = i % 10 + '0';
    }
}
