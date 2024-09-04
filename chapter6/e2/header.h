#ifndef HEADER
#define HEADER 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <wctype.h>
#define MAXWORD 100

int getword(char *word);
int fgetword(char *word, FILE *fp);
int fgetval(char *word, FILE *fp);

#define getval(word) fgetval((word), stdin)
#define afterval(inl, word) fafterval((inl), (word), stdin)

#define IDLEN 3
struct llist {
    char *var;
    struct llist *next;
};

struct tnode {
    char *ID;
    struct tnode *left;
    struct tnode *right;
    struct llist *vars ;
};

void ftprint(FILE *fp, struct tnode *root);
struct tnode *tadd(struct tnode *root, char *id, char *key);

#define tprint(root) ftprint(stdin, (root))

#endif
