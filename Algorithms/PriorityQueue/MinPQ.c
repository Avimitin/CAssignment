#include <stdio.h>
#include <stdlib.h>

int *BinaryHeap;
int count;

// Compare two item in BinaryHeap.
// Return 1 if (Heap[i] < Heap[j]).
int less(int i, int j) {
    return BinaryHeap[i] < BinaryHeap[j];
}

// Exchange two item in BinaryHeap.
void exch(int i, int j) {
    int item = BinaryHeap[i];
    BinaryHeap[i] = BinaryHeap[j];
    BinaryHeap[j] = item;
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

// Sink element to the bottom.
// k is father node and j(2*k\2*k+1) is child node.
void sink(int k) {
    // 2*k is k element's child.
    // Exchange element until the node reach the bottom.
    while (2*k < count) {
        int j = 2 * k;
        // Every node will have two child nodes at most
        // exchange the node to the bigger child node.
        if (j < count && less(j, j+1)) { j++; }
        // Check if the origin node is not less than all it's child node.
        if (!less(k, j)) { break; }
        exch(j, k);
        k = j;
    }
}

// insert item and swim it to bottom.
void insert(int item) {
    BinaryHeap[++count] = item;
    swim(count);
}

// Delete the biggest item in the heap.
int delMax() {
    int Max = BinaryHeap[1];
    // the 0 foot mark won't use.
    exch(1, count);
    BinaryHeap[count--] = 0;
    sink(1);
    return Max;
}

// Return the count of item in heap.
int size() {
    return count;
}

// Return true if the heap is empty.
int isEmpty() {
    return count == 0;
}

void init(int cap) {
    BinaryHeap = (int*)calloc(cap, sizeof(int));
    count = 0;
}

int main(int argc, char *argv[]) {
    int len = argc -1;
    init(6);
    int *a = (int*)calloc(len, sizeof(int));

    printf("Args you input: ");
    for (int i = 0; i < len; i++) {
        a[i] = atoi(argv[i+1]);
        printf("%d ", a[i]);
    }
    printf("\n");
    
    printf("Deleted bigger number: ");
    for (int i = 0; i < len; i++) {
        insert(a[i]);
        if (size() > 5) {
            printf("%d ", delMax());
        }
    }
    printf("\n");

    printf("Here are 5 nums which are the lowest in your input: ");
    for (int i=1; i <= size(); i++) {
        printf("%d ", BinaryHeap[i]);
    }
    printf("\n");
}