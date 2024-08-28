/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char: 0 to %u\n", UCHAR_MAX);
    // ... and so on for each data type
    return 0;
}