#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int less(int x, int y) {
    if (x < y) { return 1; } 
    else { return 0; }
}
void exch(int *x, int *y) {
    int current = *x;
    *x = *y;
    *y = current;
}

void sort(int *a, int len,int (*less)(int, int)) {
    int i = 0;
    for(int i = 0; i < len; i++) {
        for (int j = i; j>0 && less(*(a+j),*(a+j-1)); j--){
            exch(a+j, a+j-1);
        }
    }
}

int main() {
    int(* p)(int, int) = &max;
    int a = 3, b = 5, c= 2;
    int Max = p(p(a, b), c);
    printf("Max=%d\n",Max);

    int array[] = {3, 5, 4, 1, 6, 7, 8, 9, 2};
    printf("Sort before:");
    for (int i = 0; i < 9; i++) {
        printf("%d",*(array+i));
    }
    printf("\n");
    sort(array, 9, less);
    printf("Sort after:");
    for (int i = 0; i < 9; i++) {
        printf("%d", *(array+i));
    }
    printf("\n");
    return 0;
}
