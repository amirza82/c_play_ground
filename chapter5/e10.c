/*
Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int expt(int argc, char **argv, double *result);

int main (int argc, char **argv)
{
    double result;
    expt(--argc, ++argv, &result);
    printf("result: %lf", result);
    return EXIT_SUCCESS;
}


#define ARGLEN 1000
double atof(const char *nptr);
void push(double d);
double pop();

int expt(int argc, char **argv, double *result)
{
    int isop (char *arg);
    char *argn;
    double op2;
    while (--argc >= 0) {
        argn = *argv++;
        if (isop(argn))
            switch (*argn) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                default:
                    printf("error: unknown operator: %c", *argn);
                    break;
            }
        else
            push(atof(argn));
    }
    *result = pop();
    return 0;
}


#define STACKLEN 1000
double stack[STACKLEN];
double *stackp = stack;

void push(double d)
{
    if (stackp - stack <= STACKLEN)
        *stackp++ = d;
    else
        printf("push: error: stack full\n");
}

double pop()
{
    if (stack == stackp)
        printf("pop: error: stack empty\n");
    else
        return *--stackp;
    return 0;
}


#define OPERATORCOUNT 4
char operator[] = {'+', '-', '*', '/'};
// isop: is the argument(string) an operator or not
int isop(char *arg)
{
    if (strlen(arg) != 1)
        return 0; // not an operator
    for (int i = OPERATORCOUNT-1; i >= 0; --i)
        if (operator[i] == *arg)
            return 1;
    return 0;
}
