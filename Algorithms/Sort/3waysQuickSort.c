#include <stdio.h>
#include <stdlib.h>

void exch(int a[], int i, int j) {
    int item = a[i];
    a[i] = a[j];
    a[j] = item;
}

void Sort(int a[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int left = lo, i = lo + 1, right = hi;
    int cmp = a[lo];
    while (i <= right) {
        if (cmp > a[i]) {
            exch(a, left++, i++);
        } else if (cmp < a[i]) {
            exch(a, i, right--);
        } else {
            i++;
        }
    }
    Sort(a, lo, left-1);
    Sort(a, right + 1, hi);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Expected at least 2 value but got only %d.\n", argc-1);
    }
    int array[argc-1];
    for (int i = 1; i < argc; i++) {
        array[i-1] = atoi(argv[i]);
    }
    Sort(array, 0, argc-2);
    for (int i = 0; i < argc-1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}