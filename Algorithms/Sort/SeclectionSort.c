#include <stdio.h>

int Less(int *x, int *y);
void Exch(int *x, int *y);
extern void SeclectionSort(int length, int *array);

void SeclectionSort(int length, int *array) {
    for (int i = 0; i < length; i++) {
        int *x = array+i;
        printf("left: %d\n", *x);
        for (int j = i+1; j < length; j++) {
            int *y = array+j;
            printf("%d ", *y);
            if (Less(y, x)) {
                Exch(x, y);
            }
        }
        printf("\n");
    }
}
