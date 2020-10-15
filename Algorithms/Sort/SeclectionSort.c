#include <stdio.h>

int Less(int *x, int *y);
void Exch(int *x, int *y);
extern void SeclectionSort(int length, int *array);

void SeclectionSort(int length, int *array) {
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
            if (Less(array + j, array + i)) {
                Exch(array + i, array + j);
            }
        }
    }
}
