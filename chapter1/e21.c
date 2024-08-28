/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
*/

#include <stdio.h>
#define TAB_SPACE 6

int main()
{
    int space_count = 0;
    int c;
    while (c = getchar()) {
        if (c == ' ') {
            ++space_count;
            continue;
        } else if (c == '\t') {
            space_count += TAB_SPACE;
            continue;
        }
        for (int i = 0; i < space_count/TAB_SPACE; ++i)
                putchar('\t');

        for (int i = 0; i < space_count%TAB_SPACE; ++i) {
            putchar(' ');
        }
        if (c == EOF)
            return 0;
        space_count = 0;
        putchar(c);
    }

}
