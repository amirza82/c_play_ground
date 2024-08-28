/*Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.*/

#include <stdio.h>
#include <stdlib.h>
#include "../chapter5/e1.c"

int getint(int *);
void day_of_year(int year, int month, int day, int *pday);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int choose;
    int op1, op2, op3, res1, res2;
    getint(&choose);
    switch (choose) {
    case 1:
        getint(&op1);
        getint(&op2);
        getint(&op3);
        day_of_year(op1, op2, op3, &res1);
        printf("day of year: %d\n", res1);
        break;
    case 2:
        getint(&op1);
        getint(&op2);
        month_day(op1, op2, &res1, &res2);
        printf("month day: %d, %d\n", res1, res2);
        break;
    default:
        printf("valid options are 1 and 2");
    }

    return EXIT_SUCCESS;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
void day_of_year(int year, int month, int day, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (year < 1) {
        printf("invlid input year: %d", year);
        return;
    } else if (month < 1 || month > 12) {
        printf("invlid input month: %d", month);
        return;
    } else if (day < 1 || day > daytab[leap][month]) {
        printf("invlid input day: %d", day);
        return;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    *pday = day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (i == 13 && yearday > 31 || yearday < 1) {
        printf("invalid input yearday: %d", yearday);
        return ;
    } else if (year < 1) {
        printf("invalid input year: %d", year);
        return;
    }
    for (i = 1;i <= 13 && yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
