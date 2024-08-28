/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.*/
int printf (const char *__restrict __format, ...);
char *strcat (char *s, char *t);

int main (void)
{
    char s[10] = "sss";
    char t[4] = "ttt";
    printf("before:\n");
    printf("%s\n", s);
    printf("%s\n", t);
    strcat(s, t);
    printf("after:\n");
    printf("%s\n", s);
    printf("%s\n", t);
    return 0;
}

char *strcat(char *s, char *t)
{
    while (*s++ != '\0')
        ;
    --s;
    while ((*s++ = *t++) != '\0')
        ;
    return s-1;
}
