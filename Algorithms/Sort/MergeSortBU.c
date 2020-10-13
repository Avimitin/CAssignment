#include <stdio.h>
#include <stdlib.h>

int *aux;
extern void MergeSortBU(int length, int *a);

void Merge(int a[], int lo, int mid, int hi) {
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

// main sort methods;
// Imagine a array that split to many child array. And finally merge them.
void sort(int length, int a[]) {
    // The outer loop is used to increase sort scope.
    for (int size = 1; size < length; size += size) {
        // The inner loop is actual sort loop.
        // Start from the begin of array, end at the last child array.
        // Each time increase double size to merge another child array.
        for (int lo = 0; lo < length-size; lo += size + size) {
            int Ahi = lo + size + size -1;
            int hi = Ahi > length-1 ? length-1 : Ahi;
            Merge(a, lo, lo+size-1, hi);
        }
    }
}

void Init(int length) {
    aux = calloc(length, sizeof(int));
    if (aux == NULL) {
        fprintf(stderr, "array init fail.");
        exit(-1);
    }
}

void MergeSortBU(int length, int *a) {
    Init(length);
    sort(length, a);
    free(aux);
}
