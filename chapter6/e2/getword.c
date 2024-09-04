#include "header.h"

int getch(void);    /* get a (possibly pushed-back) character */
void ungetch(int c);   /* push character back on input */
int fgetch(FILE *fp);
void fungetch(char c, FILE *fp);
int fafterval(int *inl, char *word, FILE *fp);
int isdt(char *);
void skipuntil(char *, char);

char *datatypes[] = {"int", "char", "double", "void"};
#define DTCOUNT (sizeof (datatypes) / sizeof (char *))

// getword: get the next word. word definition same as vi.
int getword(char *word)
{
    char c, r;
    while (iswspace(c = getch()))
        ;
    if (c == EOF) {
        *word = '\0';
        return EOF;
    }
    r = *word = c;
    if (isalpha(c) || c == '_') {
        while (isalpha(c = getch()) || isdigit(c) || c == '_')
            *++word = c;
        ungetch(c);
    }
    *++word = '\0';
    return r;
}

// fgetword: get the next word in file. word definition same as vi.
int fgetword(char *word, FILE *fp)
{
    char c, r;
    while (iswspace(c = fgetch(fp)))
        ;
    if (c == EOF) {
        *word = '\0';
        return EOF;
    }
    r = *word = c;
    if (isalpha(c) || c == '_') {
        while (isalpha(c = fgetch(fp)) || isdigit(c) || c == '_')
            *++word = c;
        fungetch(c, fp);
    }
    *++word = '\0';
    return r;
}

// fgetval: return value name from file
int fgetval(char *word, FILE *fp)
{
    static int inl = 0;
    if (inl) { // already in a line with multiple variable from last call
        fgetword(word, fp); // this is the variable name
        return fafterval(&inl, word, fp);
    } else {
        while (fgetword(word, fp) != EOF)
            if (isdt(word)) {
                inl = 1;
                while (fgetword(word, fp) == '*') // skip the '*'s
                    ;
                return fafterval(&inl, word, fp);
            }
    }
    return 0;
}
// if inl == 1, it is garantied that the next word is the word after ','

// <datatypa> [*] <name> [ [ | ; | , ]

int fafterval(int *inl, char *word, FILE *fp)
{
    char nword[MAXWORD];
    if (fgetword(nword, fp) == '(') {
        skipuntil(nword, ')'); 
        if (fgetword(nword, fp) == ';') {
            *inl = 0;
            return fgetval(word, fp);
        } else if (*nword == ',') {
            return fgetval(word, fp);
        } else if (*nword == '{') {
            *inl = 0;
            skipuntil(nword, '}');
            return fgetval(word, fp);
        } else {
            printf("afterval: error invalid syntax: %s\n", nword);
            return 0;
        }
    } else if (*nword == '[') {
        skipuntil(nword, ']');
        if (fgetword(nword, fp) == ';') {
            *inl = 0;
            return 1;
        } else if (*nword == ',') {
            return 1;
        } else if (*nword == '=') {
            *inl = 0;
            return 1;
        }
    } else if (*nword == ',') {
        return 1;
    } else if (*nword == ';') {
        *inl = 0;
        return 1;
    } else {
        printf("afterval: error unexpected word %s\n", nword);
    }
    return 0;
}

int isdt(char *word)
{
    for (int i = DTCOUNT; i != 0; )
        if (!strcmp(datatypes[--i], word))
            return 1;
    return 0;
}


void skipuntil(char *nword, char c)
{
    if (*nword == c)
        return;
    while(getword(nword) != c)
        ;
}
