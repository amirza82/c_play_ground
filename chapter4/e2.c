/*Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/
#include <math.h>
#include <stdio.h>
#include <ctype.h>

#define EXIT_SUCCESS 0
#define MAXLINE 100
/* atof: convert string s to double */
double atof(char s[]);

int main ()
{
    double sum, atof(char []);
    char line[MAXLINE];
    sum = 0;
    int get_line(char [], int);
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return EXIT_SUCCESS;
}

double atof(char s[])
{
    double val, power, pow(double, double);
    int i, sign;
    int exponent = 0;
    int expoSign = 1;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e') {
        expoSign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') 
            ++i;
        for (exponent = 0; isdigit(s[i]); ++i)
                exponent = 10 * exponent + (s[i] - '0');
    }
    return (sign * val / power) * pow(10.0, exponent * expoSign);
}

int get_line(char line[], int max)
{
    int c, i;
    for (i = 0;i < max && (c = getchar()) != '\n' && c != EOF; ++i) {
        line[i] = c;
    }
    line[i] = '\0';
    if (c == EOF)
        return 0;
    else
        return i;
}
