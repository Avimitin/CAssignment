#include <stdio.h>

void changeNumber(int *num);
int * returnNum();

int main () {
    int var1;
    char var2[10];

    printf("var1's address: %p\n", &var1);
    printf("var2's address: %p\n", &var2);

    var1 = 20;
    int *p = &var1;

    printf("Address that p store: %p\n", p);
    printf("Value that p store: %d\n", *p);

    printf("var2 initing:\n");
    for (int i = 0; i < 10; i++) {
        var2[i] = i+1;
        printf("var2[%d]=%d\n",i, i+1);
    }

    char *cp = var2;
    for (int i = 0; i < 10; i++) {
        printf("var2[%d]=%d\n", i, *cp);
        *cp += 2;
        printf("Change var2[%d]=%d\n", i, *cp);
        printf("var2[%d]=%d\n\n", i, *cp);
        cp++;
    }

    int *ptr = &var1;
    int **pptr = &ptr;
    printf("ptr's address: %p, value: %d\n", ptr, *ptr);
    printf("pptr's address: %p, value: %p, value's value:%d\n", pptr, *pptr, **pptr);

    printf("Before: %d\n", var1);
    changeNumber(&var1);
    printf("After: %d\n", var1);

    int *numP = returnNum();
    *numP = 3;
    printf("nump:%p, val:%d\n", numP, *numP);
    numP += 3;
    printf("nump:%p, val:%d\n", numP, *numP);

    return 0;
}

void changeNumber(int *num) {
    *num = *num * *num;
}

int * returnNum() {
    static int i;
    return &i;
} 
