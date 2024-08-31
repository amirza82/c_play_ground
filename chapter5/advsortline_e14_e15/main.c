/*Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.*/

/*Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
char *lineptr[MAXLINES];    /* pointers to text lines */

// functions
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
void rqsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);

// function pointers
void (*sort) (void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int (*comp) (void*, void*);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;    /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int reverse = 0;    /* 1 if reverse sort */
    int igncase = 0;    /* 1 if ignore case */
    char option;

    for (--argc; argc != 0 && **++argv == '-'; --argc) {
        while ((option = *++(*argv)) != '\0')
            switch (option) {
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 1;
                break;
            case 'f':
                igncase = 1;
                break;
            default:
                fprintf(stderr, "error: unknown flag %c", option);
                return 1;
            }
    }

    // use the flags
    sort = (reverse) ? rqsort : qsort;
    if (numeric)
        comp = (int (*)(void *, void *)) numcmp;
    else if (igncase)
        comp = (int (*)(void *, void *)) strcasecmp;
    else
        comp = (int (*)(void *, void *)) strcmp;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        (*sort) ((void **)lineptr, 0, nlines - 1, comp);
      writelines(lineptr, nlines);
      return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
