/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.
*/
#include <stdio.h>
#define EXIT_SUCCESS 0


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int x = 1;
    int n = 8;
    int ans = binsearch(x, v, n);
    printf("%d\n", ans);
    return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (high >= low) {
        mid = (high + low)/2;
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1; // No match
}
