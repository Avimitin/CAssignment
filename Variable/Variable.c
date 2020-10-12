#include <stdio.h>

int x;
int y;
int i = 1;
int j = 3;
int addtwonum();

int addTwoNum() {
    // 这里的 extern 关键字会修改外部的 x 和 y
    extern int x;
    extern int y;
    x = 1;
    y = 2;
    return x + y;
}

int main() {
    printf("x=%d, y=%d\n", x, y);
    int result = addTwoNum();
    printf("x=%d, y=%d\n", x, y);
    printf("Result = %d\n", result);

    printf("i=%d, j=%d\n", i, j);
    result = addtwonum();
    printf("Result = %d\n", result);
    return 0;
}