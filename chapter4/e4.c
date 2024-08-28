/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.*/
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // for atof()
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100/* maximum depth of val stack */
#define BUFSIZE 100 /* buffer for ungetch */
char buf[BUFSIZE];
int bufp = 0; /* next free position in buf */
int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void popall(void);
void swaptop(void);
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* reverse Polish calculator */
int main()
{
    bool ignnl = false;
    int type;
    double op1, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                ignnl = true;
                push(atof(s));
                break;
            case '+':
                ignnl = false;
                push(pop() + pop());
                break;
            case '*':
                ignnl = false;
                push(pop() * pop());
                break;
            case '-':
                ignnl = false;
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                ignnl = false;
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                ignnl = false;
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '\n':
                if (!ignnl)
                    printf("\t%.8g\n", pop());
                    ignnl = false;
                break;
            case 'C': // [C]lear the stack
                ignnl = true;
                popall();
                break;
            case 'T': // print [T]op element
                ignnl = true;
                push(op2 = pop());
                printf("\t%.8g\n", op2);
                break;
            case 'D': // [D]uplicate laset element
                ignnl = true;
                push(op2 = pop());
                push(op2);
                break;
            case 'S': // [S]wap the 2 last element
                ignnl = true;
                swaptop();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
    return 0.0;
    }
}

/*popall: clear the stack*/
void popall(void)
{
    sp = 0;
}

/*swaptop: swaps the 2 top elements */
void swaptop(void)
{
    double buff;
    if (sp > 1) {
        buff = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = buff;
    } else
        printf("Can't swap with less than 2 element in stack");
}
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-' && c != '+')
        return c; /* not a number */
    else if ((c == '-' || c == '+') && !isdigit(c = getch())) {
        ungetch(c);
        return s[0];
    } else if ((s[0] == '-' || s[0] == '+')) {
        s[++i] = c;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)    /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
