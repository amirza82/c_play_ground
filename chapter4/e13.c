#include <stdio.h>
#include "string.h"
#define swap(A, B, TYPE)  {TYPE buffffff = (A); ((A) = (B)); ((B) = (buffffff));}

void reverse(char *, int);

int main (void)
{
    char str[] = "hello";
    reverse(str, strlen(str));
    printf("%s\n", str);
}
void reverse(char *str, int strlen)
{
    if (str[strlen] == '\0')
        --strlen;
    if (strlen < 1)
        return;
    reverse(str+1, strlen-2);
    swap(str[0], str[strlen], char);
}
