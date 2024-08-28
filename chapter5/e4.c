/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.*/

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main (void)
{
    char s[] = "tttsssa";
    char t[] = "ss";
    printf("%d\n", strend(s, t));
}

int strend(char *s, char *t)
{
    unsigned long s_len = strlen(s);
    unsigned long t_len = strlen(t);
    unsigned long delta = s_len - t_len;

    if (s_len >= t_len) {
        s += delta;
        for (t_len; t_len > 0; --t_len)
            if (*s++ != *t++)
                return 0;
    } else {
        return 0;
    }
    return 1;
}
