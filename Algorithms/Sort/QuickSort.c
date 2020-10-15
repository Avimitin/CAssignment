#include <stdio.h>
#include <stdlib.h>

extern void QuickSort(int lenth, int *a);

void Exch(int *i, int *j);

int Partition(int a[], int lo, int hi) {
    int i = lo; int j = hi + 1;
    int v = a[lo];
    while (1) { 
        while (a[++i] < v) {
            if (i == hi) {
                break;
            }
        }
        while (a[--j] > v) {
            if (j == lo) {
                break;
            }
        }
        if (i >= j) { break; }
        Exch(a+i, a+j);
    }
    Exch(a+lo, a+j);
    return j;
}

void _quick_sort(int  a[], int lo, int hi) {
    if (hi <= lo) { return; }
    int j = Partition(a, lo, hi);
    _quick_sort(a, lo, j-1);
    _quick_sort(a, j+1, hi);
}

void QuickSort(int lenth, int *a) {
    _quick_sort(a, 0, lenth-1);
}