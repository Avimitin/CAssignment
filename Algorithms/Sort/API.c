#include <stdio.h>

// Define Api;
extern void Exch(int *x, int *y);
extern int Less(int *x, int *y);
extern void Show(int len, int *a);
extern int IsSorted(int len, int *a);

// Exchange value of two pointer;
void Exch(int *x, int *y) {
    int item = *x;
    *x = *y;
    *y = item;
}

// Compare two value, return 1 if x < y;
int Less(int *x, int *y) {
    return *x < *y;
}

// Show all the number in array;
void Show(int len, int *a) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *(a+i));
    }
    printf("\n");
}

// Test if array is sorted or not;
int IsSorted(int len, int *a) {
    for (int i = 1; i < len; i++) {
        if (*(a+i) < *(a+i-1)) {
            return 0;
        }
    }
    return 1;
}