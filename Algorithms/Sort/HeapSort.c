#include <stdio.h>
#include <stdlib.h>

int *array;
int len;

int less(int i, int j) {
    return array[i] < array[j];
}

void exch(int i, int j) {
    int item = array[i];
    array[i] = array[j];
    array[j] = item;
}

void sink(int k, int length) {
    while (2*k <= length) {
        int j = 2*k;
        // Choose the bigger path
        if (j < length && less(j, j+1)) { j++; }
        if (!less(k,j)) { break; }
        exch(j, k);
        k = j;
    }
}

void sort() {
    int N = len-1;
    for (int k = N/2; k>=1; k--) {
        sink(k, N);
    }

    while (N > 1) {
        exch(1, N--);
        sink(1, N);
    }
}

int main(int argc, char *argv[]) {
    len = argc;
    if (len < 3) {
        printf("Need at lease 2 args for sorting \n");
        return -1;
    }
    array = (int*) calloc(len, sizeof(int));
    for (int i = 1; i < len; i++) {
       array[i] = atoi(argv[i]);
    }
    sort();
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
