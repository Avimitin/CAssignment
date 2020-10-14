#include <stdio.h>

int *BinaryHeap;
int length;

// Compare two item in BinaryHeap.
// Return 1 if (Heap[i] < Heap[j]).
int less(int i, int j) {
    return *(BinaryHeap + i) < *(BinaryHeap + j);
}

// Exchange two item in BinaryHeap.
void exch(int i, int j) {
    int item = *(BinaryHeap + i);
    *(BinaryHeap + i) = *(BinaryHeap + j);
    *(BinaryHeap + j) = item;  
}

// k is the foot mark of the heap.
// It's father is k/2 (BU).
// It's child is 2k and 2k+1
void swim(int k) {
    // while heap[k] is bigger than it's father,
    // changing it to the top and continue compare it
    // to his new father.
    while (k > 1 && less(k/2, k)) {
        exch(k, k/2);
        k = k/2;
    }
}

// Sink element
void sink(int k) {
    while (2*k < length) {
        int j = 2 * k;
        if (j < length && less(j, j+1)) { j++; }
        if (!less(k, j)) { break; }
        exch(j, k);
        k = j;
    }
}

