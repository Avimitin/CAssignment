#include <stdio.h>
#include <stdlib.h>

int *aux;
extern void MergeSort(int length, int *a);

extern void Merge(int a[], int lo, int mid, int hi) {
    int i = lo;
    int j = mid+1;

    for (int k=lo; k <= hi; k++) {
        aux[k] = a[k];
    }
    
    for (int k=lo; k <= hi; k++) {
        if      (i > mid)           { a[k] = aux[j++]; }
        else if (j > hi)            { a[k] = aux[i++]; }
        else if (aux[i] > aux[j])   { a[k] = aux[j++]; } 
        else                        { a[k] = aux[i++]; }
    }
}

void Sort(int a[], int lo, int hi) {
    if (hi <= lo) { return; }
    int mid = lo + (hi-lo)/2;

    Sort(a, lo, mid);
    Sort(a, mid + 1, hi);
    Merge(a, lo, mid, hi);
}

void UDInit(int length) {
    aux = calloc(length, sizeof(int));
    if (aux == NULL) {
        fprintf(stderr, "array init fail.");
        exit(-1);
    }
}

void MergeSort(int length, int *a) {
    UDInit(length);
    Sort(a, 0, length-1);
    free(aux);
}
