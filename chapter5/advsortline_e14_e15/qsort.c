/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)          /* do nothing if array contains */
        return;                 /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

/* rqsort: sort v[left]...v[right] into decreasing order */
void rqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)          /* do nothing if array contains */
        return;                 /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (-(*comp)(v[i], v[left]) < 0)  // Swapped the arguments
            swap(v, ++last, i);
    swap(v, left, last);
    rqsort(v, left, last - 1, comp);
    rqsort(v, last + 1, right, comp);
}


void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
